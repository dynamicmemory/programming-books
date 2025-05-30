from typing import Optional, Any

class Node:

    def __init__(self, key):
        self.parent: Optional[Node] = None
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None 
        self.key = key


class BST:

    def __init__(self):
        self.root: Optional[Node] = None 


    def search(self, key: int) -> Optional[Node]:
        p: Optional[Node] = self.root

        while p != None and p.key != key:
            if key < p.key:
                p = p.left
            else:
                p = p.right

        return p

    def add(self, key: int) -> None:
        p: Optional[Node] = Node(key)
        
        if self.root == None:
            self.root = p 
        else:
            q: Optional[Node] = self.root
            while q != None:
                if p.key <= q.key:
                    if q.left != None:
                        q = q.left
                    else: 
                        break
                else:
                    if q.right != None:
                        q = q.right
                    else:
                        break;

            if p.key < q.key:
                q.left = p
                p.parent = q
            elif p.key > q.key:
                q.right = p
                p.parent = q
                    

    def walk_tree(self) -> None:
        p: Optional[Node] = self.root 

        def walk_helper(p: Optional[Node]) -> None:
            if p != None:
                walk_helper(p.left)
                print(f"{p.key} ")
                walk_helper(p.right)

        walk_helper(p)


    def maximum(self, p: Node) -> Node:
        if p != None:

            while p.right != None:
                p = p.right 

        return p


    def minimum(self, p: Node) -> Node:
        if p != None:

            while p.left != None:
                p = p.left 

        return p


    def transplant(self, p: Optional[Node], q: Optional[Node]) -> None:
        if p != None:
            if p.parent == None:
                self.root = q 
            elif p == p.parent.left:
                p.parent.left = q 
            else:
                p.parent.right = q

            if q != None:
                q.parent = p.parent 


    def remove(self, key: int) -> None:
        p: Optional[Node] = self.search(key)
        if p != None:
            if p.left == None:
                self.transplant(p, p.right)
            elif p.right == None:
                self.transplant(p, p.left)
            else:
                q = self.minimum(p.right)
                if q != p.right:
                    self.transplant(q, q.right)
                    q.right = p.right 
                    q.right.parent = q
                self.transplant(p, q)
                q.left = p.left 
                q.left.parent = q

bst = BST()

print(bst)
bst.add(4)
bst.add(9)
bst.add(1)
bst.add(3)
bst.add(6)
bst.add(8)
bst.add(2)
bst.add(7)

bst.walk_tree()


bst.remove(6)
bst.remove(11)

bst.walk_tree()















