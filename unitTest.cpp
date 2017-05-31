#define CATCH_CONFIG_MAIN //So that catch will define a main method
#include "catch.hpp"
#include "HuffmanTree"
#include <vector>
#include <iostream>

TEST_CASE("Create Map", "This will test the createMap function in the HuffmanTree class"){
	MNTDOM001::HuffmanTree tree;
	char array[5] = {'a', 'a', '%', 'z', '\n'};
	std::unordered_map<char,int> map = tree.createMap(array,5);

	//Test the size of the map
	REQUIRE(map.size() == 4); //size is 4 since if there is a duplicate it increments the frequency

	//Test for letter a with frequency 2
	std::unordered_map<char,int>::iterator search = map.find(array[0]);
	REQUIRE(search->first == 'a');
	REQUIRE(search->second == 2);

	//Test for letter z with frequency 1
	search = map.find(array[3]);
	REQUIRE(search->first == 'z');
	REQUIRE(search->second == 1);

	//Test for character % with frequncy 1
	search = map.find(array[2]);
	REQUIRE(search->first == '%');
	REQUIRE(search->second == 1);

	// Test for new line character with frequency 1
	search = map.find(array[4]);
	REQUIRE(search->first == '\n');
	REQUIRE(search->second == 1);

}

TEST_CASE("Populate Queue", "This will test populateQueue function of the huffmanTree"){
	MNTDOM001::HuffmanTree tree;
	char array[6] = {'a', 'a', '%', '%', '%', '\n'};
	std::unordered_map<char,int> map = tree.createMap(array,6);

	MNTDOM001::HuffmanTree::myQueue nodes;
	tree.populateQueue(nodes,map);

	//Test the size of the Queue
	REQUIRE(nodes.size() == 3);

	//Test to check if the first item to be popped from the queue is the smallest one
	// .ie Node with the lowest frequency
	MNTDOM001::HuffmanNode node = nodes.top();
	REQUIRE(node.getCharacter() == '\n');
	REQUIRE(node.getFrequency() == 1);
	nodes.pop();

	//Check the rest of the items in the queue
	node = nodes.top();
	REQUIRE(node.getCharacter() == 'a');
	REQUIRE(node.getFrequency() == 2);
	nodes.pop();

	node = nodes.top();
	REQUIRE(node.getCharacter() == '%');
	REQUIRE(node.getFrequency() == 3);
	nodes.pop();
}

TEST_CASE("Populate Tree", "This will test if the tree if build correctly"){
	MNTDOM001::HuffmanTree tree;
	char array[6] = {'a', 'a', '%', '%', '%', '\n'};
	std::unordered_map<char,int> map = tree.createMap(array,6);

	MNTDOM001::HuffmanTree::myQueue nodes;
	tree.populateQueue(nodes,map);
	tree.populateTree(nodes);

	std::shared_ptr<MNTDOM001::HuffmanNode> root = tree.getRoot();
	REQUIRE(root->getCharacter() == ' ');
	REQUIRE(root->getFrequency() == 6);

	std::shared_ptr<MNTDOM001::HuffmanNode> rightLink = root->getRightLink();
	REQUIRE(rightLink->getCharacter() == '%');
	REQUIRE(rightLink->getFrequency() == 3);
	REQUIRE(rightLink->getLeftLink() == nullptr);
	REQUIRE(rightLink->getRightLink() == nullptr);

	std::shared_ptr<MNTDOM001::HuffmanNode> leftLink = root->getLeftLink();
	REQUIRE(leftLink->getCharacter() == ' ');
	REQUIRE(leftLink->getFrequency() == 3);

	rightLink = leftLink->getRightLink();
	REQUIRE(rightLink->getCharacter() == 'a');
	REQUIRE(rightLink->getFrequency() == 2);
	REQUIRE(rightLink->getLeftLink() == nullptr);
	REQUIRE(rightLink->getRightLink() == nullptr);

	leftLink = leftLink->getLeftLink();
	REQUIRE(leftLink->getCharacter() == '\n');
	REQUIRE(leftLink->getFrequency() == 1);
	REQUIRE(leftLink->getLeftLink() == nullptr);
	REQUIRE(leftLink->getRightLink() == nullptr);

}
