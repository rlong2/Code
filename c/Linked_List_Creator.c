// Ryan Long
// CS2060_001
// HW 4 Linked List
// Due November 8, 2018

/** This program builds an ordered linked list of numbers greater than 0.
* When the user enters a number less than 0, the program prints the list,
* frees the memory allocated for the nodes, and exits the program.
*/

#include <stdio.h>
#include <stdlib.h>

/** Create node structure **/
struct listNode {
    int data;
    struct listNode *next;
};


/** Prototypes **/
void createNode(int userInput);
void insertNode();
void printList();
 void freeNodes();

/** Global Variables **/
struct listNode header = {0, NULL};


/** main **/
int main()
{
    int value = 0;

    printf("Welcome to Ryan Long's Ordered Linked List Creator!\n\n");
    printf("Enter a number greater than 0 to add to the list.\n");
    printf("Enter a number less than or equal to 0 to print the list and exit.\n\n");

    printf("input: ");
    scanf("%d", &value);

    while (value >= 1) {
        createNode(value);
        printf("input: ");
        scanf("%d", &value);
    }

    printList();

    freeNodes(&header);

    exit(0);

} // main


/** This function creates a node and allocates memory for it.
* The user's input is assigned to the data portion of the node
* and the node is made to point to NULL.  The function
* insertNode is called to sort and insert the node into the list.
*/
void createNode(int userInput) {

    struct listNode *newNode = NULL;
    newNode = (struct listNode *) malloc (sizeof(struct listNode));

    //initialize newNode
    newNode->data = userInput;
    newNode->next = NULL;

    //insert struct node by calling the insertNode method
    insertNode(newNode);

} //createNode


/** This function inserts a previously created node into
* the linked list, making sure to insert the nodes in
* ascending order, from smallest values to largest values.
* Each node is sorted as it is added to the list by comparing
* the new node's value to the nodes before it and after it
* as the node travels through the linked list.
*/
void insertNode(struct listNode *newNode) {
    struct listNode *current = NULL;
    struct listNode *previous = NULL;

    current = &header;
    previous = current;

        while (current != NULL && current->data <= newNode->data) {
            previous = current;
            current = current->next;
        }
            newNode->next = current;
            previous->next = newNode;

} // insertNode


/** This function prints the linked list contents by iterating
* through the linked list and printing values until the end of the
* linked list is reached.
*/
void printList() {


    printf("\nLinked List contents: [");
    while (header.next != NULL) {

        // Skips printing '0' from the beginning of the linked list
        if (header.data == 0) {
            header = *header.next;
        } else {
                printf("%d, ", header.data);
                header = *header.next;
                }

    } // while

    // Print last element in linked list
    printf("%d]\n", header.data);

} // printList


/** This function frees the nodes from the linked list.
* The header node is not freed because it is not dynamically allocated.
* The list is walked through and each node is saved to
* a temp node and then freed, node by node until the list is empty.
*/
void freeNodes() {

    struct listNode* current;
    // Initialize current to start of list
    current = &header;

    // Advance current to skip non-dynamically allocated header value
    current = current->next;

    struct listNode* temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

} // freeNodes
