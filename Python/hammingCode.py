def calcRedundantBits(bitR):
    for i in range(bitR):
        if (2 ** i >= bitR + i + 1):
            return i


def posRedundantBits(datA, r):
    j = 0
    k = 1
    m = len(datA)
    res = ''

    # If position is power of 2 then insert '0'
    # Else append the data
    for i in range(1, m + r + 1):
        if (i == 2 ** j):
            res = res + '0'
            j += 1
        else:
            res = res + datA[-1 * k]
            k += 1

    # The result is reversed since positions are
    # counted backwards. (m + r+1 ... 1)
    return res[::-1]


def calcParityBits(arr, r):
    n = len(arr)
    for i in range(r):
        val = 0
        for j in range(1, n + 1):
            if (j & (2 ** i) == (2 ** i)):
                val = val ^ int(arr[-1 * j])
        arr = arr[:n - (2 ** i)] + str(val) + arr[n - (2 ** i) + 1:]
    return arr


def detectError(arr, nr):
    n = len(arr)
    res = 0

    # Calculate parity bits again
    for i in range(nr):
        val = 0
        for j in range(1, n + 1):
            if (j & (2 ** i) == (2 ** i)):
                val = val ^ int(arr[-1 * j])
        res = res + val * (10 ** i)

    return int(str(res), 2)


data = input("Input data")
# Calculate the no of Redundant Bits Required
m = len(data)
r = calcRedundantBits(m)

# Determine the positions of Redundant Bits
arr = posRedundantBits(data, r)

# Determine the parity bits
arr = calcParityBits(arr, r)

# Data to be transferred
print("Data transferred is " + arr)

arr = input("Enter data")
print("Error Data is " + arr)
correction = detectError(arr, r)
print("The position of error is " + str(correction))
