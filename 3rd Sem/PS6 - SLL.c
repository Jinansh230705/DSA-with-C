// Problem_Statement_06: Implement Single Linked Lists and its operations
// (creation, insertion, deletion, traversal, search, reverse)

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

void display() {
    struct Node* ptr = head;
    printf("\n\t\thead->");
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->link;
    }
    printf(" ->NULL");
}

void insertionAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->link = head;
    head = newNode;
    printf("\n\t %d Inserted at beginning.", data);
}

void insertionAtEnd(int data) {
    struct Node* newNode = createNode(data);
    struct Node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newNode;
    printf("\n\t %d Inserted at end.", data);
}

void insertionAfterNode(int oldData, int newData) {
    struct Node* ptr = head;
    struct Node* newNode = createNode(newData);
    while (ptr != NULL) {
        if (ptr->data == oldData) {
            newNode->link = ptr->link;
            ptr->link = newNode;
            printf("\n\t %d inserted after %d.", newData, oldData);
            break;
        }
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("\n\t %d Node is not available.", oldData);
    }
}

void insertionBeforeNode(int oldData, int newData) {
    struct Node* ptr = head;
    struct Node* newNode = createNode(newData);
    struct Node* temp = NULL;
    while (ptr != NULL) {
        if (ptr->data == oldData) {
            newNode->link = ptr;
            temp->link = newNode;
            printf("\n\t %d inserted before %d.", newData, oldData);
            break;
        }
        temp = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("\n\t %d Node not available in the list.", oldData);
    }
}

void insertionAtPosition(int pos, int newData) {
    struct Node* ptr = head;
    struct Node* temp = NULL;
    struct Node* newNode = createNode(newData);
    int count = 1;
    while (ptr != NULL) {
        if (count == pos) {
            newNode->link = ptr;
            temp->link = newNode;
            printf("\n\t %d inserted at position %d.", newData, count);
            break;
        }
        temp = ptr;
        ptr = ptr->link;
        count++;
    }
    if (ptr == NULL) {
        printf("\n\t Linked List containing only %d Nodes", count - 1);
    }
}

void deleteNodeAtBeginning() {
    struct Node* ptr = head;
    struct Node* temp = ptr;
    ptr = ptr->link;
    head = ptr;
    printf("\n\t Node at beginning of the list deleted successfully.");
    free(temp);
    temp = NULL;
}

void deleteNodeAtEnd() {
    struct Node* ptr = head;
    struct Node* pre;
    while (ptr->link != NULL) {
        pre = ptr;
        ptr = ptr->link;
    }
    pre->link = NULL;
    printf("\n\t Node at end of the list deleted successfully.");
    free(ptr);
    ptr = NULL;
}

struct Node* deleteAfterNode(int node) {
    struct Node* ptr = head;
    struct Node* temp;
    while (ptr != NULL) {
        if (ptr->data == node) {
            temp = ptr;
            ptr = ptr->link;
            break;
        }
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("\n\t Node is not available in the list.");
        return NULL;
    }
    temp->link = ptr->link;
    printf("\n\t Node deleted successfully after %d.", node);
    free(ptr);
    ptr = NULL;
    return temp;
}

struct Node* deleteBeforeNode(int node) {
    struct Node* ptr = head;
    struct Node* temp = NULL;
    struct Node* prev = NULL;
    while (ptr != NULL) {
        if (ptr->data == node) {
            temp->link = prev->link;
            free(prev);
            prev = NULL;
            printf("\n\t Node deleted successfully before %d.", node);
            return ptr;
        }
        temp = prev;
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("\n\t Node not available in the List.");
        return NULL;
    }
    return NULL;
}

void deleteParticularNode(int node) {
    struct Node* ptr = head;
    struct Node* temp;
    while (ptr->data != node) {
        temp = ptr;
        ptr = ptr->link;
        if (ptr == NULL) {
            printf("\n\t Node is not available in the List.");
            return;
        }
    }
    temp->link = ptr->link;
    free(ptr);
    ptr = NULL;
    printf("\n\t Node %d deleted successfully from the List.", node);
}

void deleteNodeAtPosition(int pos) {
    struct Node* ptr = head;
    struct Node* temp;
    int count = 0;
    while (count != pos - 1) {
        temp = ptr;
        ptr = ptr->link;
        count++;
        if (ptr == NULL) {
            printf("\n\t Only %d Node available in the List.", count);
            return;
        }
    }
    temp->link = ptr->link;
    printf("\n\t Node deleted successfully at position %d from the List.", pos);
    free(ptr);
    ptr = NULL;
}

void searchNode(int data) {
    struct Node* ptr = head;
    int count = 1;
    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("\n\tNode %d found \n\tposition: %d \n\taddress: %p", data, count, ptr);
            break;
        }
        ptr = ptr->link;
        count++;
    }
    if (ptr == NULL) {
        printf("\n\t Node not found");
    }
}

void reverseList() {
    struct Node* prev = head;
    struct Node* current = prev->link;
    struct Node* next = current->link;
    prev->link = NULL;
    while (current != NULL) {
        current->link = prev;
        prev = current;
        current = next;
        if (current == NULL) {
            break;
        }
        next = next->link;
    }
    head = prev;
}

void main() {
    printf("\n\tLinked List");
    head = createNode(45);
    printf("\n\n\tInitially with single Node.");
    display();

    printf("\n\n\tInsertion of Node in the Singly Linked List");
    printf("\n\n\t1. Insertion at beginning.");
    insertionAtBeginning(22);
    insertionAtBeginning(15);
    display();

    printf("\n\n\t2. Insertion at end.");
    insertionAtEnd(56);
    insertionAtEnd(67);
    insertionAtEnd(78);
    display();

    printf("\n\n\t3. Insertion after a Node.");
    insertionAfterNode(45, 35);
    display();

    printf("\n\n\t4. Insertion before a Node.");
    insertionBeforeNode(67, 70);
    display();

    printf("\n\n\t5. Insertion at particular position.");
    insertionAtPosition(3, 30);
    display();

    printf("\n\n\t-- Search Node in the Singly Linked List --");
    searchNode(56);

    printf("\n\n\n\t-- Deletion of Node in the Singly Linked List --");

    printf("\n\n\t1. Deletion at beginning.");
    deleteNodeAtBeginning();
    display();

    printf("\n\n\t2. Deletion at end.");
    deleteNodeAtEnd();
    display();

    printf("\n\n\t3. Deletion after a Node.");
    deleteAfterNode(56);
    display();

    printf("\n\n\t4. Deletion before a Node.");
    deleteBeforeNode(78);
    display();

    printf("\n\n\t5. Deletion at particular position.");
    deleteNodeAtPosition(5);
    display();

    printf("\n\n\t6. Deletion of particular Node.");
    deleteParticularNode(30);
    display();

    printf("\n\n\t-----List after reversing the Nodes--------");
    reverseList();
    display();
}
