#pragma once
#include <iostream>
#include <memory>
#include <vector>
template <typename T>
struct SkipNode
{
    int key;    // index
    T   value;  
    // cur Node's next Node
    std::vector<std::shared_ptr<SkipNode>> next;
    // level is randomly generated
    SkipNode(int key, T value, int level);
    ~SkipNode() 
    {
        std::cout << "delete Node: " << key << std::endl;
    }

};

// initalization
template <typename T>
SkipNode<T>::SkipNode(int key, T value, int level)
            :key(key), value(value) 
{
    for (int i = 0; i < level; ++i) 
    {
        next.emplace_back(nullptr);
    }
}


