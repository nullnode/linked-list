#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;

// note: most of these comments are for my own reference to understand what I'm doing through each step
// note: linkedlist's work in essentially 2 parts; the following design should illustrate some of the wording used in the comments below
// note: our linkedlist can be visualized in the following diagram:      | |data| |next| |      the |next| block is equal to what we want our next node to be, hence the term linkedlist
// the above diagram shows a "node" with 2 parts; the data block is an int, the next block simply holds the value of another node which is next in line

LinkedList::LinkedList()
{
	top = NULL; // our constructor initializes our top variable (node pointer) to 0 in the same fashion as a size int would be initialized to 0 if we were using an array.
}

// Precondition: must be a valid number and not a string
// Postcondition: we create a node to hold the data value and then place it ontop of the stack.
// we create a new node called p to represent some new data to be pushed onto our stack, then we set the data variable within p to be equal to the data we took in from our push method
// after we assign our node some data, we declare that the "next" node (within p) is now saying "hey, the next node in line is top"
// then we make p our top entry into the stack by saying top = p 
void LinkedList::push(int value)
{
    node *p = new node; // node pointer to hold our new data to be pushed onto the stack
	p->data = value; // My first experience with the arrow operator! I'ts the same thing as p.data = value if we were using a node class instead of a struct!
	p->next = top; // now we're setting our "next" node (which is part of each node) = to our top object.
	top = p; // we're setting our linkedlist class's top node equal to p, which is what we just created. thus, each time we push a value, the new node that gets created now takes the top spot
	size++;
}

// Precondition: Since we're checking isEmpty() first, no errors should occur even with an empty stack.
// Postcondition: we're popping the top element off the stack and returning its value
// base case check to make sure the stack isnt empty, then we find the top value in our stack and return it
// we create a node and set it equal to top, then change top to be equal to the next node in line in temp, essentially returning the top node in the stack
int LinkedList::pop()
{
	if (isEmpty()) // if the stack is empty, we cant pop anything off
	{
		cout << "The stack is empty!" << endl;
		return false;
	}
    node *temp = top; // temporary variable to store top
	top = temp->next; // after setting our temp node equal to top, we now set top equal to temp's next.
	size--;
	return temp->data; // we return the data stored in temp, which is equal to top. effectively we are "popping" off the top element in the stack
}

// Precondition: our isEmpty() check will prevent any errors even with an empty stack
// we're simply taking a gander at the data value within the top node, IF it exists
// Postcondition: we'll return the data within the top node
int LinkedList::peek()
{
	if (isEmpty()) // we're checking to make sure the stack isnt empty, if its empty we cant peek at anything since nothing exists
	{
		cout << "The stack is empty!" << endl;
		return NULL;
	}
	return top->data; // we return the data within our top node
}

// returns true if our stack is empty and false if our stack has isnt empty
// we use the top node to determine if we have values on our stack or not, if the top is null then obviously its empty
bool LinkedList::isEmpty()
{
	return (top == NULL);
}

// returns the size of the array
int LinkedList::getSize()
{
	return size;
}
