#include "binary_tree.hh"
#include <stack>
#include <queue>
#include <bits/stdc++.h>

void binary_tree::insert(int data) {
	node* new_node = new node(data);

	// require pointer to pointer to update
	// value of pointer pointed by parent.
	node** parent = &m_root;
	while (*parent != nullptr) {
		if (data >= (*parent)->m_data) {
			parent = &((*parent)->m_right);
		} else {
			parent = &((*parent)->m_left);
		}
	}
	*parent = new_node;	
	return;
}

void binary_tree::inorder() {
	inorder(m_root);
	return;
}

void binary_tree::postorder() {
	postorder(m_root);
	return;
}

void binary_tree::preorder() {
	preorder(m_root);
	return;
}

void binary_tree::inorder(node* current_node) {
	if (current_node == nullptr) return;
	inorder(current_node->m_left);
	std::cout << current_node->m_data << std::endl;
	inorder(current_node->m_right);
}

void binary_tree::postorder(node* current_node) {
	if (current_node == nullptr) return;
	postorder(current_node->m_left);
	postorder(current_node->m_right);
	std::cout << current_node->m_data << std::endl;
}

void binary_tree::preorder(node* current_node) {
	if (current_node == nullptr) return;
	std::cout << current_node->m_data << std::endl;
	preorder(current_node->m_left);
	preorder(current_node->m_right);
}

void binary_tree::non_recursive_inorder() {
	std::stack<node*> s;
	node* current_node = m_root;
	while (current_node != nullptr || s.empty() == false) {
		while (current_node != nullptr) {
			s.push(current_node);
			current_node = current_node->m_left;
		}	
		current_node = s.top();
		s.pop();

		std::cout << current_node->m_data << std::endl;

		current_node = current_node->m_right;
	}
}

void binary_tree::non_recursive_preorder() {
    std::stack<node*> s;
    node* current_node = m_root;
    s.push(current_node);
    while (s.empty() == false) {
        current_node = s.top();
        std::cout << current_node->m_data << std::endl;
        s.pop();

        if (current_node->m_right != nullptr) {
            s.push(current_node->m_right);
        }
        if (current_node->m_left != nullptr) {
            s.push(current_node->m_left);
        }
    }
}

void binary_tree::non_recursive_postorder() {
    std::stack<node*> s;
	std::stack<int> d;
	node* current_node = m_root;
    s.push(current_node);
    while (s.empty() == false) {
        current_node = s.top();
        d.push(current_node->m_data);
        s.pop();

        if (current_node->m_left != nullptr) {
            s.push(current_node->m_left);
        }
        if (current_node->m_right != nullptr) {
            s.push(current_node->m_right);
        }
    }

    while (d.empty() == false) {
        std::cout << d.top() << std::endl;
        d.pop();
    }
}

int binary_tree::depth() {
    return depth(m_root);
}

int binary_tree::depth(node* current_node) {
    if (current_node == nullptr) return 0;
    int l = depth(current_node->m_left) + 1;
    int r = depth(current_node->m_right) + 1;
    if (l >= r) return l;
    return r;
}

void binary_tree::print_k_distance(int k) {
    print_k_distance(m_root, k);
}

void binary_tree::print_k_distance(node* current_node, int k) {
    if (current_node  == nullptr) return;

    print_k_distance(current_node->m_left, k-1);
    print_k_distance(current_node->m_right, k-1);
    if (k == 0) {
        std::cout << current_node->m_data << std::endl;
        return;
    }
}

void binary_tree::level_order_traversal() {
    level_order_traversal(m_root);    
}

void binary_tree::level_order_traversal(node* current_node) {
    std::queue<node*> q;
    q.push(current_node);
    while (q.empty() == false) {
        current_node = q.front();
        q.pop();
        std::cout << current_node->m_data << std::endl;
        if (current_node->m_left != nullptr) {
            q.push(current_node->m_left); 
        }
        if (current_node->m_right != nullptr) {
            q.push(current_node->m_right); 
        }
    }
}

void binary_tree::print_level_by_level() {
    print_level_by_level_2(m_root);
}

void binary_tree::print_level_by_level(node* current_node) {
    std::queue<node*> q;
    q.push(current_node);
    q.push(nullptr);
    while (q.size() > 1) {
        current_node = q.front();
        q.pop();
        if (current_node == nullptr) {
            std::cout << std::endl;
            q.push(nullptr);
            continue;
        }
        std::cout << current_node->m_data << " ";
        if (current_node->m_left != nullptr) {
            q.push(current_node->m_left); 
        }
        if (current_node->m_right != nullptr) {
            q.push(current_node->m_right); 
        }
    }
    std::cout << std::endl;
}

void binary_tree::print_level_by_level_2(node* current_node) {
    std::queue<node*> q;
    q.push(current_node);
    while (q.size() > 0) {
        int count = q.size();
        for (int i = 0; i < count; i++) {
            current_node = q.front();
            std::cout << current_node->m_data << " ";
            q.pop();
            if (current_node->m_left != nullptr) {
                q.push(current_node->m_left);
            }
            if (current_node->m_right != nullptr) {
                q.push(current_node->m_right);
            }
        }
        std::cout << std::endl;
    }
}

int binary_tree::size() {
    return size(m_root);
}

int binary_tree::size(node* current_node) {
    if (current_node == nullptr) {
        return 0;
    }

    return 1 + size(current_node->m_left) +
            size(current_node->m_right);
}

int binary_tree::max_node() {
    return max_node(m_root);
}

int binary_tree::max_node(node* current_node) {
    if (current_node == nullptr) {
        return 0;
    }
    return std::max(current_node->m_data, std::max(max_node(current_node->m_left), max_node(current_node->m_right)));
}

bool binary_tree::bst() {
    return bst(m_root);
}

bool binary_tree::bst(node* current_node) {

}
