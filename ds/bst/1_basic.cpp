#include <iostream>
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
		std::cout << root->key << " ";
		inorder(root->right);
	}
}

void preorder(node *root) {
	if (root != NULL) {
		std::cout << root->key << " ";		
		preorder(root->left); 
		preorder(root->right);
	}
}

void postorder(node *root) {
	if (root != NULL) {	
		postorder(root->left); 		
		postorder(root->right);
		std::cout << root->key << " ";				
	}
}
#if 0
typedef struct list_t {
	node *np;
	struct list_t *next;
} list;

void levelorder(node *root) {
	list *head; 
	head = (list *)malloc(sizeof(list));
	head->np = root; 
	head->next = NULL;

	list *last = head; 

	while (head && head->np) {
		if (head->np->left) {
			last->next = (list *)malloc(sizeof(list));
			last = last->next; 
			last->np = head->np->left; 
			last->next = NULL;
		}
		if (head->np->right) {
			last->next = (list *)malloc(sizeof(list));
			last = last->next; 
			last->np = head->np->right; 
			last->next = NULL;
		}	

		list *cur = head; 
		head = cur->next; 
		std::cout << cur->np->key << " ";
		free(cur->np);
		free(cur); 
	}
}
#endif
#if 1
#include <queue>
using namespace std;
void levelorder(node *root) {
	if (root==NULL) return; 
	queue<node *> q;

	q.push(root);
	while(!q.empty()) {
		node *cur = q.front(); 
		std::cout << cur->key << " "; 
		q.pop();

		if (cur->left) q.push(cur->left); 
		if (cur->right) q.push(cur->right);
	}
}
#endif

node *search(node *root, int key) {
	if (root==NULL || root->key==key)
		return root; 

	if (root->key<key)
		return search(root->right, key); 

	return search(root, key);
}

int tree_height(node *root) {
	if (root == NULL)
		return 0; 
	else {
		int lsth = tree_height(root->left); 
		int rsth = tree_height(root->right); 
		if (lsth>rsth)
			return lsth+1; 
		else
			return rsth+1;
	}
}

int main() {
	node *root= NULL; 

#if 1
	root = insert(root, 50); 
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
#endif

#if 0
	root = insert(root, 25); 
	insert(root, 15);
	insert(root, 50);
	insert(root, 10);
	insert(root, 22);
	insert(root, 35);
	insert(root, 70);
	insert(root, 4);
	insert(root, 12);
	insert(root, 18);
	insert(root, 24);	
	insert(root, 31);
	insert(root, 44);
	insert(root, 66);
	insert(root, 90);	
#endif

	std::cout << "Height of the tree: " << tree_height(root) << std::endl;
	
	std::cout << "Inorder (Left, Root, Right) traversal: ";
	inorder(root); 
	std::cout << std::endl;

	std::cout << "Preorder (Root, Left, Right) traversal: ";
	preorder(root); 
	std::cout << std::endl;

	std::cout << "Postorder (Left, Right, Root) traversal: ";
	postorder(root); 
	std::cout << std::endl;

	std::cout << "BFS or Levelorder (Left, Right, Root) traversal: ";
	levelorder(root); 
	std::cout << std::endl;
	return 0; 
}
