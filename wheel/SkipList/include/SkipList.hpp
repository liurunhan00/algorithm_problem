#pragma once
#include <iostream>
#include <time.h>
#include "SkipNode.hpp"
#include <random>
#include <limits>
#include <memory>
template <typename T>
class SkipList
{
public:
    // head
    std::shared_ptr<SkipNode<T>> head;

    // SkipList's maxlevel
    int maxLevel;

    // INT_MAX && INT_MIN
    const int minInt = std::numeric_limits<int>::min();
    const int maxInt = std::numeric_limits<int>::max();

public:
    SkipList(int maxLevel, T iniValue);
     ~SkipList();

    // random level
    int randomLevel();

    // insert find delete
    std::shared_ptr<SkipNode<T>> insert(int key, T value);
    std::shared_ptr<SkipNode<T>> find(int key);
    std::shared_ptr<SkipNode<T>> deleteNode(int key);

    // print
    void printSkList();

  private:
    std::shared_ptr<SkipNode<T>> tail;
    
    // cur List's maxLevel
    int nodeLevel(std::vector<std::shared_ptr<SkipNode<T>>> p);
};

template <typename T>
SkipList<T>::SkipList(int maxLevel, T iniValue)
            : maxLevel(maxLevel)
{
    // init head && tail with minV && maxV
    head = std::make_shared<SkipNode<T>>(minInt, iniValue, maxLevel);
    tail = std::make_shared<SkipNode<T>>(maxInt, iniValue, maxLevel);
    
    // head->tail all level
    for (int i = 0; i < maxLevel; ++i)
    {
        head->next[i] = tail;
    }
}

template <typename T>
SkipList<T>::~SkipList() 
{}


// random level
template <typename T>
int SkipList<T>::randomLevel()
{
    int random_level = 1;
    int seed = time(nullptr);
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<int> dis(0, 1);

    while (dis(e) && random_level < maxLevel)
    {
        random_level++;
    }
    return random_level;
}

template <typename T>
int SkipList<T>::nodeLevel(std::vector<std::shared_ptr<SkipNode<T>>> p)
{
    int node_level = 0;
    if (p[0]->key == maxInt)
    {
        return node_level;
    } 

    for (int i = 0; i < p.size(); ++i) 
    {
        if (p[i] && p[i]->key != maxInt)
        {
            node_level++;
        }
        else 
        {
            break;
        }
    }
    return node_level;
}

/* insert
 * first find, if exist, renew it
 * get new node's random_level
 * insert and adjust
 */
template <typename T>
std::shared_ptr<SkipNode<T>> SkipList<T>::insert(int key, T value)
{
    int x_level = randomLevel();
    auto tmp = head;
    auto new_node = find(key);
    if (new_node) {
        new_node->value = value;
        std::cout << "\nThis node " << key << "has already exist. And its value been updated to " << value << std::endl;
        return head;
    }
    std::cout << "key: " << key << ", randomLevel: " << x_level << std::endl;

    new_node = std::make_shared<SkipNode<T>>(key, value, maxLevel);
    
    // find place to insert
    // update the previous and the later one
    for (int i = x_level - 1; i >= 0; --i)
    {
        while (tmp->next[i] && tmp->next[i]->key < key) 
        {
            tmp = tmp->next[i];
        }
        // insert place
        new_node->next[i] = tmp->next[i];
        tmp->next[i] = new_node;
    }
    return head;
}
/*
 * find
 * Since the list is ordered
 * first find the closest node that is less than this node
 * return that node is equal the node
 * else return nullptr
 */
template <typename T>
std::shared_ptr<SkipNode<T>> SkipList<T>::find(int key)
{
    auto tmp = head;
    // get cur_max_level
    int cur_level = nodeLevel(tmp->next);

    for (int i = cur_level - 1; i >= 0; --i) 
    {
        while (tmp->next[i] && tmp->next[i]->key < key)
        {
            tmp = tmp->next[i];
        }
    }
    tmp = tmp->next[0];
    if (key == tmp->key) {
        std::cout << "\n This key：" << key << " has been found\n";
    } else {
        return nullptr;
    }
    return tmp;
}

// deleteNode
// find it, if not exist return 
// find the previous node 
// exchange its relationships
template <typename T>
std::shared_ptr<SkipNode<T>> SkipList<T>::deleteNode(int key)
{
    auto node = find(key);
    if (!node) {
        std::cout << "node key = " << key << " not exist\n";
        return head;
    }
    auto tmp = head;
    int x_level = node->next.size();

    std::cout << "\nthe deleting node " << key << "'s level is " << x_level << std::endl;

    for (int i = (x_level - 1); i >= 0; --i) 
    {
        while (tmp->next[i] && tmp->next[i]->key < key)
        {
            tmp = tmp->next[i];
        }
        tmp->next[i] = tmp->next[i]->next[i];
        std::cout << "this node " << key << "has been deleted from level " << i << std::endl;
    }
    return head;
}

template <typename T> 
void SkipList<T>::printSkList() 
{
    for (int i = 0; i < maxLevel; ++i) 
    {
        auto tmp = head;
        int Linelen = 1;

        if (tmp->next[i]->key != maxInt)
        {
            std::cout << "\nthis is level "<< i << ":" << std::endl;
            std::cout << "{";

            while (tmp->next[i] && tmp->next[i]->key != maxInt)
            {
                std::cout << "(" << "Key: " << tmp->next[i]->key << ",";
                std::cout << "Value: " << tmp->next[i]->value << ")";

                tmp = tmp->next[i];

                if (tmp->next[i] && tmp->next[i]->key != maxInt)
                {
                    std::cout << ", ";
                }

                if (Linelen++ % 5 == 0) std::cout << '\n';
            }
            std::cout << "}";
        }
    }
    std::cout << "\n" ;
}
