import csv
import pandas as pd
import numpy as np
from sklearn.metrics import mean_squared_error
from sklearn.metrics import mean_absolute_error
from math import sqrt
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeRegressor
from sklearn.neural_network import MLPClassifier

train = []
test = []
with open('input.csv', 'r') as file:
    reader = csv.reader(file, delimiter = '\t')
    for row in reader:
        if row[0] == 'SampleNo':
            continue
        elif int(row[0]) >= 101:
            test.append(row)
        else:
            train.append(row)
for i in test:
    i.pop(0)
    i.pop(6)
for i in train:
    i.pop(0)
train = pd.DataFrame(train)
test = pd.DataFrame(test)

X = train.drop([6], axis=1)
Y = train[6]

X = X.astype(np.float)
Y = Y.astype(np.float)


model = LinearRegression()
model.fit(X, Y)

mse = mean_squared_error(Y, model.predict(X))
mae = mean_absolute_error(Y, model.predict(X))
print("mse = ",mse," & mae = ",mae," & rmse = ", sqrt(mse))


output = model.predict(test)
pd.DataFrame(output).to_csv('linearreg.csv', index=False, header=False)


model2 = LogisticRegression()
model2.fit(X, Y)

mse = mean_squared_error(Y, model2.predict(X))
mae = mean_absolute_error(Y, model2.predict(X))

print("mse = ",mse," & mae = ",mae," & rmse = ", sqrt(mse))


output2 = model2.predict(test)
pd.DataFrame(output2).to_csv('logisticreg.csv', index=False, header=False)



model3 = DecisionTreeRegressor()
model3.fit(X, Y)

mse = mean_squared_error(Y, model3.predict(X))
mae = mean_absolute_error(Y, model3.predict(X))
print("mse = ",mse," & mae = ",mae," & rmse = ", sqrt(mse))


output3 = model3.predict(test)
pd.DataFrame(output3).to_csv('desiciontree.csv', index=False, header=False)


model4 = MLPClassifier()
model4.fit(X, Y)

output4 = model4.predict(test)
pd.DataFrame(output4).to_csv('nn.csv', index=False, header=False)

mse = mean_squared_error(Y, model4.predict(X))
mae = mean_absolute_error(Y, model4.predict(X))
print("mse = ",mse," & mae = ",mae," & rmse = ", sqrt(mse))