import matplotlib.pyplot as plt
import numpy as np
import sklearn
import sklearn.datasets
import sklearn.linear_model
import matplotlib
from sklearn.metrics import confusion_matrix

def plot_decision_boundary(pred_func):
    # Set min and max values and give it some padding
    x_min, x_max = X[:, 0].min() - .5, X[:, 0].max() + .5
    y_min, y_max = X[:, 1].min() - .5, X[:, 1].max() + .5
    h = 0.01
    # Generate a grid of points with distance h between them
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
    # Predict the function value for the whole gid
    Z = pred_func(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    # Plot the contour and training examples
    plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap=plt.cm.Spectral)


np.random.seed(0)
X, y = sklearn.datasets.make_moons(1000, noise=0.20)
plt.scatter(X[:,0], X[:,1], s=40, c=y, cmap=plt.cm.Spectral)

import pandas as pd
import seaborn as sn

clf = sklearn.linear_model.LogisticRegressionCV()
clf.fit(X, y)

plot_decision_boundary(lambda x: clf.predict(x))
plt.title("Logistic Regression")

df_cm = pd.DataFrame(confusion_matrix(y, clf.predict(X)), index = [i for i in "01"],
                  columns = [i for i in "01"])
plt.figure(figsize = (10,7))
sn.heatmap(df_cm, annot=True)

Xtest, ytest = sklearn.datasets.make_moons(200, noise=0.20)

df_cm = pd.DataFrame(confusion_matrix(ytest, clf.predict(Xtest)), index = [i for i in "01"],
                  columns = [i for i in "01"])
plt.figure(figsize = (10,7))
sn.heatmap(df_cm, annot=True)

result = clf.predict(Xtest)
total = 0
for i in range(200):
    if (ytest[i] == result[i]):
        total = total + 1

print(total / 200)
