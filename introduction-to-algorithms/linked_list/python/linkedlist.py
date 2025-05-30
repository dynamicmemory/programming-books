from typing import Optional, Any

class Node:

    def __init__(self, key, next=None, prev=None):
        self.next = next
        self.prev = prev
        self.key = key


class Linked_List: 

    def __init__(self):
        self.head = Node(None);
        self.tail = Node(None);


    def search(self, key: int) -> Optional[Node]:
        p: Optional[Node] = self.head 
        while p:
            if p.key == key:
                return p 
            p: Optional[Node] = p.next
        return None


    def add(self, key: int) -> None:
        p = Node(key)

        if (self.head.key == None):
            self.head = p
            self.tail = p 
        else:
            self.tail.next = p
            p.prev = self.tail
            self.tail = p 
        

    def print_list(self) -> None:
        p = self.head 
        while p:
            print(p.key)
            p = p.next
        print()


    # def removefromhead(self) -> None:
    
    def remove(self, key: int) -> None:
        p: Optional[Node] = self.search(key)
        if p is None:
            print(f"{key} is not in list") 
        else:
            if p == self.head:
                # print(f"{key} is the head of the list")
                self.head = self.head.next
                # self.head.prev = None 
            elif p == self.tail:
                self.tail = self.tail.prev 
                self.tail.next = None
            else:
                p.next.prev = p.prev
                p.prev.next = p.next


ls: Linked_List = Linked_List()

ls.add(1)
ls.add(2)
ls.add(3)
ls.add(4)
ls.add(5)
ls.print_list()
ls.remove(3)
ls.print_list()
ls.remove(1)
ls.remove(5)
ls.print_list()
ls.remove(5)
ls.remove(4)
ls.remove(2)
ls.print_list()
ls.remove(10)
        




















# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next=None, prev=None):
#         self.next = next
#         self.prev = prev
#         self.key = key
#
#
# class Linked_List: 
#
#     def __init__(self):
#         self.head = Node(None);
#         self.tail = Node(None);
#
#
#     def search(self, key: int) -> Optional[Node]:
#         p: Optional[Node] = self.head 
#         while p:
#             if p.key == key:
#                 return p 
#             p: Optional[Node] = p.next
#         return None
#
#
#     def add(self, key: int) -> None:
#         p = Node(key)
#
#         if (self.head.key == None):
#             self.head = p
#             self.tail = p 
#         else:
#             self.tail.next = p
#             p.prev = self.tail
#             self.tail = p 
#
#
#     def print_list(self) -> None:
#         p = self.head 
#         while p:
#             print(p.key)
#             p = p.next
#         print()
#
#
#     # def removefromhead(self) -> None:
#
#     def remove(self, key: int) -> None:
#         p: Optional[Node] = self.search(key)
#         if p is None:
#             print(f"{key} is not in list") 
#         else:
#             if p == self.head:
#                 # print(f"{key} is the head of the list")
#                 self.head = self.head.next
#                 # self.head.prev = None 
#             elif p == self.tail:
#                 self.tail = self.tail.prev 
#                 self.tail.next = None
#             else:
#                 p.next.prev = p.prev
#                 p.prev.next = p.next
#
#
# ls: Linked_List = Linked_List()
#
# ls.add(1)
# ls.add(2)
# ls.add(3)
# ls.add(4)
# ls.add(5)
# ls.print_list()
# ls.remove(3)
# ls.print_list()
# ls.remove(1)
# ls.remove(5)
# ls.print_list()
# ls.remove(5)
# ls.remove(4)
# ls.remove(2)
# ls.print_list()
# ls.remove(10)
#
