#http://www.codechef.com/FEB13/problems/BUY1GET1/
def doIt():
    k = int(raw_input())
    for i in range(k):
        ary = {}
        for j in range(ord('A'),ord('Z') + 1):
            ary[chr(j)] = 0
        for j in range(ord('a'),ord('z') + 1):
            ary[chr(j)] = 0
        input = raw_input()
        for e in input:
            if(('a' <= e and e <= 'z') or ('A' <= e and e <= 'Z')): ary[e] += 1
        count = 0
        for v in ary.values():
            while(v > 0):
                v -= 2
                count += 1
        print count

        doIt()
