#include "tree.h"

Tree::Tree(int weight, char letter) {
	this->letter = letter;
	this->weight = weight;
	this->left = NULL;
	this->right = NULL;
}

Tree::Tree(int weight, Tree* t1, Tree* t2) {
	this->letter = NULL;
	this->weight = weight;
	this->left = t1;
	this->right = t2;
}

Tree::~Tree() {

}

int Tree::getWeight() const {
	return this->weight;
}

void Tree::traverseTree(std::unordered_map<char, std::string> &bitString, const std::string &path, const Tree* tree) const {
	if (tree->left && tree->right) {
		tree->left->traverseTree(bitString, path + "1", tree->left);
		tree->right->traverseTree(bitString, path + "0", tree->right);
	}
	else {
		/*for (char t : path) {
			bitString.push_back(t);
		}
		bitString.push_back(this->letter);*/
		bitString[this->letter] = path;
	}
}

void Tree::printTree(std::unordered_map<char, std::string> &bitString) const {
	traverseTree(bitString, "", this);
}

