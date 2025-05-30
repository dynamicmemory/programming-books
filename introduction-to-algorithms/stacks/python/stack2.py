from typing import Any, Optional


class Stack:

    def __init__(self):
        """
        Constructor for the stack class 
        """

        self._data = []


    def push(self, item) -> None:
        """
        Add and element to the stack 
        """

        self._data.append(item)


    def pop(self) -> Optional[Any]:
        """ 
        Remove the top element from the stack and return it or None if empty 
        """

        if not self._data:
            raise IndexError("Stack is empty")
        return self._data.pop()


    def peek(self) -> Any:
        """
        Return the top element from the stack 
        """

        if not self._data:
            return None 
        return self._data[-1]


    def is_empty(self) -> bool:
        """
        Check if a stack is empty 
        """

        return len(self._data) == 0














# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
# from typing import Any, Optional
#
#
# class Stack:
#
#     def __init__(self):
#         """
#         Constructor for the stack class 
#         """
#
#         self._data = []
#
#
#     def push(self, item) -> None:
#         """
#         Add and element to the stack 
#         """
#
#         self._data.append(item)
#
#
#     def pop(self) -> Optional[Any]:
#         """ 
#         Remove the top element from the stack and return it or None if empty 
#         """
#
#         if not self._data:
#             raise IndexError("Stack is empty")
#         return self._data.pop()
#
#
#     def peek(self) -> Any:
#         """
#         Return the top element from the stack 
#         """
#
#         if not self._data:
#             return None 
#         return self._data[-1]
#
#
#     def is_empty(self) -> bool:
#         """
#         Check if a stack is empty 
#         """
#
#         return len(self._data) == 0
#
#
#
#
