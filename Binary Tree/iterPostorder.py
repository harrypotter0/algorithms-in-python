class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def peek(s):
    if len(s)>0:
        return s[-1]
    return None

def postOrderIterative(root):
    current = root
    stack = []
    while(current!=None or len(stack)>0):
        if(current!=None):
            stack.append(current)
            current = current.left
        else :
            temp = peek(stack).right
            if(temp == None):
                temp = stack.pop()
                print(temp.data)
                while(len(stack)>0 and temp==peek(stack).right):
                    temp = stack.pop()
                    print(temp.data)
            else :
                current = temp


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

postOrderIterative(root)
