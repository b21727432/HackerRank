#!/usr/bin/env python
# coding: utf-8

# In[18]:


birimler = [200, 100, 50, 10, 5, 1, 0.50, 0.25, 0.05, 0.01]
para = int(input())
maxadet = [0,0,0,0,0,0,0,0,0,0]



for x in range(10):
    maxadet[x], kalan = divmod(para, birimler[x])

for birim in birimler:
    adet, para = divmod(para, birim) # divmoddan kaç adet olduğu, geriye kaç kaldığı dönüyor 
    if adet:
        print(adet,"adet", birim, "var")
        
maxadet


# Normal en az paralarla yapma mantığını, divmod fonksiyonu ile kurabildim. En çok kombinasyonu bulma kısmında ise recursive bir yol izlenebilir fakat mantığını tam olarak kuramadım.Çünkü kafamda kurduğum çözüm yaklaşık n^10 time complexitysinde çalışıyor.Daha efektif bir  yol olmalı.Mantık olarak ana paradan n*200 + m* 100 + y*50 + t * 20 ..... şeklinde bir fonksiyon kurulmalı ve tüm kombinasyonları bulmak için iterasyon yapılabilir.Zamanım az olduğu için yapamadım :(
