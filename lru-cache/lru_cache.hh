#include <iostream>
#include <list>
#include <map>

#ifndef _LRU_CACHE_
#define _LRU_CACHE_
using namespace std;
class lru_cache {
        private:
                struct node {
                        int key;
                        int value;
                        node(int _key, int _value):key(_key), value(_value){}
                };
                typedef map<int, list<struct node*>::iterator> index;
                typedef list<struct node*> queue ;
                typedef pair<int, list<node*>::iterator> index_item;
                queue m_queue;
                index m_index;
                int m_capacity;
        public:
                lru_cache(int size):m_capacity(size){}
                ~lru_cache();
                int get(int key);
                int set(int key, int value);
                void print_cache();
                void print_queue();
                void reset();
};
#endif
