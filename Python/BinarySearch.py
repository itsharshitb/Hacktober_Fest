# Iterative Approach
# Time Complexity -> O(log N)

def Binary_Search(Array, X):
    Low = 0
    High = len(Array) - 1
    Middle = 0
 
    while Low <= High:
 
        Middle = (High + Low) // 2
 
        # X is Greater --> Ignore Left Half
        if Array[Middle] < X:
            Low = Middle + 1
 
        # X is Smaler --> Ignore Right Half
        elif Array[Middle] > X:
            High = Middle - 1
 
        # X is @ Middle
        else:
            return Middle
 
    return -1           # X not found in Array
 
 
# Sample Array
A = [5, 10, 15, 20, 25]
x = 20
 
# Calling Our Binary Search Function
Result = Binary_Search(A, x)
 
if Result != -1:
    print("ELEMENT FOUND AT INDEX :", str(Result))
else:
    print("ELEMENT IS ABSENT IN GIVEN ARRAY !")
