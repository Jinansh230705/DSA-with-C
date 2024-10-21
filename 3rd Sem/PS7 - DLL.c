// Problem_Statement_07: Implement Double Linked Lists and its operations
// (creation, insertion, deletion, traversal, search, reverse)

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *start = NULL;
Node *end = NULL;

void printNodeStart() {
    Node *ptr = start;
    if (ptr == NULL) {
        printf("\nList is Empty");
        return;
    }
    printf("\n\t\tStart -> ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("End\n");
}

void printNodeEnd() {
    Node *ptr = end;
    if (ptr == NULL) {
        printf("\nList is Empty");
        return;
    }
    printf("\n\t\tEnd -> ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("Start\n");
}

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertionAtBeginning(int data) {
    Node *newNode = createNode(data);
    if (start == NULL) {
        start = end = newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    printf("\n\t %d Inserted at beginning.", data);
}

void insertionAtEnd(int data) {
    Node *newNode = createNode(data);
    if (start == NULL) {
        start = end = newNode;
    } else {
        end->next = newNode;
        newNode->prev = end;
        end = newNode;
    }
    printf("\n\t %d Inserted at end.", data);
}

void insertionAfterNode(int newData, int oldData) {
    Node *newNode = createNode(newData);
    Node *ptr = start;
    while (ptr != NULL) {
        if (ptr->data == oldData) {
            newNode->next = ptr->next;
            newNode->prev = ptr;
            if (ptr->next != NULL) ptr->next->prev = newNode;
            ptr->next = newNode;
            if (newNode->next == NULL) end = newNode; // Update the end pointer
            printf("\n\t %d inserted after %d.", newData, oldData);
            return;
        }
        ptr = ptr->next;
    }
    printf("\n\t %d Node is not available.", oldData);
}

void insertionBeforeNode(int newData, int oldData) {
    Node *newNode = createNode(newData);
    Node *ptr = start;
    while (ptr != NULL) {
        if (ptr->data == oldData) {
            newNode->next = ptr;
            newNode->prev = ptr->prev;
            if (ptr->prev != NULL) ptr->prev->next = newNode;
            ptr->prev = newNode;
            if (newNode->prev == NULL) start = newNode; // Update the start pointer
            printf("\n\t %d inserted before %d.", newData, oldData);
            return;
        }
        ptr = ptr->next;
    }
    printf("\n\t %d Node not available in the list.", oldData);
}

void insertionAtPosition(int newData, int pos) {
    Node *newNode = createNode(newData);
    Node *ptr = start;
    int count = 1;
    while (ptr != NULL) {
        if (count == pos) {
            newNode->next = ptr;
            newNode->prev = ptr->prev;
            if (ptr->prev != NULL) ptr->prev->next = newNode;
            ptr->prev = newNode;
            if (newNode->prev == NULL) start = newNode; // Update the start pointer
            printf("\n\t %d inserted at position %d.", newData, count);
            return;
        }
        ptr = ptr->next;
        count++;
    }
    printf("\n\t Position %d is out of range.", pos);
}

void searchNode(int data) {
    Node *ptr = start;
    int count = 1;
    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("\n\t Node %d found at position %d. Address: %p", data, count, ptr);
            return;
        }
        ptr = ptr->next;
        count++;
    }
    printf("\n\t Node %d is not available in the list.", data);
}

void deleteNodeAtBeginning() {
    if (start == NULL) {
        printf("List is empty.");
        return;
    }
    Node *ptr = start;
    start = start->next;
    if (start != NULL) start->prev = NULL;
    else end = NULL;
    printf("\n\t Node at beginning of the list deleted successfully.");
    free(ptr);
}

void deleteNodeAtEnd() {
    if (start == NULL) {
        printf("List is empty.");
        return;
    }
    Node *ptr = end;
    end = end->prev;
    if (end != NULL) end->next = NULL;
    else start = NULL;
    printf("\n\t Node at end of the list deleted successfully.");
    free(ptr);
}

void deleteAfterNode(int node) {
    Node *ptr = start;
    while (ptr != NULL) {
        if (ptr->data == node && ptr->next != NULL) {
            Node *temp = ptr->next;
            ptr->next = temp->next;
            if (temp->next != NULL) temp->next->prev = ptr;
            if (ptr->next == NULL) end = ptr; // Update end if needed
            free(temp);
            printf("\n\t Node deleted successfully after %d.", node);
            return;
        }
        ptr = ptr->next;
    }
    printf("\n\t Node %d is not available in the list.", node);
}

void deleteBeforeNode(int node) {
    Node *ptr = start;
    while (ptr != NULL) {
        if (ptr->data == node && ptr->prev != NULL) {
            Node *temp = ptr->prev;
            ptr->prev = temp->prev;
            if (temp->prev != NULL) temp->prev->next = ptr;
            if (ptr->prev == NULL) start = ptr; // Update start if needed
            free(temp);
            printf("\n\t Node deleted successfully before %d.", node);
            return;
        }
        ptr = ptr->next;
    }
    printf("\n\t Node %d is not available in the list.", node);
}

void deleteParticularNode(int node) {
    Node *ptr = start;
    while (ptr != NULL) {
        if (ptr->data == node) {
            if (ptr->prev != NULL) ptr->prev->next = ptr->next;
            if (ptr->next != NULL) ptr->next->prev = ptr->prev;
            if (ptr == start) start = ptr->next; // Update start if needed
            if (ptr == end) end = ptr->prev;     // Update end if needed
            free(ptr);
            printf("\n\t Node %d deleted successfully from the list.", node);
            return;
        }
        ptr = ptr->next;
    }
    printf("\n\t Node %d is not available in the list.", node);
}

void deleteNodeAtPosition(int pos) {
    Node *ptr = start;
    int count = 1;
    while (ptr != NULL) {
        if (count == pos) {
            if (ptr->prev != NULL) ptr->prev->next = ptr->next;
            if (ptr->next != NULL) ptr->next->prev = ptr->prev;
            if (ptr == start) start = ptr->next; // Update start if needed
            if (ptr == end) end = ptr->prev;     // Update end if needed
            free(ptr);
            printf("\n\t Node deleted successfully at position %d.", pos);
            return;
        }
        ptr = ptr->next;
        count++;
    }
    printf("\n\t Only %d nodes available in the list.", count - 1);
}

int main() {
    printf("\n\tDoubly Linked List: ");
    start = createNode(101);
    printf("\n\n\tInitially with a single node.");
    printNodeStart();

    printf("\n\n\t----Insertion of Nodes in the Doubly Linked List----");
    printf("\n\n\t1. Insertion At Beginning.");
    insertionAtBeginning(80);
    insertionAtBeginning(70);
    insertionAtBeginning(60);
    printNodeStart();

    printf("\n\n\t2. Insertion At End");
    insertionAtEnd(300);
    insertionAtEnd(400);
    insertionAtEnd(500);
    printNodeStart();

    printf("\n\n\t3. Insertion After Node");
    insertionAfterNode(90, 80);
    printNodeStart();

    printf("\n\n\t4. Insertion Before Node");
    insertionBeforeNode(200, 300);
    printNodeStart();

    printf("\n\n\t5. Insertion At Position");
    insertionAtPosition(100, 4);
    printNodeStart();

    printf("\n\n\t----Search a Node in the List----");
    searchNode(300);
    searchNode(150);

    printf("\n\n\t----Deletion of Nodes from the Doubly Linked List----");
    deleteNodeAtBeginning();
    printNodeStart();
    deleteNodeAtEnd();
    printNodeStart();
    deleteAfterNode(90);
    printNodeStart();
    deleteBeforeNode(200);
    printNodeStart();
    deleteParticularNode(101);
    printNodeStart();
    deleteNodeAtPosition(2);
    printNodeStart();

    printf("\n\n\tThe List Traversal From Start to End.");
    printNodeStart();
    printf("\n\n\tThe List Traversal From End to Start.");
    printNodeEnd();

    return 0;
}
