#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList stack; // object of our linked list stack class!
	int choice; // used in our switch statement for the user to input a choice for the menu
	bool menu = true; // bool for keeping our menu open so the user can use the stack program until he exits by using option 4
	int num; // used for user input to push numbers onto the stack

	cout << "1 through 10 are being pushed onto the stack." << endl;
	for (int i = 1; i <= 10; i++) 
	{
		stack.push(i); // adding 0 - 9 to the stack
	}
	cout << "Our stack size is: " << stack.getSize() << endl;

	cout << "We will now pop the entire stack: " << endl;
	while (!stack.isEmpty()) // as long as the stack isnt empty, we're gonna pop each element
	{
		cout << stack.pop() << " "; //outputting the results of each pop
	}
	cout << endl;

	stack.push(5); // adding 5 to the top of the stack
	cout << "After pushing 5 onto the stack, our top element is: " << stack.peek() << endl; // takin a peek at the top element
	stack.push(1); // adding 1 to the top of the stack
	cout << "After pushing 1 onto the stack, our top element is: " << stack.peek() << endl; 
	cout << "Popping the stack gives us: " << stack.pop() << endl;
	cout << "Popping the stack gives us: " << stack.pop() << endl;
	cout << endl;

	cout << "Welcome to Chron's Stack Program!" << endl << "Please make a choice!" << endl;
	while (menu) // using this bool might be a bit silly, but it works perfectly and we can exit our program inside the switch statement 
	{
		cout << "1. Push" << endl << "2. Pop" << endl << "3. Peek" << endl << "4. Get size" << endl << "5. Exit" << endl;
		cin >> choice;
		while (choice > 5 || choice < 1) // protects our switch statement from invalid choices, since we have 1-4 as options
		{
			cout << "Invalid choice!";
			cin >> choice;
		}
		switch (choice) // menu for choosing whether to push, pop, or peek. plus we can exit if we choose 4
		{
		case 1:
			cout << "Enter a number to push: ";
			cin >> num;
			stack.push(num);
			cout << endl << num << " has been pushed onto the stack" << endl;
			break;
		case 2:
			cout << "Popping the stack: " << stack.pop() << endl;
			break;
		case 3:
			cout << "Peeking at the stack: " << stack.peek() << endl;
			break;
		case 4: 
			cout << "Size is: " << stack.getSize() << endl;
			break;
		case 5:
			cout << "Exiting, bye!" << endl;
			return 0;
		}
	}
	return 0;
}
