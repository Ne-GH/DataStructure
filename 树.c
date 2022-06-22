#include<stdio.h>

#include<stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct {
	node* root;
}tree;

int max_mun(node* node) {
	if (node == NULL)
		return -1;
	else {
		int m1 = max_mun(node->left);
		int m2 = max_mun(node->right);
		int m3 = node->data;
		int max = m1;
		if (m2 > max) {
			max = m2;
		}
		if (m3 > max) {
			max = m3;

		}
		return max;
	}


}

int get_height(node* node) {
	if (node == NULL)
		return 0;
	else {
		int left_height = get_height(node->left);
		int right_height = get_height(node->right);
		int max = left_height;
		if (right_height > left_height)
			max = right_height;

		return max + 1;//加上的是根节点
	}
}
void insert(tree* tree, int value) {
	node* tnode = (node*)malloc(sizeof(node));
	tnode->data = value;
	tnode->left = NULL;
	tnode->right = NULL;

	if (tree->root == NULL) {
		tree->root = tnode;
	}
	else {
		node* temp = tree->root;
		while (temp != NULL) {
			if (value < temp->data) {

				if (temp->left == NULL) {
					temp->left = tnode;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL) {
					temp->right = tnode;

					return;

				}

				else {
					temp = temp->right;
				}
			}


		}


	}


}

void print(node* node) {
	if (node != NULL) {

		print(node->left);
		printf("%d\n", node->data);
		print(node->right);
	}
}

int main() {
	tree tree;
	tree.root = NULL;

	int arr[7] = { 6,3,8,2,5,1,7 };
	for (int i = 0; i < 7; ++i) {
		insert(&tree, arr[i]);
	}
	print(tree.root);

	int h = get_height(tree.root);
	printf("h: %d\n", h);

	int m = max_mun(tree.root);
	printf("max=%d\n", m);
	return 0;
}