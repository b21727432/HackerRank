#!/usr/bin/env python
# coding: utf-8

price = []

while True:
    print("IF YOU WANT TO QUIT PRESS q")
    x = input("Enter a Stock Price: ")
    if x == 'q':
        break
    x = int(x)
    price.append(x)

print(price)
print("Prices that falls constantly are : "  + str(priceFallsConstantly(price)))
print("Maximum Profit is : " + str(maximumProfit(price)))

def maximumProfit(price):
    maxProfit = 0;
    #priceları teker teker gez
    for i in range(0, len(A)):
        #suanki pricedan ilerisini gezme loopu
        for j in range (i + 1, len(A)):
            potentialMaxProfit = A[j] - A[i]
            # önceki ile buldugumuzu karsılastırıyoruz daha karlıysa bunu seciyoruz
            if(potentialMaxProfit > maxProfit):
                maxProfit = potentialMaxProfit
    if(maxProfit == 0):
        return "no profit in one unit"
    
    return maxProfit


def priceFallsConstantly(l):
    l1 = []
    length = len(l)
    for i in range(0,length-1,1):
        check = True
        for j in range(i+1,length,1):
            if l[i] < l[j]:
                check = False
        if check:
            l1.append(l[i])

    l1.append(l[-1])
    return l1




