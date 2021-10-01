def find3Numbers(A, n, X):
   
  A.sort()
  while(A[-1]>X):
    A.pop()
  n=len(A)
  for i in range(n-2):
    j=i+1
    k=n-1
    while(j<k):
      summ=A[i]+A[j]+A[k]
      if summ==X:
        return 1
                    
      elif summ<X:
        j+=1
      else:
        k-=1
  return 0

n=int(input())
X=int(input())
A=list(map(int,input().split()))
find3Numbers(A,n,X)