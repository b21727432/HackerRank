#!/usr/bin/env python
# coding: utf-8




def yazdir(blockSize):
    for i in range(len(blockSize)):
        f2.write(str(blockSize[i]) + " ")




def yazdir2(blockSize, inserted):
    for i in range(len(blockSize)):
        if(blockSize[i] in inserted):
            f2.write(str(blockSize[i]) + "* ")
        elif(blockSize[i] != 0):
            f2.write(str(blockSize[i]) + " ")


f = open("untitled4.txt", "r")
f2 = open("output.txt", "w")
lines = []
for i in f:
    i = i.strip("\n")
    lines.append(i)


first = lines[0].split(",")
second = lines[1].split(",")
originalblockSize = [int(x) for x in first]
originalprocessSize = [int(x) for x in second]


f2.write("First-Fit Memory Allocation\n")
f2.write("---------------------------------------------------------------------\n")


# first fit
firstblockSize = originalblockSize.copy()
firstprocessSize = originalprocessSize.copy()
f2.write("start =>")
yazdir(firstblockSize)
f2.write("\n")
firstinserted = []
for i in range(len(firstprocessSize)): # prosesler arasında geziyor
    count = 0
    for y in range(len(firstblockSize)): # memoryler arasında geziyor
        if(firstprocessSize[i] < firstblockSize[y] and (firstblockSize[y] not in firstinserted)):
            firstblockSize.insert(y+1, firstblockSize[y] - firstprocessSize[i])
            firstblockSize[y] = firstprocessSize[i]
            firstinserted.append(firstprocessSize[i])
            count = count + 1
            f2.write(str(firstprocessSize[i]) + " =>")
            yazdir2(firstblockSize, firstinserted)
            f2.write("\n")
            break
    if(count == 0):
        f2.write(str(firstprocessSize[i]) + " => not allocated, must wait")


f2.write("Best-Fit Memory Allocation")
f2.write("---------------------------------------------------------------------\n")


# best fit kendinden buyuk en kucuk
bestinserted = []
bestblockSize = originalblockSize.copy()
bestprocessSize = originalprocessSize.copy()
f2.write("start => ")
yazdir(bestblockSize)
f2.write("\n")
for i in range(len(bestprocessSize)): # prosesler arasında geziyor
    minblock = 999
    minindex = 0
    count = 0
    for y in range(len(bestblockSize)): # memoryler arasında geziyor
        if(bestprocessSize[i] <= bestblockSize[y] and (bestblockSize[y] not in bestinserted) and bestblockSize[y] < minblock):
            minblock = bestblockSize[y]
            minindex = y
            count = count + 1
    if(count == 0):
        f2.write(str(bestprocessSize[i]) + " => not allocated, must wait")
    else:
        bestblockSize.insert(minindex+1, bestblockSize[minindex] - bestprocessSize[i])
        bestblockSize[minindex] = bestprocessSize[i]
        bestinserted.append(bestprocessSize[i])
        f2.write(str(bestprocessSize[i]) + " => ")
        yazdir2(bestblockSize, bestinserted)
        f2.write("\n")




f2.write("Worst-Fit Memory Allocation")
f2.write("---------------------------------------------------------------------\n")


# worst fit kendinden buyuk en kucuk
worstinserted = []
worstblockSize = originalblockSize.copy()
worstprocessSize = originalprocessSize.copy()
f2.write("start => ")
yazdir(worstblockSize)
f2.write("\n")
for i in range(len(worstprocessSize)): # prosesler arasında geziyor
    maxblock = 0
    maxindex = 0
    count = 0
    for y in range(len(worstblockSize)): # memoryler arasında geziyor
        if(worstprocessSize[i] < worstblockSize[y] and (worstblockSize[y] not in worstinserted) and worstblockSize[y] > maxblock):
            maxblock = worstblockSize[y]
            maxindex = y
            count = count + 1
    if(count == 0):
        f2.write(str(worstprocessSize[i]) + " => not allocated, must wait")
    else:
        worstblockSize.insert(maxindex+1, worstblockSize[maxindex] - worstprocessSize[i])
        worstblockSize[maxindex] = worstprocessSize[i]
        worstinserted.append(worstprocessSize[i])
        f2.write(str(worstprocessSize[i]) + " => ")
        yazdir2(worstblockSize, worstinserted)
        f2.write("\n")



f.close()
f2.close()

