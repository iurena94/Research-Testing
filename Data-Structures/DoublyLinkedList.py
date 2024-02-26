#Implementing a Doubly linked list 
class Node:
  def __init__(self, data):
    self.data = data
    self.prev = None
    self.next = None

class DoublyLinkedList:
  def __init__(self):
    self.head = None
    self.tail = None


  def print_list(self): 
    temp = self.head 
    full_list = []

    if self.is_empty():
      print("Empty List")
      return
    
    while(temp): 
      full_list.append(temp.data)
      temp = temp.next
    
    return print(full_list)
        

  def is_empty(self) -> bool: 
    # returns True of the list is empty
    return self.head is None


  # Push
  def push_head(self, new_data):
    new_node = Node(new_data)
    new_node.next = self.head

    if self.is_empty() == False: # If the list isn't empty
      self.head.prev = new_node # make the previous head point to the new node
      self.head = new_node # and assign the new node as the new head

    else: # If the list is empty, assign the new node as the head and tail 
      self.head = new_node
      self.tail = new_node


  def push_tail(self, new_data):
    new_node = Node(new_data)
    new_node.prev = self.tail

    if self.is_empty() == False: # If the list isn't empty
      self.tail.next = new_node # make the previous tail point to the new node
      self.tail = new_node # and assign the new node as the new tail

    else: # If the list is empty, assign the new node as the head and tail 
      self.head = new_node
      self.tail = new_node

  # Pop
  def pop_head(self): # removes and returns the head

    if self.is_empty:
      print("The list is empty")

    
    else:
      temp = self.head
      temp.next.prev = None # previous node will no longer point to the old head
      self.head = temp.next # previous node is the new head
      temp.next = None # delete the popped node
      return temp.data # return data

  def pop_tail(self): # removes and returns the tail
    if self.is_empty():
      print("The list is empty")
    
    else:
      temp = self.tail
      temp.prev.next = None # next node will no longer point to the old tail
      self.tail = temp.prev # next node is the new tail
      temp.prev = None # delete the popped node
      return temp.data # return data
    
  # Peek


  # Insert


def main():
  DLList = DoublyLinkedList()
  DLList.push_head(1)
  DLList.push_head(2)
  DLList.push_tail(3)
  DLList.push_head(4)
  DLList.push_tail(5)
  print("List Created")
  DLList.print_list() # returns [4,2,1,3,5]

  print("\nList Modified")
  DLList.pop_head()
  DLList.pop_tail()
  DLList.print_list() # returns [2,1,3]
  
  newDLL = DoublyLinkedList()
  print("New List Created")
  newDLL.print_list() # return "empty list"
  
  newDLL.pop_tail # return "The list is empty"
  newDLL.pop_head # return "The list is empty"
  

if __name__ == "__main__":
  main()
