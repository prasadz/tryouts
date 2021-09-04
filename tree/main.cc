#include "binary_tree.hh"
int main() {
	binary_tree tree;
	//                   50
	//        25                     75 
	//   15       35          65            85
	tree.insert(50);
	tree.insert(25);
	tree.insert(75);
	tree.insert(15);
	tree.insert(35);
	tree.insert(65);
	tree.insert(85);

	std::cout << "Inorder Traversal" << std::endl;
	tree.inorder();

	std::cout << "Postorder Traversal" << std::endl;
	tree.postorder();

	std::cout << "Preorder Traversal" << std::endl;
	tree.preorder();

	std::cout << "Non-recursive Inorder Traversal" << std::endl;
	tree.non_recursive_inorder();

	std::cout << "Non-recursive Preorder Traversal" << std::endl;
	tree.non_recursive_preorder();

	std::cout << "Non-recursive Postorder Traversal" << std::endl;
    tree.non_recursive_postorder();

    std::cout << "Depth of tree: " << tree.depth() << std::endl;

    std::cout << "nodes at kth distance (k=2): " << std::endl;
    tree.print_k_distance(2);

    std::cout << "Level order traversal" << std::endl;
    tree.level_order_traversal();

    std::cout << "Print level by level" << std::endl;
    tree.print_level_by_level();

    std::cout << "Size of tree: " << tree.size() << std::endl;

    std::cout << "Max of tree: " << tree.max_node() << std::endl;

	return 0;
}
