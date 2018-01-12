class Node :
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def maxDepth(node):
    if node is None :
        return 0
    else :
        ldepth = maxDepth(node.left)
        rdepth = maxDepth(node.right)

        if (ldepth>rdepth):
            return ldepth +1
        else :
            return rdepth +1
        
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)


print "Height of tree is %d" %(maxDepth(root))
