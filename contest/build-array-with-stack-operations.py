import numpy as np

class Solution:
    def isAlreadySolution(self, target, output):
        isSolution = False
        if len(target) == len(output):
            for targ, op in zip(target, output):
                if targ != op:
                    return isSolution
            isSolution = True
            return isSolution

    def buildArray(self, target, n: int):
        output = []
        output_array = []
        for i in range(1, n + 1):
            if i in target:
                output.append("Push")
                output_array.append(i)

            else:
                output.append("Push")
                output.append("Pop")

            # do check
            if (self.isAlreadySolution(target=target, output=output_array)):
                    return output

        return output
