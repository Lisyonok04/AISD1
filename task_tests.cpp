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
    cout << endl;
}

TEST(clear, test) {
    Tree<int> set;
    set.inserter(41);
    set.inserter(90);
    set.inserter(20);
    set.print();
    set.eraser(41);
    set.print();
    cout << endl;
}

TEST(get_element, test) {
    Tree<int> set;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(4);
    Node<int>* res = new Node<int>(2, node1, node2);
    cout<<get_count_elements(res);
    cout << endl;
}

TEST(get_element2, test) {
    Tree<int> set;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node3 = new Node<int>(5);
    Node<int>* node4 = new Node<int>(10);
    Node<int>* node2 = new Node<int>(4, node3, node4);
    Node<int>* res = new Node<int>(2, node1, node2);
    cout << get_count_elements(res);
    cout << endl;
}

TEST(contain, test) {
    Tree<int> set;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node3 = new Node<int>(5);
    Node<int>* node4 = new Node<int>(10);
    Node<int>* node2 = new Node<int>(4, node3, node4);
    Node<int>* res = new Node<int>(2, node1, node2);
    Tree<int> a(res);
    if (a.contains(10)) {
        cout << "True" << endl;
    }
    else cout << "False" << endl;
    cout << endl;
}

TEST(contain2, test) {
    Tree<int> set;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node3 = new Node<int>(5);
    Node<int>* node4 = new Node<int>(10);
    Node<int>* node2 = new Node<int>(4, node3, node4);
    Node<int>* res = new Node<int>(2, node1, node2);
    Tree<int> a(res);
    if (a.contains(-4)) {
        cout << "True" << endl;
    }
    else cout << "False" << endl;
    cout << endl;
}

TEST(root, test) {
    Node<int>* node1 = new Node<int>(1);
    Tree<int> a(node1);
    a.inserter(2);
    a.inserter(4);
    cout << a.getroot()->_val;
    a.eraser(1);
    cout << a.getroot()->_val;
    a.eraser(2);
    cout << a.getroot()->_val;
    cout << endl;
}

TEST(Task, test) {
    vector<int> a{ 1, 1, 2, 2, 3, 3, 4, 5, 6, 6 };
    vector<int> result = unique(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

TEST(Task2, test) {
    vector<int> a{ 1, 1, 1, 2, 2, 1, 1, 3, 3, 4, 4, 5, 5, 6};
    vector<int> result = unique(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

TEST(Task3, test) {
    vector<int> a{ 1, 2, 3, 4, 5, 6 };
    vector<int> result = unique(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

TEST(Task4, test) {
    vector<int> a{ 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6 };
    vector<int> result = unique(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

//TEST(test_for_time, test) {
//    Tree<int> t1;
//    Tree<int> t2;
//    Tree<int> t3;
//    t1.filling(1000);
//    t2.filling(10000);
//    t3.filling(100000);
//    vector<int> v1(1000);
//    vector<int> v2(10000);
//    vector<int> v3(100000);
//    cout << "time for filling vector>>\n\t1000 = "
//        << get_time_filling_vector(1000) / 1000 << " ms\n\t10000 = "
//        << get_time_filling_vector(10000) / 1000 << " ms\n\t100000 = "
//        << get_time_filling_vector(100000) / 1000 << " ms" << endl;
//    cout << "time for contains vector>>\n\t1000 = "
//        << get_time_contains_vector(v1, 1000) / 1000 << " ms\n\t10000 = "
//        << get_time_contains_vector(v2, 10000) / 1000 << " ms\n\t100000 = "
//        << get_time_contains_vector(v3, 100000) / 1000 << " ms" << endl;
//    cout << "time for insert vector>>\n\t1000 = "
//        << get_time_insert_vector(v1, 1000) / 1000 << " ms\n\t10000 = "
//        << get_time_insert_vector(v2, 10000) / 1000 << " ms\n\t100000 = "
//        << get_time_insert_vector(v3, 100000) / 1000 << " ms" << endl;
//    cout << "time for erase vector>>\n\t1000 = "
//        << get_time_erase_vector(v1, 1000) / 1000 << " ms\n\t10000 = "
//        << get_time_erase_vector(v2, 10000) / 1000 << " ms\n\t100000 = "
//        << get_time_erase_vector(v3, 100000) / 1000 << " ms" << endl;
//
//    cout << "time for filling >>\n\t1000 = "
//        << get_time_filling(1000) / 1000 << " ms\n\t10000 = "
//        << get_time_filling(10000) / 1000 << " ms\n\t100000 = "
//        << get_time_filling(100000) / 1000 << " ms" << endl;
//    cout << "time for contains >>\n\t1000 = "
//        << get_time_contains(t1, 1000) / 1000 << " ms\n\t10000 = "
//        << get_time_contains(t2, 10000) / 1000 << " ms\n\t100000 = "
//        << get_time_contains(t3, 100000) / 1000 << " ms" << endl;
//    cout << "time for insert >>\n\t1000 = "
//        << get_time_insert(t1, 1000) / 1000 << " ms\n\t10000 = "
//        << get_time_insert(t2, 10000) / 1000 << " ms\n\t100000 = "
//        << get_time_insert(t3, 100000) / 1000 << " ms" << endl;
//    cout << "time for erase >>\n\t1000 = "
//        << get_time_erase(t1, 1000) / 1000 << " ms\n\t10000 = "
//        << get_time_erase(t2, 10000) / 1000 << " ms\n\t100000 = "
//        << get_time_erase(t3, 100000) / 1000 << " ms" << endl;
//}
