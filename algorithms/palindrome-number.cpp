class Solution:
    def reverse(self, x: int) -> int:
        reversed_num = 0

        while x > 0:
            reversed_num = reversed_num*10 + x%10
            x = x//10
        return reversed_num
    def isPalindrome(self, x: int) -> bool:
        neg = False
        if x < 0:
            neg = True
            return False
        if x > 2**31 - 1:
            return False
        reversed_num = self.reverse(x)
        if reversed_num == x:
            return True
