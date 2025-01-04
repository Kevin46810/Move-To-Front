Templates are being used so each class function can take on a different data type and be reused instead of creating a duplicate with a changed data type.  

DList class attributes:

-       Constructor -> Initializes length to 0 and have head pointer start at NULL
-       Destructor -> empties list once DList object goes out of scope
-       Insert head and tail -> functions to insert an item either at the front or back
-       Delete -> removes the item and its location from the list
-       Check if an item is in the list -> returns true if item found, false otherwise
-       Check for empty list -> returns true if no items are in list, false otherwise
-       Return tail location -> gives location of the back item
-       Print list -> outputs the items in the list (most recent head items go first, and most recent tail items go last)
-       Return list length -> gives current length of the list
-       Return node location -> gives location of the node containing a specified item

Move to the Front algorithms allows easier access to desired items.  If you’re dealing with a very long list of items, having the desired item at the front makes it easier to access.  The main algorithm of the Move to Front is finding the desired item and moving it to the front.  This is accomplished by the client functions AccessItem and FindAndMove.  

AccessItem checks if the list is empty.  If not, it proceeds to ask the user which item they want to access.  If the inputted item is in the list, the FindAndMove function is called.  The FindAndMove function simply deletes the item from its original location and reinserts it to the head.
