import numpy as np
class Solution:

    def setReferenceVector(self, a, b):
        ax, ay = a[0], a[1]
        bx, by = b[0], b[1]
        print(f'a shape: {np.shape(a)} b shape: {np.shape(b)} a-b shape: {np.shape([ax-bx, ay-by])}')
        self.ref_vector = np.array([ax-bx, ay-by])
        print(f"self.ref_vector shape: {self.ref_vector.shape}")

    def getRelVector(self, a, b):
        ax, ay = a[0], a[1]
        bx, by = b[0], b[1]
        i_vector = np.array([ax-bx, ay-by])
        print(f"i_vector shape: {i_vector.shape}")
        return i_vector

    def checkStraightLine(self, coordinates) -> bool:
        if len(coordinates) == 2:
            return True
        #calculate the slope one time
        self.setReferenceVector(coordinates[0], coordinates[1])

        # loop through all points
        for i in range(0, len(coordinates)-1):
            i_vector = self.getRelVector(coordinates[i], coordinates[i+1])
            # do cross product
            if (np.cross(self.ref_vector, i_vector)):
                return False
        return True
