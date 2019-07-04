#pragma once
#include <vector>
#include <unordered_map>

class Tree {
public:
	Tree(int weight, char letter);
	Tree(int weight, Tree* t1, Tree* t2);
	~Tree();
	int getWeight() const;
	void printTree(std::unordered_map<char, std::string> &bitString) const;
	void traverseTree(std::unordered_map<char, std::string> &bitString, const std::string &path, const Tree* tree) const;
private:
	Tree* left;
	Tree* right;
	int weight;
	char letter;
};

