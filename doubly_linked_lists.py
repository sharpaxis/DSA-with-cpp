import gc


# creating nodes
class Node :
    def __init__ (self , data) :
        self.data = data
        self.next = None
        self.prev = None


# list object
class DoublyLinkedList :
    def __init__ (self) :
        self.head = None
        self.tail = None

    # inserting object at head
    def insertHead (self , new_data) :
        new_node = Node ( data=new_data )
        if self.head is None :
            self.head = new_node
            self.tail = new_node
        else :
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    # inserting object at tail
    def insertTail (self , new_data) :
        new_node = Node ( data=new_data )
        if self.tail is None :
            self.head = new_node
            self.tail = new_node
        else :
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    # inserting object when previous node is known
    def insertAfter (self , prev_node , new_data) :
        if prev_node is None :
            raise IndexError ( "Node doesn't exist" )
        new_node = Node ( data=new_data )
        new_node.next = prev_node.next
        new_node.prev = prev_node
        if prev_node.next is not None :
            prev_node.next.prev = new_node
        prev_node.next = new_node

    # inserting object when next node is known
    def insertBefore (self , next_node , new_data) :
        if next_node is None :
            raise IndexError ( "Node doesn't exist" )
        new_node = Node ( data=new_data )
        new_node.next = next_node
        new_node.prev = next_node.prev
        if next_node.prev is not None :
            next_node.prev.next = new_node
        next_node.prev = new_node
        if next_node == self.head :
            self.head = new_node

    # inserting object when index is known
    def insertIndex (self , new_data , n) :
        if n < 1 :
            return
        i = 1
        current = self.head
        while current is not None and i < n :
            current = current.next
            i += 1
        if current is None :
            return
        self.insertAfter ( current , new_data )

    # for accessing elements by index
    def indexnoderef (self , n) :
        if n < 1 :
            return
        i = 1
        current = self.head
        while current is not None and i < n :
            current = current.next
            i += 1
        if current is None :
            return
        else :
            return current

    # removing obj at head
    def removeHead (self) :
        if self.head is None :
            raise IndexError ( "Empty list" )
        if self.head == self.tail :
            self.head = None
            self.tail = None
        else :
            self.head = self.head.next
            self.head.prev = None

    # removing obj at tail
    def removeTail (self) :
        if self.tail is None :
            raise IndexError ( "Empty list" )
        if self.head == self.tail :
            self.head = None
            self.tail = None
        else :
            self.tail = self.tail.prev
            self.tail.next = None

    # removing given object
    def deleteObj (self , obj) :
        if self.head is None or obj is None :
            return
        if obj.next is not None :
            obj.next.prev = obj.prev
        if obj.prev is not None :
            obj.prev.next = obj.next
        gc.collect ( )

    # removing object at a given index
    def deleteIndex (self , n) :
        if self.head is None or n <= 0 :
            return
        i = 1
        current = self.head
        while current is not None and i < n :
            current = current.next
            i += 1
        if current is None :
            return
        self.deleteObj ( current )

    # printing out list forward or reverse
    def display (self , order) :
        if order == "forw" :
            current = self.head
            while current is not None :
                print ( str ( current.data ) , end=" " )
                current = current.next
        elif order == "rev" :
            current = self.tail
            while current is not None :
                print ( current.data , end=" " )
                current = current.prev


# creating a doubly linked list
dll = DoublyLinkedList ( )
dll.insertHead ( 1 )
node1 = Node ( 1 )
dll.insertTail ( 4 )
node4 = Node ( 4 )
dll.insertAfter ( node1 , 4 )
node4_2 = Node ( 4 )
dll.insertAfter ( node4_2 , 7 )
dll.insertTail ( 3 )
dll.insertTail ( 4 )
dll.insertAfter ( dll.indexnoderef ( 3 ) , 78 )
dll.display ( "rev" )
