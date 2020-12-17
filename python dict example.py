#!/usr/bin/env python
# coding: utf-8

# In[13]:


def employee_info(string1, string2):
    string1 = string1.split(",")
    string2 = string2.split(",")
    listofdict = []
    a = 0
    for i in string1:
        record = {}
        i = i.split()
        
        i[1] = i[1].upper()
        
       
        record["Name"] = string2[a]
        record["Surname"] = i[1]
        record["Age"] = int(i[2])
        record["Position"] = i[3]
        record["Employment Time"] = int(i[4])
        
        listofdict.append(record)
        a = a + 1
    
    return listofdict
        
        


# In[14]:


employee_info("Arthur tReLAwY 36 CEO 10, Josiah MaRsToN 43 CEO 12, John mOrgAN 33 Bookkeeper 8", "Josiah, John, Arthur")


# In[7]:


def employee_info(string1, string2):
    string1 = string1.split(",")
    string2 = string2.split(",")
    listofdict = []
    a = 0
    for i in string1:
        record = {}
        i = i.split()
        
        i[0] = i[0].lower()
        i[0] = i[0].title()
       
        record["Name"] = i[0]
        record["Surname"] = string2[a]
        record["Age"] = i[2]
        record["Position"] = i[3]
        record["Employment Time"] = i[4]
        
        listofdict.append(record)
        a = a + 1
    
    return listofdict


# In[15]:


def employee_info(x, y):
    x = x.split(",")
    y = y.split(",")
    mylist = []
    for i in range(len(x)):
        output = {}
        x[i] = x[i].split()
        
        x[i][0] = x[i][0].lower()
        x[i][0] = x[i][0].title()
       
        output["Name"] = x[i][0]
        output["Surname"] = y[i]
        output["Age"] = int(x[i][2])
        output["Position"] = x[i][3]
        output["Employment Time"] = int(x[i][4])
        
        mylist.append(output)
    
    return mylist


# In[16]:


employee_info("aRTHur TRELAWY 36 CEO 10, JoSiAh MARSTON 43 CEO 12, jOHn MORGAN 33 Bookkeeper 8", "MORGAN, TRELAWY, MARSTON")


# In[ ]:




