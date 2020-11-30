class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        len_answer = 0 # len: string
        # answer_string = ""
        longest_string = deque()
        for f in s:
            if f not in longest_string:
                longest_string.append(f)
                if len(longest_string) > len_answer:
                    len_answer = len(longest_string)
                    # answer_string = longest_string
            else:
                # pop from the left till
                while f in longest_string:
                    longest_string.popleft()
                longest_string.append(f)
                if len(longest_string) > len_answer:
                    len_answer = len(longest_string)
                    # answer_string = longest_string
        # print(f"answer string: {answer_string}")
        return len_answer
