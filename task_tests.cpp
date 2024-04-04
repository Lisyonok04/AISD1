#include "task.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

TEST(insert, test) {
    Tree<int> set;
    set.inserter(41);
    set.inserter(90);
    set.inserter(20);
    set.print();
}

TEST(clear, test) {
    Tree<int> set;
    set.inserter(41);
    set.inserter(90);
    set.inserter(20);
    set.print();
    set.eraser(41);
    set.print();
}

TEST(get_element, test) {
    Tree<int> set;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(4);
    Node<int>* res = new Node<int>(2, node1, node2);
    cout<<get_elements(res);
}

TEST(get_element2, test) {
    Tree<int> set;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node3 = new Node<int>(5);
    Node<int>* node4 = new Node<int>(10);
    Node<int>* node2 = new Node<int>(4, node3, node4);
    Node<int>* res = new Node<int>(2, node1, node2);
    cout << get_elements(res);
}