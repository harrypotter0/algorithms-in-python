class Node :
    def __init__(self.key):
        self.left = None
        self.right = None
        self.val = key

def search(root,key):

    # Base Cases: root is null or key is present at root
    if root is None or root.val == key:
        return root

    # Key is greater than root's key
    if root.val < key:
        return search(root.right,key)

    # Key is smaller than root's key
    return search(root.left,key)

def inorder(root):
    if root :
        inorder(root.left)
        print(root.val)
        inorder(root.right)
