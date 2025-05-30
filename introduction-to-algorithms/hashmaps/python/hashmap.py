from typing import Optional

class Node:
    
    def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
        self.next = next
        self.prev = prev 
        self.key = key


class LinkedList:

    def __init__(self) -> None:
        self.head = None


    def is_empty(self) -> bool:
        return self.head is None


    def search(self, key: int): 
        p = self.head 
        while p is not None and p.key != key:
            p = p.next 

        return p 

    
    def list_insert(self, key: int) -> None:
        p = Node(key, next=self.head)

        if self.head is not None:
            self.head.prev = p
        self.head = p


    def list_remove(self, key: int) -> None:
        p = self.search(key)

        if p is None:
            return 

        if p.prev is not None:
            p.prev.next = p.next 
        else:
            self.head = p.next

        if p.next is not None:
            p.next.prev = p.prev


    def list_print(self): 
        p = self.head 
        while p is not None:
            print(f"{p.key} ", end='')
            p = p.next 

        print()


class hashmap:

    def __init__(self, size = 13):
        self.size = size 
        self.map = [LinkedList() for _ in range(size)]

        
    def _hash(self, key: int) -> int:
        return key % self.size 


    def contains(self, key: int) -> bool:
        index: int = self._hash(key)
        return not self.map[index].search(key)

    def insert(self, key: int) -> None:
        index = self._hash(key)
        if self.contains(key):
            self.map[index].list_insert(key)

    def remove(self, key: int) -> None:
        index: int = self._hash(key)
        self.map[index].list_remove(key)

    def print(self):
        for _ in range(self.size):
            print(f"List {_}: ", end='')
            self.map[_].list_print()


map = hashmap()

map.insert(4)
map.insert(6)
map.insert(0)
map.insert(3)
map.insert(30)
map.insert(420)
map.insert(69)
map.insert(11)
map.insert(1)
map.insert(8)
map.insert(5)
map.print()






# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()

# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
# from typing import Optional
#
# class Node:
#
#     def __init__(self, key, next: Optional['Node'] = None, prev: Optional['Node'] = None):
#         self.next = next
#         self.prev = prev 
#         self.key = key
#
#
# class LinkedList:
#
#     def __init__(self) -> None:
#         self.head = None
#
#
#     def is_empty(self) -> bool:
#         return self.head is None
#
#
#     def search(self, key: int): 
#         p = self.head 
#         while p is not None and p.key != key:
#             p = p.next 
#
#         return p 
#
#
#     def list_insert(self, key: int) -> None:
#         p = Node(key, next=self.head)
#
#         if self.head is not None:
#             self.head.prev = p
#         self.head = p
#
#
#     def list_remove(self, key: int) -> None:
#         p = self.search(key)
#
#         if p is None:
#             return 
#
#         if p.prev is not None:
#             p.prev.next = p.next 
#         else:
#             self.head = p.next
#
#         if p.next is not None:
#             p.next.prev = p.prev
#
#
#     def list_print(self): 
#         p = self.head 
#         while p is not None:
#             print(f"{p.key} ", end='')
#             p = p.next 
#
#         print()
#
#
# class hashmap:
#
#     def __init__(self, size = 13):
#         self.size = size 
#         self.map = [LinkedList() for _ in range(size)]
#
#
#     def _hash(self, key: int) -> int:
#         return key % self.size 
#
#
#     def contains(self, key: int) -> bool:
#         index: int = self._hash(key)
#         return not self.map[index].search(key)
#
#     def insert(self, key: int) -> None:
#         index = self._hash(key)
#         if self.contains(key):
#             self.map[index].list_insert(key)
#
#     def remove(self, key: int) -> None:
#         index: int = self._hash(key)
#         self.map[index].list_remove(key)
#
#     def print(self):
#         for _ in range(self.size):
#             print(f"List {_}: ", end='')
#             self.map[_].list_print()
#
#
# map = hashmap()
#
# map.insert(4)
# map.insert(6)
# map.insert(0)
# map.insert(3)
# map.insert(30)
# map.insert(420)
# map.insert(69)
# map.insert(11)
# map.insert(1)
# map.insert(8)
# map.insert(5)
# map.print()
