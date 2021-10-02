def longestCommonSubsequenceLength(s1, s2):
    # Helper function for recursion
    def lcs(n,m,cache):
      if n == 0 or m == 0:
        return 0
            
      if cache[n-1][m-1] != -1:
        return cache[n-1][m-1]
            
      s1FinalCharacter = s1[n-1]
      s2FinalCharacter = s2[m-1]

      if s1FinalCharacter == s2FinalCharacter:
        cache[n-1][m-1] = 1 + lcs(n-1, m-1, cache)

      else:
        cache[n-1][m-1] = max(lcs(n-1, m, cache), lcs(n, m-1, cache))
      
      return cache[n-1][m-1]
        
    cache = [[-1 for j in range(len(s2))] for i in range(len(s1))]
    return lcs(len(s1), len(s2), cache)
a=int(input(""))
s1=list(map(int,input().split()))
b=int(input(""))
s2=list(map(int,input().split()))
print(longestCommonSubsequenceLength(s1,s2))