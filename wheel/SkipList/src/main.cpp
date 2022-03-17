#include "SkipList.hpp"
#include <cstddef>
#include <iostream>

int main() {
    int maxLevel = 6;
    SkipList<int> s_list(maxLevel, 0);
    for (size_t i = 0; i < 50; ++i)
    {
        s_list.insert(i, i);
    }
    s_list.deleteNode(70);
    s_list.deleteNode(20);

    s_list.printSkList();
}
