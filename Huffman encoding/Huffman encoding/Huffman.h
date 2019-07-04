#pragma once
#include <string>
#include <unordered_map>
#include "Tree.h"

class Huffman {
public:
	Huffman();
	~Huffman();
	std::unordered_map<char, int> countChars(std::string &unEncoded);
	Tree *encode(std::unordered_map<char, int> &encodables);

	struct TreeWrapper {
		TreeWrapper() {
			tree = NULL;
		}
		TreeWrapper(Tree* t) {
			tree = t;
		}
		bool operator<(const TreeWrapper &tw) const {
			return tree->getWeight() > tw.tree->getWeight();
		}
	public:
		Tree* tree;
	};
};

