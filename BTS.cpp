#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* NewNode(int data)
{
	node* node = new (struct node);

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
struct node* insert(struct node* node, int data) {
	if (node == NULL) {
		return(NewNode(data));
	}
	else {
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		return(node);
	}
}
int size(struct node* node) {
	if (node == NULL) {
		return(0);
	}
	else {
		return(size(node->left) + 1 + size(node->right));
	}
}
int minValue(struct node* node) {
	if (node == NULL) {
		cout << " tree empty" << endl;
	}
	struct node* key = node;
	while (key->left != NULL)
		key = key->left;
	return (key->data);
}
int maxValue(struct node* node) {
	if (node == NULL)
	{
		cout << " tree empty " << endl;
	}
	struct node* key = node;
	while (key->right != NULL)
		key = key->right;

	return (key->data);
}
/*void evenElements(struct node* node)
{
	if (node != NULL) {
		evenElements(node->left);
		if (node->data % 2 == 0) {
			cout << " \n\n\n " << (node->data);
			evenElements(node->right);
		}
	}
}*/
void oddElements(struct node* node)
{
	if (node != NULL) {
		oddElements(node->left);
		if (node->data % 2 != 0)
			cout << " \n\n Odd elements of tree " << (node->data);
		oddElements(node->right);
	}
}
int sumElements(struct node* node)
{
	if (node == NULL) {
		return NULL;
	}
	return(node->data + sumElements(node->left) + sumElements(node->right));
}

void printTree(struct node* node) {
	if (node == NULL) return;
	printTree(node->left);
	cout << " " << (node->data);
	printTree(node->right);
}
void postorder(struct node* node) {
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout << " \n Postorder traversal:  " << (node->data);
	}
}
void inorder(struct node* node) {
	if (node != NULL)
	{
		inorder(node->left);
		cout << "\n Inorder  traversal : " << (node->data);
		inorder(node->right);
	}
}
void preorder(struct node* node) {
	if (node != NULL) {
		cout << "\n Preorder  traversal : " << (node->data);
		preorder(node->left);
		preorder(node->right);
	}
}int searchbst(node* root, int val)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->data == val)
	{
		return 1;
	}
	if (root->data < val)
	{
		return searchbst(root->right, val);
	}
	else
	{
		return searchbst(root->left, val);
	}
}
node* remove(node* root, int val)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->data > val)
	{
		root->left = remove(root->left, val);
	}
	else if (root->data < val)
	{
		root->right = remove(root->right, val);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		else if (root->left == NULL)
		{
			node* temp = new node;
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			node* temp = new node;
			temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			int min = minValue(root->right);
			root->data = min;
			root->right = remove(root->right, min);
		}
	}
	return root;
}
int main()
{
	node* node = NULL;
	node = insert(node, 5);
	insert(node, 3);
	insert(node, 2);
	insert(node, 1);
	insert(node, 8);
	insert(node, 9);
	insert(node, 6);
	insert(node, 7);
	insert(node, 4);

	oddElements(node);
	inorder(node);
	postorder(node);
	preorder(node);
	cout << "\n\n Min value - " << minValue(node);

	cout << "\n\n Max value - " << maxValue(node);
	size(node);
	cout << "\n\n Sum all elements - " << sumElements(node);

	cout << " \n\n Size binary tree -  " << size(node) << endl;
	remove(node, 3);
	remove(node, 6);
	remove(node, 7);
	remove(node, 9);
	inorder(node);
	return 0;
}