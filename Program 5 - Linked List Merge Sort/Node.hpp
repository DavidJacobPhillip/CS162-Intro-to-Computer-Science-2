#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// not seperated into interface/implementation due to template class usage
template <class T>
class Node{
    public:
    T value;
    Node<T> *next;
};

#endif
