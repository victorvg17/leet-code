
class Solution:
    def decodeString(self, code: str) -> str:
        stack = []
        k = 0
        c_str = ""
        for c in code:
            if c.isdigit():
                k = 10*k + int(c)
            elif c == "[":
                curr_elem = (k, c_str)
                stack.append(curr_elem)
                c_str = ""
                k = 0
            elif c == "]":
                last_k, last_str = stack.pop()
                c_str = last_str + last_k*c_str
            else:
                c_str += c
        return c_str
