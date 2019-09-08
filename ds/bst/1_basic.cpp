#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int key; 
	struct node_t *left, *right; 
} node; 

//utility functions
node *newNode(int key) {
	node *tmp = (node *)malloc(sizeof(node)); 
	tmp->key = key;
	tmp->left = tmp->right = NULL; 
	return tmp; 
}

node *insert(node *nd, int key) {
	if (nd==NULL) return newNode(key);

	if (key<nd->key)
		nd->left = insert(nd->left, key); 
	else if (key>nd->key)
		nd->right = insert(nd->right, key);
	return nd; 	 
}

void inorder(node *root) {
	if (root != NULL) {
		inorder(root->left); 
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

node *search(node *root, int key) {
	if (root==NULL || root->key==key)
		return root; 

	if (root->key<key)
		return search(root->right, key); 

	return search(root, key);
}

int main() {
	node *root= NULL; 
	root = insert(root, 50); 
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	inorder(root); 
	return 0; 
}
