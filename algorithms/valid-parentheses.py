
class Solution:
    def isValid(self, s: str) -> bool:
        my_st = []
        for c in s:
            if c == "(" or c == "{" or c == "[":
                my_st.append(c)
            elif c == ")":
                if len(my_st) == 0:
                    return False
                if my_st.pop() != "(":
                    return False
            elif c == "}":
                if len(my_st) == 0:
                    return False
                if my_st.pop() != "{":
                    return False
            elif c == "]":
                if len(my_st) == 0:
                    return False
                if my_st.pop() != "[":
                    return False
        if len(my_st) == 0:
            return True
        else:
            return False
