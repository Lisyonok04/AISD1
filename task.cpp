#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node {
	int _val;
	Node<T>* _left;
	Node<T>* _right;

	Node(int val) :_val(val), _left(nullptr), _right(nullptr) {};
	Node(int val, Node<T>* left, Node<T>* right) :_val(val), _left(left), _right(right) {};
};

