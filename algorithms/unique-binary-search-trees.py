class Solution:
    def numTrees(self, n: int) -> int:
        """
        G(n): number of unique BSTs for sequence of length n.
        F(i, n): number of unique BSTs with i as root and sequence length n.
        G(n) = F(1, n) + F(2, n) + F(3, n) + .... F(n, n)
        F(i, n) = G(i-1)*G(n-i)
        G(n) = sum([G(i-1)*G(n-i)])
        G(n) = G(0)*G(n-1) + G(1)*G(n-2) + G(2)*G(n-3) + ... G(n-1)*G(0)
        base case: G(0) = 0, G(1) = 1
        """
        G = [0]*(n+1)
        G[0] = 1
        G[1] = 1
        
        for i in range(2, n+1):
            for j in range(1, i+1):
                G[i] += G[j-1]*G[i-j]
        return G[n]

        
        
