#!/usr/bin/env python
# coding: utf-8

# In[12]:


def satisfactory(filename):
    satirlar = []
    with open(filename) as f:
        satirlar = f.readlines()
    gecenler = 0    
    for i in satirlar:
        i = i.split()
        final = int(i[0]) * 5 / 100
        final += int(i[1]) * 5 / 100
        final += int(i[2]) * 25 / 100
        final += int(i[3]) * 25 / 100
        final += int(i[4]) * 40 / 100
        if(final >= 60):
            gecenler += 1
    return gecenler


# In[13]:


satisfactory("input.txt")

