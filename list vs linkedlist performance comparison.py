#!/usr/bin/env python
# coding: utf-8

# In[1]:


import collections
import time
import random

x = int(input())
y = int(input())

indexvalues = []
for i in range(y):
    indexvalues.append(random.randint(1,x))

datatime = []
linkedlisttime = []

data = []
linkedlist = collections.deque()
for i in range(x):
    randomone = random.randint(1, x)
    data.append(randomone)
    linkedlist.append(randomone)

for i in indexvalues:
    c = 0
    print("Sample ID " + str(c) + " Random Index: " + str(i))
    
    start_timedata = time.time()
    x = data[i]
    dtime = time.time() - start_timedata
    datatime.append(dtime)
    print("Array["+str(i)+"]"+" = "+ str(x))
    print("    Access time: " + str(dtime))
    start_timelinked = time.time()
    linkedlist.index(x)
    ltime = time.time() - start_timelinked
    linkedlisttime.append(ltime)
    print(str(i) + ". element in Linked List = " + str(x))
    print("    Access time: " + str(ltime))


# In[4]:


import matplotlib.pyplot as plt

plt.plot(linkedlisttime)
plt.plot(datatime)

plt.show()

# in this plot we can see that array acces time of list is always zero, this is because of 
# accessing using index which is o(1) in list example.However in linked list, when we want to access
# we go through elements one by one which is o(n) in general. Indexes are generated randomly so this is
# why we can see the spikes.


# In[3]:


plt.figure(figsize=(3, 5))

names = ["Array", "Linked List"]
times = [datatime[49], linkedlisttime[49]]

plt.bar(names, times)

plt.show()

# this is detailed plot as we see, array access time is 0 where linked list access time is 0.003.
# this can change depending on computers specs, python program


# In[ ]:




