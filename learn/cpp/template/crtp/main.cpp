// https://en.cppreference.com/w/cpp/language/crtp
#include <iostream>

template <typename Derived>
struct Base {
    void echo_name() {
        static_cast<Derived*>(this)->impl();  // make sure the class you derived have this method!
    }
};

struct D1: Base<D1> {
    void impl() {
        std::cout << "Name: D1" << std::endl;
    }
};

struct D2: Base<D2> {
    void impl() {
        std::cout << "Name: D2" << std::endl;
    }
};

// struct D3: Base<D3> {
//     void IMPL() {
//         std::cout << "Name: D2" << std::endl;
//     }
// };

int main() {
    D1 d1;
    D2 d2;
    d1.echo_name();
    d2.echo_name();

    // crtp.cpp: In instantiation of ‘void Base<Derived>::echo_name() [with Derived = D3]’:
    // crtp.cpp:35:17:   required from here
    // crtp.cpp:7:38: error: ‘struct D3’ has no member named ‘impl’
    //     7 |         static_cast<Derived*>(this)->impl();  // make sure the class you derived have this method!
    //       |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~
    // make: *** [Makefile:2: all] Error 1
    // D3 d3;
    // d3.echo_name();
}
