#include <iostream>
#include <map>
#include <vector>

using namespace std;

#ifndef _LOOKUP_TABLE_
#define _LOOKUP_TABLE_
class lookup_table {
        private:
                struct node {
                        int key;
                        int value;        
                        node(int _key, int _value):key(_key), value(_value) {}
                };
                typedef map<int,int> index;
                typedef vector<node*> table;
                typedef pair<int, int> index_node;
                index m_index;
                table m_table;
        public:
                lookup_table() {}
                int set(int key, int value);
                int get(int key);
                int get_random();
                int delete_node(int key);
                void print_index();
                void print_table();
};
#endif
