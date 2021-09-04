#include <iostream>

class binary_tree {
	private:
		struct node {
			int m_data;
			struct node* m_left;
			struct node* m_right;
			node(int data) : m_data(data), m_left(nullptr), m_right(nullptr) {}
		};
		node* m_root;
		void inorder(node* current_node);
		void postorder(node* current_node);
		void preorder(node* current_node);
		int  depth(node* current_node);
        void print_k_distance(node* current_node, int k);
        void level_order_traversal(node* current_node);
        void print_level_by_level(node* current_node);
        void print_level_by_level_2(node* current_node);
        void print_spiral(node* current_node);
        int  size(node* current_node);
        int max_node(node* current_node);
        bool bst(ode* current_node);
	public:
		binary_tree() : m_root(nullptr) {}
		void insert(int data);
		bool empty() { return m_root == nullptr; }
		void inorder();
		void postorder();
		void preorder();
		void non_recursive_inorder();
        void non_recursive_preorder();
        void non_recursive_postorder();
        int depth();
        void print_k_distance(int k);
        void level_order_traversal();
        void print_level_by_level();
        void print_spiral();
        int  size();
        int max_node();
        bool bst();
};
