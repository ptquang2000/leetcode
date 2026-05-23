class BinaryNode:
   def __init__(self, value:int=0, left: 'BinaryNode | None' = None, right:'BinaryNode | None' = None):
      self.value = value
      self.left = left
      self.right = right

   @classmethod
   def create(cls, value: int | None):
      if value is None:
         return None
      else:
         return cls(value)


def form_binary_tree(values: list[int | None]) -> BinaryNode | None:
   if not values:
      return None

   head = BinaryNode.create(values.pop(0))
   next_node: list[BinaryNode | None] = [head]
   node_index = 0

   while values:
      node = next_node.pop(0)
      assert node is not None, f"Node at index {node_index} should not be None"

      assert len(values) > 1, "Missing child nodes"
      node.left = BinaryNode.create(values.pop(0))
      node.right = BinaryNode.create(values.pop(0))
      node_index += 2

      if node.left:
         next_node.append(node.left)
      if node.right:
         next_node.append(node.right)

   return head

def to_bfs(tree: BinaryNode | None) -> list[int | None]:
   if tree is None:
      return []
   nodes: list[BinaryNode | None] = [tree]
   result = []
   while nodes:
      node = nodes.pop()
      result.append(node.value if node is not None else None)
      if node:
         nodes.append(node.left)
         nodes.append(node.right)
   return result


def find_node_by_index(tree: BinaryNode | None, node_index: int) -> BinaryNode:
   nodes: list = [tree]
   index = 0
   while index < node_index:
      nodes.append(nodes[index].left)
      nodes.append(nodes[index].right)
      index += 1
   return nodes[node_index]
