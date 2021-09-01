#include "lookup_table.hh"
int lookup_table::set(int key, int value) {
        auto index_it = m_index.find(key);
        if (index_it != m_index.end()) {
                node* req_node = m_table.at(key);
                if (req_node->value == value) {
                        return 1;
                }
                req_node->value = value;
                return 2;
        }
        m_table.push_back(new node(key, value));
        size_t lookup_index = m_table.size() - 1;
        m_index.insert(index_node(key, lookup_index)); 
        return 0;
}

int lookup_table::get(int key) {
        auto index_it = m_index.find(key);
        if (index_it == m_index.end()) {
                return -1;
        }
        node* req_node = m_table[index_it->second];
        req_node->value;
}

int lookup_table::delete_node(int key) {
        auto index_it = m_index.find(key);
        if (index_it == m_index.end()) {
                return -1;
        } 

        int current_index = index_it->second;
        int last_index = m_table.size() - 1;
        int key_of_last_index = m_table[last_index]->key;

        delete m_table[current_index];
        m_table[current_index] = m_table[last_index];
        m_index[key_of_last_index] = current_index;
        m_index.erase(key);
        m_table.pop_back();
        return 0;
}

void lookup_table::print_index() {
        int count = 0;
        for (auto it = m_index.begin(); it != m_index.end(); ++it) {
                cout << it->first << " " 
                        << it->second << " "
                        << m_table[it->second]->key << " "
                        << m_table[it->second]->value << endl;             
        }
}

void lookup_table::print_table() {
        for (auto it = m_table.begin(); it != m_table.end(); it++) {
               cout << (*it)->key << " " << (*it)->value << endl; 
        }
}
