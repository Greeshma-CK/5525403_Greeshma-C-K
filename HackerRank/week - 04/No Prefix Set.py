#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'noPrefix' function below.
#
# The function accepts STRING_ARRAY words as parameter.
#

#!/bin/python3


#!/bin/python3

#!/bin/python3

class Node:
    def __init__(self, parent=None):
        self.parent = parent
        self.children = {}
        self.leaf = False

def noPrefix(words):
    root = Node(None)
    for word in words:
        node = root
        prefix = False
        exists = [] 

        for let in word:
            if let in node.children:
                child = node.children[let]
                exists.append(True)
            else:
                exists.append(False)
                child = Node(node)
                node.children[let] = child
            node = child
            if node.leaf:
                prefix = True
                break
        if prefix or all(exists):
            print("BAD SET")
            print(word)
            return

        node.leaf = True

    print("GOOD SET")


if __name__ == '__main__':
    n = int(input().strip())
    words = []
    for _ in range(n):
        words_item = input().strip()
        words.append(words_item)
    noPrefix(words)
