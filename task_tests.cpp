#include "task.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

TEST(test_SET, test) {
    Tree<int> set;
    set.insert(41);
    set.insert(90);
    set.insert(20);
    set.print();
}