#!/usr/bin/env python
# coding: utf-8

# In[10]:


import random
import time
import string
f = open("metin.txt", "w")
for i in range(3):
    randoms = []
    for i in range(100):
        randoms.append(random.choice(string.ascii_letters))
    for i in randoms:
        f.write(i + " ")
    time.sleep(2)


# In[18]:


fr = open("metin.txt", "r")
index = []
for i in fr:
    i = i.split(" ")
    for j in range(50):
        index.append(i[j + 100])
randomtext = []
for i in range(45):
    randomtext.append(''.join(random.choices(index, k=10)))
print(randomtext)


# In[ ]:




