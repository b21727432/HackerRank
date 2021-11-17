import pandas as pd
df = pd.read_csv('veriler.csv')
print(df)
gecenler = []
kalanlar = []
for i in df.values:
    ortalama = i[2] * 40 / 100 + i[3] * 60 / 100
    if(ortalama >= 50):
        gecenler.append(i)
    else:
        kalanlar.append(i)
print("Gecen Ogrenciler : ")
for i in gecenler:
    print("Adı Soyadı: " + i[0] +" "+ i[1] + " Ortalaması " + str(i[2] * 40 / 100 + i[3] * 60 / 100))
kalanort = 0
for i in kalanlar:
    kalanort += i[2] * 40 / 100 + i[3] * 60 / 100
print("Kalan ogrencilerin not ortalaması : " + str(kalanort / len(kalanlar)))

print("Final notu vize notlarından büyük olan öğrenciler : ")
for i in df.values:
    if(i[3] > i[2]):
        print("Adı Soyadı: " + i[0] +" "+ i[1] +" Vize Notu " + str(i[2]) + " Final Notu " + str(i[3]) + " Ortalaması " + str(i[2] * 40 / 100 + i[3] * 60 / 100))





