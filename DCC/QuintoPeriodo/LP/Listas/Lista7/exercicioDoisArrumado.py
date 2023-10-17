class Node:
    def __init__(self, data):
        self.data = data
        self.link = None

class Stack:
    def __init__(self):
        self.top = None

    def add(self, data):
        new_node = Node(data)
        new_node.link = self.top
        self.top = new_node

    def hasMore(self):
        return self.top is not None

    def remove(self):
        if self.top is None:
            return None
        removed_data = self.top.data
        self.top = self.top.link
        return removed_data

def test():
    s = Stack()
    s.add("AA")
    s.add(0)
    while s.hasMore():
        print(s.remove())

test()

