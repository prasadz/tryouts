#include <iostream>

using namespace std;
#ifndef _LINKED_LIST_
#define _LINKED_LIST_
class list {
        private:
                struct node {
                        int data;
                        node* next;
                        node(int _data):data(_data), next(nullptr){}
                };
                node* m_root;
                node* m_last;
        public:
                list() : m_root(nullptr), m_last(nullptr) {}
                void push_back(int data);
                void push_front(int data);
                void pop_back();
                void pop_front();
                void revert();
                void print();
};
#endif
