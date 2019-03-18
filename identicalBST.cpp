 #include<iostream>
#include <assert.h>  

struct node{
	int key;
	 node *left, *right;
};

// A utility function to create a new BST node 
struct node *newNode(int item){
	node *temp =new node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST 
void inorder(node *root){
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(node* node, int key){
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

bool are_identical(node* root1, node* root2) {
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}

	if (root1 != nullptr && root2 != nullptr) {
		return ((root1->key == root2->key) &&
			are_identical(root1->left, root2->left) &&
			are_identical(root1->right, root2->right));
	}
	return false;
}

int main(){
	node *root = NULL;
	root = insert(root, 50);
	for (int i = 0; i < 10; i++) {
		int m= rand() % 100;
		insert(root, m);
    }
	inorder(root); // print inoder traversal of the BST 

	assert(are_identical(root, root));
	//assert(are_identical(root, NULL));
	system("pause");
	return 0;
}
