#!/usr/bin/env python
# coding: utf-8

# In[1]:


class Ogrenci:
    def __init__(self, ad, soyad, numara, notu):
            self.ad = ad
            self.soyad = soyad
            self.numara = numara
            self.notu = notu
    def ogrencinin_durumu(self):
        try:
            if(self.notu > 90):
                print("A")
            elif(self.notu > 80 and self.notu < 90):
                print("B")
            elif(self.notu > 70 and self.notu < 80):
                print("C")
            else:
                print("Ders Tekrarı")
        except:
            print("Not Hesaplanamadı")


# In[2]:


import math

class Ucgen:
    def __init__(self, kenar1, kenar2, kenar3):
        self.kenar1 = kenar1
        self.kenar2 = kenar2
        self.kenar3 = kenar3
    
    def set(self, kenar1, kenar2, kenar3):
        self.kenar1 = kenar1
        self.kenar2 = kenar2
        self.kenar3 = kenar3
        
    def ucgen_tipi(self):
        
        try:
            if(self.kenar1 < self.kenar2 + self.kenar3 and self.kenar1 > self.kenar2 + self.kenar3 and self.kenar2 < self.kenar1 + self.kenar3 and self.kenar2 > self.kenar1 + self.kenar3 and self.kenar3 < self.kenar2 + self.kenar1 and self.kenar3 > self.kenar2 + self.kenar1):
                if(self.kenar1 != self.kenar2 and self.kenar1 != self.kenar3):
                    print("cesitkenar ucgen")
                elif(self.kenar1 == self.kenar2 and self.kenar1 == self.kenar3):
                    print("eskenar ucken")
                elif((self.kenar1 == self.kenar2 and self.kenar1 != self.kenar3) or (self.kenar1 == self.kenar3 and self.kenar1 != self.kenar2) or (self.kenar2 == self.kenar3 and self.kenar2 != self.kenar1)):
                    print("ikizkenar")
                elif((math.sqrt(self.kenar1**2 + self.kenar2**2) == self.kenar3) or (math.sqrt(self.kenar1**2 + self.kenar3**2) == self.kenar2) or (math.sqrt(self.kenar2**2 + self.kenar3**2) == self.kenar1)):
                    print("dik ücgen")
            else:
                print("Ucgen degil")
        except:
            print("Ucgen Sınıfı çalışmadı")
        
                
        
        
        


# In[3]:


class Ders:
    def __init__(self, ders_ismi, ogrenci_sayisi, tur):
        if(type(ders_ismi) != str):
            raise ValueError("Ders ismi icin bir string girmelisiniz")
        else:
                self.ders_ismi = ders_ismi
        if(type(ogrenci_sayisi) != int):
            raise ValueError("Ogrenci sayisi icin bir string girmelisiniz")
        else:
            self.ogrenci_sayisi = ogrenci_sayisi
        if(type(tur) != str):
            raise ValueError("Tür icin bir string girmelisiniz")
        else:
            if(tur != "Secmeli" and tur != "Zorunlu"):
                raise ValueError("Yanlis Tür Girdiniz")
            else:
                print("Ders Bilgisi Başarıyla Girildi")
                self.tur = tur
    def __len__(self):
         return self.ogrenci_sayisi


# In[4]:


class Bolum:
    def __init__(self, bolum_ismi):
        print("Bölüm Bilgisi Başarıyla Girildi")
        self.bolum_ismi = bolum_ismi
        self.sozluk = {}
        
    def ders_ekle(self, ders):
        print("Ders Bölüme Başarıyla Eklendi")
        if(self.sozluk):
            self.sozluk["Ders Adı"].append(ders.ders_ismi)
            self.sozluk["Öğrenci Sayısı"].append(ders.ogrenci_sayisi)
            self.sozluk["Tür"].append(ders.tur)
        else:
            self.sozluk = {"Ders Adı":[ders.ders_ismi], "Öğrenci Sayısı":[ders.ogrenci_sayisi], "Tür":[ders.tur]}
        
        
    
    def bölüm_bilgisi(self):
        print(self.sozluk)


# In[5]:


yeni_ders = Ders("Bilgisayar Programlama",80,"Zorunlu")


# In[6]:


bölümler = Bolum("Elektrik-Elektronik")


# In[7]:


bölümler.ders_ekle(yeni_ders)


# In[8]:


bölümler.bölüm_bilgisi()


# In[9]:


yeni_ders = Ders("Matematik",40,"Secmeli")


# In[10]:


bölümler.ders_ekle(yeni_ders)


# In[11]:


bölümler.bölüm_bilgisi()


# In[12]:


len(yeni_ders)


# In[14]:


yeni_ders = Ders("Matematik", 40, "Normal Ders")


# In[ ]:




