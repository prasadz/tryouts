#include "linked_list.hh"

void list::push_back(int data) {
        if (m_root == nullptr) {
                m_root = new node(data);
                m_last = m_root;
                return;
        }
        m_last->next = new node(data);
        m_last = m_last->next; 
}

void list::push_front(int data) {
        if (m_root == nullptr) {
                m_root = new node(data);
                m_last = m_root;
                return;
        }
        node* new_node = new node(data);
        new_node->next = m_root;
        m_root = new_node;
}

void list::print() {
        node* it = m_root;
        while (it != nullptr) {
                cout << it->data << endl;
                it = it->next;
        }
}

void list::pop_back() {
        if (m_root == nullptr) {
                return;
        }
        if (m_root == m_last) {
                delete m_root;
                m_root = nullptr;
                m_last = nullptr;
                return;
        }

        node* current_node = m_root;
        while (current_node->next != m_last) {
                current_node = current_node->next;
        }
        delete m_last;
        m_last = current_node;
        m_last->next = nullptr;
}

void list::pop_front() {
        if (m_root == nullptr) {
                return;
        }
        if (m_root == m_last) {
                delete m_root;
                m_root = nullptr;
                m_last = nullptr;
                return;
        }
        node* current_node = m_root;
        m_root = current_node->next;
        delete current_node;
}

void list::revert() {
        if (m_root == nullptr || m_root == m_last) {
                return;
        }
        node* current_node = m_root;
        node*  prev_node = nullptr;
        node* next_node = nullptr;
        m_last = m_root;
        while (current_node != nullptr) {
                next_node = current_node->next;
                current_node->next = prev_node;
                prev_node = current_node;
                current_node = next_node;
        }
        m_root = prev_node;
}
