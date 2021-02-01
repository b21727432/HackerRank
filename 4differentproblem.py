#!/usr/bin/env python
# coding: utf-8

# In[7]:


import random

liste = []
odd = 0
even = 0
oddcount = 0
evencount = 0
for i in range(1000):
    liste.append(random.randint(1,1000))
    if(liste[i] % 2 == 0):
        even += liste[i]
        evencount = evencount + 1
    else:
        odd += liste[i]
        oddcount = oddcount + 1
        
oddavg = odd / oddcount
evenavg = even / evencount
generalavg = (even + odd) / 1000

print("Odd sayilarin ortalaması : " + str(oddavg))
print("Even sayilarin ortalaması : " + str(evenavg))
print("Tum sayilarin ortalaması : " + str(generalavg))



# In[9]:


n = int(input("Enter n :"))
if(n == 0):
    print("None")
if(n < 0):
    print("Low")
if(n >= 0):
    if(n > 100):
        print("Out of range")
    if(n <= 100):
        if(n != 0):
            print("High")


# In[25]:


import random
hat = []
hat.append('red')
hat.append('red')
hat.append('red')
hat.append('blue')
hat.append('blue')
hat.append('blue')
hat.append('blue')
hat.append('blue')
hat.append('yellow')
hat.append('yellow')

redcount = 0
bluecount = 0
yellowcount = 0
for i in range(1000):
    color = random.choice(hat)
    if(color == 'red'):
        redcount = redcount + 1
    elif(color == 'blue'):
        bluecount = bluecount + 1
    elif(color == 'yellow'):
        yellowcount = yellowcount + 1
print("1000 atis sonrası gelen Red sayisi " + str(redcount) + " Blue sayisi : " + str(bluecount) + " Yellow sayisi : " + str(yellowcount))
redcount = 0
bluecount = 0
yellowcount = 0
for i in range(1000000):
    color = random.choice(hat)
    if(color == 'red'):
        redcount = redcount + 1
    elif(color == 'blue'):
        bluecount = bluecount + 1
    elif(color == 'yellow'):
        yellowcount = yellowcount + 1
print("1000000 atis sonrası gelen Red sayisi " + str(redcount) + " Blue sayisi : " + str(bluecount) + " Yellow sayisi : " + str(yellowcount))


# In[29]:


name = input("Enter your name")
age = int(input("Enter your age"))
print("Your name is " + name)
print("Your age is " + str(age))
s1 = name[0]
print(s1)
s2 = name[len(name) - 1]
print(s2)
s3 = []
for i in range(len(name)):
    s3.append(name[i])
s4 = []
for i in range(len(name)):
    if(i != 0 and i != len(name) - 1):
        s4.append(name[i])
list1 = [-10, 10, 5, 6, 7, -5]
list2 = []
for i in range(len(list1)):
    list2.append(list1[i])
x = 5
y = 10
z = 15
mid = 0
if(x > y and x > z):
    if(y > z):
         mid = y
    else:
        mid = z
elif(y > x and y > z):
    if(x > z):
         mid = x
    else:
        mid = z
elif(z > y and z > x):
    if(x > y):
         mid = x
    else:
        mid = y
list3 = []
for i in range(len(list1)):
    if(list1[i] > 0):
        list3.append(list1[i])


# In[28]:


raiserate = float(input("Raise rate girin %"))
currentsalary = float(input("Current salary girin"))

yenisalary = currentsalary * (100 + raiserate) / 100
print(yenisalary)

