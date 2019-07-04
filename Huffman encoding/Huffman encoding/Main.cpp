#include "tree.h"
#include "huffman.h"
#include "iostream"

using namespace std;
// an andvanced algorithm wich encodes strings into 0 and 1 with a min heap to store them in
void main() {
	string stringu = "aaaabbbcc";
	Huffman huffman;
	unordered_map<char, int> encodable = huffman.countChars(stringu);
	Tree *tree = huffman.encode(encodable);

	unordered_map<char, std::string> charMap;

	tree->printTree(charMap);

	for (list<pair<const char, string>>::iterator iterator = charMap.begin(); iterator != charMap.end(); iterator++) {
		cout << iterator->second << ": " << iterator->first << endl;
	}
}
