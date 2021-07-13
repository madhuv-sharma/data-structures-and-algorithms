// Designed in Turbo C++

#include <alloc.h>
#include <conio.h>
#include <iostream.h>
#include <stdio.h>


struct Node
{ 
	int data; 
	Node *nxt; 
};


class LinkedList
{
	Node* head;

	public:

		LinkedList()
		{
			head = NULL;
		}


		void addatbeg(int n)
		{
			Node* new_node = new Node;
			new_node -> data = n;
			new_node -> nxt = NULL;
			if (head == NULL)
				head = new_node;
			else
			{
				new_node -> nxt = head;
				head = new_node;
			}
		}

		void append(int n)
		{
			Node *temp = new Node;
			Node *r = new Node;

			if(*head == NULL)
			{
				temp = (struct Node*) malloc(sizeof(struct Node));
				temp -> data = n;
				temp -> lnk = NULL;
				*head = temp;
			}
			else
			{
				temp = *head;

				while (temp -> lnk != NULL)
					temp = temp -> lnk;

				r = (struct Node*) malloc(sizeof(struct Node));
				r -> data = n;
				r -> lnk = NULL;
				temp -> lnk = r;
			}
		}

		void remove(int n)
		{
			if (head -> data == n)
			{
				delete head;
				head = head -> nxt;
				return;
			}
			else if (head -> nxt == NULL)
			{
				if (head -> data == n)
				{
					delete head;
					head = NULL;
					return;
				}
				cout << "Value not found!" << endl;
				return;
			}
			Node* temp = head;
			while(temp -> nxt!= NULL)
			{
				if (temp -> nxt -> data == val)
				{
					Node* temp_ptr = temp -> nxt -> nxt;
					delete temp -> nxt;
					temp -> nxt = temp_ptr;
					return;
				}
				temp = temp -> nxt;
			}
			cout << "Value not found" << endl;
		}


		void display()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << temp -> data << " ";
				temp = temp -> nxt;
			}
			cout << endl;
		}
};

int main()
{
	LinkedList l;
	
	cout << "Original Linked List: ";
	l.display();
	
	cout << "Adding elements at beginning: ";
	l.addatbeg(1);
	l.addatbeg(2);
	l.addatbeg(3);
	l.addatbeg(4);
	l.addatbeg(5);
	l.display();

	cout << "Appending 6: ";
	l.append(6);

	cout << "Deleting 2: ";
	l.remove(2);
	l.display();

	cout << "Deleting 9: ";
	l.remove(9);
}