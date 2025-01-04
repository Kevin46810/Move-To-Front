//My code
#include <iostream>
#include <vector>

using namespace std;
#include "dlist.h"

//Client function List
void PrintMenu (char &c);
void FindAndMove(DList<int> &list, int item);
void AccessItem(DList<int> &list);
void Delete (DList<int> &list);
void PrintList (DList<int> &list);
int PrintLength (DList<int> &list);
void HeadInsert (DList<int> &list);
void TailInsert (DList<int> &list);

int main() {

        DList<int> list; //New list object
        char sel;

  //Loops until the user enters 'Q' or 'q'
        do {
                PrintMenu(sel); 
                switch(toupper(sel)) {
                        case 'H' : HeadInsert(list); break;
                        case 'T' : TailInsert(list); break;
                        case 'A' : AccessItem(list); break;
                        case 'D' : Delete(list); break;
                        case 'P' : PrintList(list); break;
                        case 'L' : cout << PrintLength(list) << endl; break;
                        case 'Q' : cout << "Program ended." << endl; break; 
                        default : cout << "\nInvalid input.  Try again." << endl;

}

}

        while (toupper(sel) != 'Q');

}

void PrintMenu (char &c) {

        cout << "\nPlease select one of the commands: " << endl;
        cout << "-------------------------------------" << endl;
        cout << "        H --> Insert head            " << endl;
        cout << "        T --> Insert tail            " << endl;
        cout << "        A --> Access an item         " << endl;
        cout << "        D --> Delete an item         " << endl;
        cout << "        P --> Print list             " << endl;
        cout << "        L --> Print list length      " << endl;
        cout << "        Q --> Quit program          \n" << endl;

        cout << "Enter your command here: ";
        cin >> c;
        cout << endl;

}

void AccessItem(DList<int> &list) {

  //Exits function if list is empty
  if (list.isEmpty()) {
    cout << "List empty." << endl;
    return;
  }
  
        int item;

  //User input
        cout << "Which item would you like to access?: ";
        cin >> item;
        cout << endl;
 
        FindAndMove(list, item); //Calls to move item to the front

}

void FindAndMove(DList<int> &list, int item) {
   
 //Exits function if item isn't found
 if (!list.inList(item)) {
   cout << "Item not found." << endl;
   return;
 }

  list.deleteItem(item); //Deletes item from its original position
  list.insertHead(item); //Reinserts item to the front
  
}

void Delete (DList<int> &list) {
  
    //Exits function if list is empty
    if (list.isEmpty()) {
    cout << "List empty." << endl;
    return;
  }
  
  int item;
  
  //User input
  cout << "Please enter the item you want to delete from the list: ";
  cin >> item;
  cout << endl;
  
  list.deleteItem(item); //Delete item call
  
}

void PrintList (DList<int> &list)  {
   
  list.print(); //Print list call
  
  }
  
int PrintLength (DList<int> &list)  {

  return list.lengthIs(); //Returns current length of list
  
}

void HeadInsert (DList<int> &list) {
    
  int item;
  
  //User input
  cout << "Please enter the integer you want to insert to head: ";
  cin >> item;
  cout << endl;
  
  //Prevents a duplicate item from getting added
  if (list.inList(item)) {
    cout << "Item already in list." << endl;
    return;
  }
  
  list.insertHead(item); //Insert head call
  
}

void TailInsert (DList<int> &list) {

  int item;
  
  //User input
  cout << "Please enter the integer you want to insert to tail: ";
  cin >> item;
  cout << endl;
  
  //Prevents a duplicate item from getting added
  if (list.inList(item)) {
    cout << "Item already in list." << endl;
    return;
  }
  
  list.appendTail(item); //Insert tail call
}
