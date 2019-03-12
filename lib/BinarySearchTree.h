#pragma once

template<typename T>
class BinarySearchTree {
private:
	class Node {
	public:
		Node(T key, Node *left = nullptr, Node *right = nullptr) : left(left), right(right), key(key) {}
		
		T key;
		Node *left{nullptr}, *right{nullptr};
	};
	
	Node *insert(Node *node, T key) {
		if (node == nullptr)
			node = new Node(key);
		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		return node;
	}
	
	Node *root{new Node()};
public:
	BinarySearchTree(T key) : root(new Node(key)) {}
	
	Node *insert(T key) {
		return insert(root, key);
	}
	
};