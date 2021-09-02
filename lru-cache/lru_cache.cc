#include "lru_cache.hh"

lru_cache::~lru_cache() {
        reset();
}

int lru_cache::set(int key, int value) {
        auto index_it = m_index.find(key);
        if (index_it != m_index.end()) {
                node* n = *(index_it->second);
                int retval = 1;
                if (n->value != value) {
                        n->value = value;
                        retval = 2;
                }
                get(key);
                return retval;
        }
        if (m_index.size()  == m_capacity) {
                auto rit = m_queue.rbegin();
                m_index.erase((*rit)->key);
                delete (*rit);
        } 
        node* new_node = new node(key,value); 
        m_queue.push_front(new_node);
        m_index.insert(index_item(key, m_queue.begin()));
        return 0;
}

int lru_cache::get(int key) {
        auto index_it = m_index.find(key);
        if (index_it == m_index.end()) {
                return -1;
        }
        auto it = index_it->second;
        node* req_node = *it;
        m_queue.erase(it);
        m_queue.push_front(req_node);
        m_index.insert(index_item(key, m_queue.begin()));
        return req_node->value;
}

void lru_cache::print_cache() {
        cout << "cache: " << endl;
        for (auto it = m_index.begin(); it != m_index.end(); it++) {
                node* n = *(it->second);
                cout << it->first << " " << n->key << " "
                        << n->value << endl;
        }
}

void lru_cache::print_queue() {
        cout << "queue: " << endl;
        for (auto i = m_queue.begin(); i != m_queue.end(); i++) {
               node* n = *i;
               cout << n->key << " " << n->value << endl; 
        }
}

void lru_cache::reset() {
        for (auto it = m_index.begin(); it != m_index.end(); it++) {
               delete *(it->second);
               m_index.erase(it);
        }
}
