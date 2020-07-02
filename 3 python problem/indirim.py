#!/usr/bin/env python
# coding: utf-8

# In[2]:


print("Birinci ürünün fiyatını giriniz : ")
birinciurun = int(input())
print("İkinci ürünün fiyatını giriniz : ")
ikinciurun = int(input())
print("Üçüncü ürünün fiyatını giriniz : ")
ucuncuurun = int(input())

toplam = birinciurun + ikinciurun + ucuncuurun

if(toplam < 100):
    print("Toplamınız 100TL den az olduğu için %10 indirim uygulanıyor...")
    print("Ödemeniz gereken miktar : " + str(toplam * 90 / 100) + "TL " + "Uygulanan İndirim : " + str(toplam * 10 / 100) + "TL")
elif(toplam >= 100 and toplam <= 200):
    print("Toplamınız 100TL ve 200TL arasında olduğu için %20 indirim uygulanıyor...")
    print("Ödemeniz gereken miktar : " + str(toplam * 80 / 100) + "TL " + "Uygulanan İndirim : " + str(toplam * 20 / 100) + "TL")
elif(toplam > 200):
    print("Toplamınız 250TL den fazla olduğu için %25 indirim uygulanıyor...")
    print("Ödemeniz gereken miktar : " + str(toplam * 75 / 100) + "TL " + "Uygulanan İndirim : " + str(toplam * 25 / 100) + "TL")


# In[ ]:




