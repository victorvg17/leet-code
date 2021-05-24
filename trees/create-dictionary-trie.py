
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def addWord(self, word: str) -> None:
        curr = self.root
        for w in word:
            curr = curr.children[w]
        curr.is_word = True
        

    def search(self, word: str) -> bool:
        curr = self.root
        self.res = False
        self.dfs(curr, word)
        return self.res
    
    def dfs(self, curr, word:str) -> None:
        if not word:
            if curr.is_word is True:
                self.res = True
            return
        if word[0] == ".":
            for n in curr.children.values():
                self.dfs(n, word[1:])
        else:
            curr = curr.children.get(word[0])
            if curr is None:
                return
            self.dfs(curr, word[1:])
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
