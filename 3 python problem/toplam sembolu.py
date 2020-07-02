#!/usr/bin/env python
# coding: utf-8

# In[3]:


import math

print("A değerini hesaplamak için X değerini giriniz : ")
x = int(input())
A = 0
for n in range(1,x+1):
    A += (1/x) + math.sqrt(x)
print("Hesaplanan A değeriniz : " + str(A))


# In[ ]:




