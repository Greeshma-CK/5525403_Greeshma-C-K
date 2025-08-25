#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER_ARRAY queries
#

def solve(arr, queries):
    result = []
    for d in queries:
        maxnum = max(arr[:d])
        minnum = maxnum
        
        for i in range(d, len(arr)):
            if arr[i-d] == maxnum:
                maxnum = max(arr[i-d+1:i+1])
            elif arr[i] > maxnum:
                maxnum = arr[i]
                
            if maxnum < minnum:
                minnum = maxnum
        result.append(minnum)
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    queries = []

    for _ in range(q):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = solve(arr, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
