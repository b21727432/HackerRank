#!/usr/bin/env python
# coding: utf-8

# In[53]:


bahceler=['A','B','C','D','E']
baglantilar=[('A','B'),('E','A'),('D','B')]
baslangic='C'


# In[54]:


visited = []
yenibaglantilar = []
visited.append(baslangic)
count = 0
visitAll(bahceler, baslangic, baglantilar, visited)
print(visited)
print(count)
print(yenibaglantilar)
visited = []
yenibaglantilar = []
count = 0
dfs(bahceler, baslangic, baglantilar, visited)
print(count)
print(yenibaglantilar)


# In[1]:


# bu optimal olmayan ilk yazdığım fonksiyon, genel olarak dfs mantıgında calısıyor, visited kontrol edip yol varsa yol ile yoksa normal ilerliyor
def visitAll(bahceler, baslangic, baglantilar, visited):
    global count
    for a in bahceler: # dfs mantıgında komsuları arasında bir iterasyon
        if a not in visited: # tekrar ziyaret etmemek için
            if (baslangic, a) not in baglantilar:
                yenibaglantilar.append((baslangic, a))
                visited.append(a)
                count = count + 1
                visitAll(bahceler, a, baglantilar, visited)
            else:
                visited.append(a)
                yenibaglantilar.append((baslangic, a))
                visitAll(bahceler, a, baglantilar, visited)


# In[49]:


#sonraki hedefi seçmek için kurduğum bir mantık eğer 2 node'a komşuluk varsa oraya gidebilri diye düşündüm
def nextDest(baglantilar, visited):
    count = 0
    for (x,y) in baglantilar:
        for(z,t) in baglantilar:
            if(x == t):
                if z not in visited:
                    return z
    if(count == 0):
        return 0


# In[52]:


#güncellenmiş dfs fonksiyonu, karar verip bağlantıları kontrol ediyor, bağlantı varsa masraf olmadan yoksa masraflı bir biçimde karşıya geçiyor
def dfs(bahceler, baslangic, baglantilar, visited):
    global count
    if baslangic not in visited:
        visited.append(baslangic)
        # burda karar verme kısmında baglantilara bakıp ona göre karar verilmeli
        where = nextDest(baglantilar, visited)
        if(where != 0):
            if(baslangic, where) not in baglantilar:
                yenibaglantilar.append((baslangic, where))
                count = count + 1
                dfs(bahceler, where, baglantilar, visited)
            else:
                dfs(bahceler, where, baglantilar, visited)
        else:
            for a in bahceler:
                if a not in visited:
                    if(baslangic, a) not in baglantilar:
                        yenibaglantilar.append((baslangic, a))
                        count = count + 1
                        dfs(bahceler, a, baglantilar, visited)
                    else:
                        dfs(bahceler, a, baglantilar, visited)


# Burda dfs ile bir döngü yapmak istedim fakat burda bizden istenen daha az yolla yapılması, DFS ise bu mantığa göre çalışmıyor. DFS 'e ek olarak önceki bağlantıları kontrol edip bu bağlantılar üzerinden bir yol bulan bir algoritma yazılmalı.
# 
# 
# Genel olarak düşündüğüm şeyler : başlangıçtan visited listesi ile gezdiğim nodeları tutmak, nodeları uğradıgımda hangi nodea gitmesi için genel bir mantık oluşturmaya çalıştım.Karar verdikten sonra önceden yol varsa count arttırmadan, yol yoksa yol olışturup count arttırıp o node'a git.
