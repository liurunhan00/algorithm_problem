#include <type_traits>
#include <iostream>

// #define REQUIRE(x)  std::enable_if_t<std::is_same<std::decay_t<T>, x>::value, int> = 1
// 
// template <typename T, REQUIRE(int)>
// T func(const T &t) {
//     return 1;
// }
// 
// template <typename T,  REQUIRE(float)>
// T func(T t) {
//     return 2;
// }

template <typename T>
T func(T t) {
    using x = std::decay_t<decltype(t)>;
    x x_ = t;
    if (std::is_same<x ,double>::value)
        std::cout << "double\n";
    if (std::is_same<x ,int>::value)
        std::cout << "int\n";
    return x_;
}

// template <>
// double func<double>(double t) {
//     return 3;
// }
// main.cpp:15:8: error: template-id ‘func<double>’ for ‘double func(double)’ does not match any template declaration
//    15 | double func<double>(double t) {



int main() {
    std::cout << func<float>(1.9) << std::endl;
    std::cout << func<const int>(1.9) << std::endl;  // std::decay_t
    std::cout << func<double>(1.9) << std::endl;  // std::decay_t
}