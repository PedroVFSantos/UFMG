class Node:
    def init (self, data):
        self.data = data
        self.link = None

class Stack:
    def init (self):
        self.top = None

    def add (self, data):
        new_node = Node(data)
        new_node.link = self.top
        self.top = new_node


