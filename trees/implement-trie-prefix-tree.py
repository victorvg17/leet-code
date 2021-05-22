
class TrieNode:
    def __init__(self):
        # {key=str-i : value=TrieNode-i}
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curr = self.root
        for w in word:
            curr = curr.children[w]
        curr.is_word = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curr = self.root
        for w in word:
            if curr.children.get(w) is None:
                return False
            curr = curr.children[w]
        return curr.is_word
            

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curr = self.root
        for w in prefix:
            if curr.children.get(w) is None:
                return False
            curr = curr.children[w]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
