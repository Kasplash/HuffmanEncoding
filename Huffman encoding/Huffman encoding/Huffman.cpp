#include "Huffman.h"
#include <queue>

using namespace std;


vector<pair<char, char>> charPairVector;

Huffman::Huffman() {

}

Huffman::~Huffman() {

}
// count the chars of the unencoded string
unordered_map<char, int> Huffman::countChars(string &unEncoded) {
	unordered_map<char, int> resultMap;
	char tempChar;

	for (unsigned i = 0; i < unEncoded.length(); i++) {
		tempChar = unEncoded.at(i);

		resultMap[tempChar] = resultMap[tempChar] + 1;
	}

	return resultMap;
}
// encode the string in a hufffman tree
Tree *Huffman::encode(unordered_map<char, int> &encodables) {
	priority_queue<TreeWrapper> priorQueue;

	for (list<pair<const char, int>>::iterator iterator = encodables.begin(); iterator != encodables.end(); iterator++) {
		Tree *leaf = new Tree(iterator->second, iterator->first); //Avreferera
		priorQueue.push(leaf);
	}

	while (priorQueue.size() > 1) {
		TreeWrapper tree1 = priorQueue.top();
		priorQueue.pop();
		TreeWrapper tree2 = priorQueue.top();
		priorQueue.pop();

		Tree *tree = new Tree(tree1.tree->getWeight() + tree2.tree->getWeight(), tree1.tree, tree2.tree);
		priorQueue.push(tree);
	}

	TreeWrapper finalTree = priorQueue.top();
	return finalTree.tree;

}

