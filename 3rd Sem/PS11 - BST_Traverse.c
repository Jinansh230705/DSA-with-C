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


void pre_Order(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
         pre_Order(root->left);
         pre_Order(root->right);
    }
}

void in_Order(struct Node* root) {
    if (root != NULL) {
        in_Order(root->left);
        printf("%d ", root->data);
        in_Order(root->right);
    }
}

void post_Order(struct Node* root) {
    if (root != NULL) {
        post_Order(root->left);
        post_Order(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    
    for(int i=0; i<n;i++){
    	int data;
    	printf("Enter Value for node %d: \n", i+1);
    	scanf("%d", &data);
    	root = insert(root,data);
	}
    
    printf("Inorder Traversal: \n");
    in_Order(root);
    printf("\n");

    printf("Preorder Traversal: \n");
    pre_Order(root);
    printf("\n");
   
    printf("Postorder Traversal: \n");
    post_Order(root);
    return 0;
}

