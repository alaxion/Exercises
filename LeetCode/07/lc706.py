# lc706.py

# LeetCode 706. Design HashMap `E`
# acc | 100% | 13'
# A~0h03

class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hm = {}

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        self.hm[key] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        return self.hm[key] if key in self.hm else -1

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        if key in self.hm:
            del self.hm[key]


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
