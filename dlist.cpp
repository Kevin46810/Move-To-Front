//My code
#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info; //Used to extract the item in the node
	NodeType<ItemType>*     next; //Pointer for next node
	NodeType<ItemType>*     back; //Pointer for previous node
};

template <class ItemType>
DList<ItemType>::DList()                // Class constructor
{
	length = 0; //Length initialized at 0
	head = NULL; //Head starts NULL
}

template <class ItemType>
DList<ItemType>::~DList   ()
{
	// Post: List is empty; All items have been deallocated.

	makeEmpty(); //List becomes empty once object goes out of scope

}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
	// Post: List is empty; all items have been deallocated.

	NodeType<ItemType>* tempPtr;

	while (head != NULL)
	{
		tempPtr = head; //Gives us access to the current head pointer before moving it
		head = head->next; //Moves head pointer
		delete tempPtr; //Deallocate the memory tempPtr was pointing to
	}
	length = 0; //Reset length to 0


}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)
{
	//  Pre :  item to be deleted is passed in via parameter 
	// Post :  item is deleted if it exists in list 

	//Exits function if the item does not exist
	if (!inList(item)) {
		cout << "Item does not exist." << endl;
		return;
	}

	//Creates a new pointer to point to head's pointee
	NodeType<ItemType>* temp = head;

	//Iterates through the list until the node with the selected item is found
	while (temp != NULL) {
		if (temp -> info == item)
			break;
		temp = temp -> next;
	}

	deleteLocation(temp); //Delete the item's location on the list
	length--; //Update length

}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)
{

	//  Pre : Item to be deleted exits in list and its location
	//        is passed in via parameter

	// Post : Location passed in is removed from list;  Length
	//        is decremented, and location is deallocated 

	// Special Cases Handled for Deleting Only One Item in List,
	// The Head Item of List, and the Tail Item of List

	//Head delete
	if (delPtr == head) {
		head = head -> next; 

		//Set the now previous node to null if moving the head didn't already make it null
		if (head != NULL) 
			head -> back = NULL; 

			delete delPtr; //Deallocate the memory
			delPtr = NULL; //No dangling pointers
			return; //Exit function
	}

	//Tail delete
	else if (delPtr -> next == NULL) {
		delPtr -> back -> next = NULL; //Set the previous node's next to NULL

		delete delPtr; //Deallocate memory
		delPtr = NULL; //No dangling pointers
		return; //Exit function
	}

	//Else
	//Given that delPtr's next is not null, set the previous node to point to delPtr's next
	if (delPtr -> next != NULL)
		delPtr -> back -> next = delPtr -> next;

		//Given that delPtr's previous is not null, set the next node to point to delPtr's previous
		if (delPtr -> back != NULL)
			delPtr -> next -> back = delPtr -> back;

			//The two above statements maintain the doubly linked list

			delete delPtr; //Deallocate memory
			delPtr = NULL; //No dangling pointers

}

template <class ItemType>
void DList<ItemType>::print() const
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen

	//Exits function if list is empty
	if (isEmpty()) {
		cout << "List empty." << endl;
		return;
	}

	NodeType<ItemType>* temp = head; //New pointer to point to head's pointee 

	//Prints each item until there's none left
	while (temp != NULL) {
		cout << temp -> info;
		cout  << " ";
		temp = temp -> next;  
	}

	cout << endl;
	delete temp; //Deallocate memory
	temp = NULL; //No dangling pointers

}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
	// Post :  function returns bool value if item is found 

	NodeType<ItemType>* temp = head; //New pointer to point to head's pointee 

	//Return true if item is found
	while (temp != NULL) {
		if (temp -> info == item)
			return true;
		temp = temp -> next;

	}

	return false; //Item not found

}

template <class ItemType>
bool DList<ItemType>::isEmpty() const
{
	// Post : function returns true if list is empty, false otherwise

	return (head == NULL); //If head is null, the list is empty

}


template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)
{
	//  Pre : item to be inserted is passed in via parameter
	// Post : item is inserted at head of list;  Former first node is 
	//        linked back to this new one via double link;
	//        Length incremented;  Special case handled if list is empty 

	NodeType<ItemType>* temp = new NodeType<ItemType>; //Gives new memory to a new pointer
	temp -> info = item; //Sets current node's item to the item passed in
	temp -> back = NULL; //Makes the current node the head

	//Enters if there are no items in the list
	if (isEmpty()) {
		temp -> next = NULL;
		head = temp;
		length++;
		return;
	}

	//Activates these statements otherwise
	temp -> next = head;
	temp -> next -> back = temp; 
	head = temp;
	length++;

}

template <class ItemType>
int DList<ItemType>::lengthIs() const
{
	// Post : Function returns current length of list

	return length;

}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const
{
	//  Pre : item to be located is passed in via parameter 
	// Post : function returns address of item being searched for --
	//        if not found, NULL is returned  

	NodeType<ItemType>* temp = new NodeType<ItemType>;  //Gives new memory to a new pointer

	//Iterates until item passed in is found
	while (temp != NULL) {
		if (temp -> info == item)
			break;

		temp = temp -> next;
	}

	//Item found
	if (temp != NULL) {
		return temp;
	}

	return NULL; //Item not found

}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
	// Post :  item is added to tail of list; Former last node
	//         is linked to this new one via double link 

	NodeType<ItemType>* temp = new NodeType<ItemType>; //New memory for a new pointer

	temp -> info = item;
	temp -> next = NULL; //Sets the current node as the tail

	//Enters if list is empty
	if (isEmpty()) {
		temp -> back = NULL;
		head = temp;
		length++;
		return;
	}

	//Activates these statements otherwise
	temp -> back = last();
	temp -> back -> next = temp; //Links the previous node's next with the current node
	length++;


}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const
{
	// Post : Function returns location of current last item in list

	NodeType<ItemType>* temp = head; //temp points to the pointee of the head

	//Keeps going until the end of the list is reached
	while (temp -> next != NULL) 
		temp = temp -> next;

		return temp;

}
