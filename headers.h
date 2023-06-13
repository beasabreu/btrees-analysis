#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// 1 , AFG , DIST , 93 , 18
struct rec
{
	int key;
	// rest
	char country[5];
	char grate[10];
	int score;
	int rate;
};
typedef struct rec recordNode;

// Structure to represent a record in the B-tree
struct bTreeNode
{
	bool isLeaf; // Flag indicating if the node is a leaf node
	int pos; // Position of the node in the file
	int noOfRecs; // Number of records in the node
	recordNode* recordArr[2 * t - 1]; // Pointers to the child nodes
	int children[2 * t]; // Array of record nodes
};
typedef struct bTreeNode bTreeNode;

// Structure for the B-tree
struct tree
{
	char fileName[20]; // Name of the file containing the B-tree
	FILE* fp; // File pointer
	int root; // Position of the root node in the file
	int nextPos; // Position for the next node to be inserted in the file
};
typedef struct tree bTree;


//Coments for methods in implementation.c
bTree* createTree(char* fileName,bool mode);
bTreeNode* nodeInit(bTreeNode* node,bool isLeaf,bTree* tree);
void insert(bTree* tree,recordNode* record);
void delete(bTree* tree,int key);
void traverse(bTree* tree, int root);
void dispNode(bTreeNode* node);
void writeFile(bTree* ptr_tree, bTreeNode* p, int pos);
void readFile(bTree* ptr_tree, bTreeNode* p, int pos);


void enterData(recordNode* record, int id_num, char country[], char Grate[], int Score, int Rate);
recordNode* getData(char *filepath, int len);
recordNode* search(bTree* tree, int key);
recordNode* searchRecursive(bTree* tree, int key, bTreeNode* root);
bool removeFromTree(bTree* tree, int key);
bTreeNode* merge(bTree* tree, bTreeNode *node, int idx);
void borrowFromNext(bTree* tree, bTreeNode *node, int idx);
void borrowFromPrev(bTree* tree, bTreeNode *node, int idx);
void fill(bTree* tree, bTreeNode *node, int idx);
recordNode *getSucc(bTree* tree, bTreeNode *node, int idx);
recordNode *getPred(bTree* tree, bTreeNode *node, int idx);
void removeFromNonLeaf(bTree* tree, bTreeNode *node, int idx);
void removeFromLeaf (bTree* tree, bTreeNode *node, int idx);
void removeNode(bTree* tree, bTreeNode* node, int k);
int findKey(bTreeNode* node, int k);
