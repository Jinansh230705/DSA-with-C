#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void in_Order(struct Node* root) {
    if (root != NULL) {
        in_Order(root->left);
        printf("%d ", root->data);
        in_Order(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n,d;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    
    for(int i=0; i<n;i++){
    	int data;
    	printf("Enter Value for node %d: \n", i+1);
    	scanf("%d", &data);
    	root = insert(root,data);
	}

    printf("Inorder Traversal before deletion: \n");
    in_Order(root);
    
    printf("Enter value to delete:\n");
    scanf("%d", &d);

    root = deleteNode(root, d);
    printf("In Order after %d is deleted: \n",d);
    in_Order(root);

    return 0;
}