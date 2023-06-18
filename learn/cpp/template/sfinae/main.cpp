#include <type_traits>
#include <iostream>

#define REQUIRE(x)  std::enable_if_t<(x), int> = 1


template <typename T, REQUIRE((std::is_same<T, int>::value))>
T func(T t) {
    return 1;
}

template <typename T, REQUIRE((std::is_same<T, float>::value))>
T func(T t) {
    return 2;
}


// template <>
// double func<double>(double t) {
//     return 3;
// }
// main.cpp:15:8: error: template-id ‘func<double>’ for ‘double func(double)’ does not match any template declaration
//    15 | double func<double>(double t) {

// --------------- func invoke --------------

// std::invoke_result cpp:17
// template <typename F, std::enable_if_t<std::is_void<std::invoke_result_t<F>>::value, int> = 1>

// std::declval<F>() -> construct F&&
// std::declval<F>()() -> call F()
template <typename F, REQUIRE((std::is_void<decltype(std::declval<F>()())>::value))>
auto invoke(F f) {
    std::cout << "void f no ret \n";
}

template <typename F, REQUIRE((!std::is_void<decltype(std::declval<F>()())>::value))>
auto invoke(F f) {
    return f();
}

// --------------- class -----------------
struct A {
    int DO() {
        std::cout << "A do\n";
        return 0;
    }
};

struct B {
    int DO() {
        std::cout << "B do\n";
        return 0;
    }
};

struct C {
    void NO_DO() {
        std::cout << "C not do\n";
    }

};

template<typename T, typename Dummy = void>
struct DO: std::false_type {
};

// In cpp17: std::void_t<decltype(std::declval<T>().DO())
// SFINAE only care if this expression is true that could pass the compiler
template<typename T>
struct DO<T, decltype(std::declval<T>().DO(), void())> : std::true_type {
};

template <typename T, REQUIRE(DO<T>::value)>
void real_do(T t) {
    t.DO();
}

template <typename T, REQUIRE(!DO<T>::value)>
void real_do(T t) {
    t.NO_DO();
}

int main() {
    std::cout << func<float>(1.9) << std::endl;
    std::cout << func<int>(1.9) << std::endl;

    std::cout << invoke([]()-> int {return 1;}) << std::endl;
    invoke([]()-> void {});

    A a;
    B b;
    C c;
    real_do<A>(a);
    real_do<B>(b);
    real_do<C>(c);
}
