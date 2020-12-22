#!/usr/bin/env python
# coding: utf-8

# In[77]:


def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2 
    
    if l > n and arr[i] > arr[l]:
        largest = l
    
    if r > n and arr[largest] > arr[r]:
        largest = r
    
    if largest != i:
        arr = list(arr)
        arr[i],arr[largest] = arr[largest],arr[i]
        arr = tuple(array)
        heapify(arr, n, largest)
    return arr

def insert(array, newNum, infos):
    size = len(array)
    if size == 0:
        array = list(array)
        array.append((newNum, infos))
        array = tuple(array)
        return array
    else:
        array = list(array)
        array.append((newNum,infos));
        array = tuple(array)
        for i in range((size//2)-1, -1, -1):
            array = heapify(array, size, i)
        return array

def deleteNode(array):
    
    
    array = list(array)
    array.pop(1) 
    array = tuple(array)
    
    for i in range((len(array)//2)-1, -1, -1):
        array = heapify(array, len(array), i)
    return array
    
arr = []

x = [("I 3 7 3 12-7"), ("I 1 3 5 326"), ("I 2 5 4 4-44"),("L"), ("G"), ("L"), ("I 4 6 4 -512"), ("L"), ("G"), ("L"), ("G"), ("L")]
for i in x:
    #bosluklarla gelen satırı ayırıp heap yapımıza eklememize yarıyor
    i = i.split(" ")
    if(i[0] == "I"):
        # eger I harfi gelirse heap'e ekleme işlemi yapıyoruz
        arr = insert(arr, (int(i[2])), i[1] + i[2] + i[3] + i[4])
    elif(i[0] == "G"):
        # heapin başından poplayıp devam ediyoruz
        arr = deleteNode(arr)
    elif(i[0] == "L"):
        # elde olanları yazdırıyoruz
        for a in arr:
            print(a[1])
        print("-----------")


# In[ ]:




