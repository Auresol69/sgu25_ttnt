class node:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def __eq__(self, other):
        return self.a == other.a and self.b == other.b
    def __hash__(self):
        return hash((self.a, self.b))
    def getA(self):
        return self.a

visited = set([node(1,1), node(2,2), node(2,2)])
for i in visited:
    print(f"{i.a} {i.b}")
