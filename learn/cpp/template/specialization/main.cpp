#include <iostream>

template <typename U, typename T>
struct Add {
    U a;
    T b;
    Add(U a, T b): a(a), b(b){}
    void print() {
        std::cout << "else" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
};

template <typename U>
struct Add<U, int> {
    U a;
    int b;
    Add(U a, int b): a(a), b(b){}
    void print() {
        std::cout << "int \n";
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
};

template <typename U>
struct Add<U, float> {
    U a;
    float b;
    Add(U a, float b): a(a), b(b){}
    void print() {
        std::cout << "float \n";
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
};

int main() {
    Add<int, int> a1(1, 3);
    a1.print();

    Add<int, float> a2(1, 3.0);
    a2.print();

    Add<int, double> a3(1, 3.0);
    a3.print();
}