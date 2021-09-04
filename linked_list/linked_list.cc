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

bool list::insert(size_t position, int data) {
        if (position == 0 ) {
                return false;
        }
        if (position == 1) {
                push_front(data); 
                return true;
        }
        node* current_node = m_root;
        for (int i = 1; i< position - 1 && current_node->next != nullptr 
                        ; i++) {
                current_node = current_node->next;
        }
        
        node* new_node = new node(data);
        new_node->next = current_node->next;
        current_node->next = new_node;
        if (current_node == m_last) {
                m_last = new_node;
        }
        return true;
}
