#!/usr/bin/env python
# coding: utf-8

# In[62]:


def postfix(s):

    n=len(s)

    stack =[]

    for i in range(n):

        if type(s[i]) == int:
          #append function is equivalent to push

            stack.append(int(s[i]))

        elif (s[i]=="+"):

            a=stack.pop()

            b=stack.pop()
            stack.append(int(b)+int(a))

        elif (s[i]=="**"):

            a=stack.pop()

            b=stack.pop()
            stack.append(pow(int(b),int(a)))

        elif (s[i]=="%"):
            
            a=stack.pop()

            b=stack.pop()
            stack.append(int(b) % int(a))
          
    return stack.pop()


# In[65]:


print(postfix([1, 2, 3,5, "+", "**", "%"]))


# In[ ]:




