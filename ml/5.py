import numpy as np 
import matplotlib.pyplot as plt 
from sklearn import datasets 
from sklearn.model_selection import train_test_split 
from sklearn.linear_model import LogisticRegression 
from sklearn.metrics import mean_squared_error 
from sklearn.preprocessing import PolynomialFeatures 
from sklearn.pipeline import make_pipeline 

iris = datasets.load_iris() 
X = iris.data[:, :2]  # Use only the first two features for simplicity 
y = iris.target 

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42) 

def plot_bias_variance(): 
    degrees = np.arange(1, 11) 
    train_errors = [] 
    test_errors = [] 

    for degree in degrees: 
        model = make_pipeline(PolynomialFeatures(degree), LogisticRegression(max_iter=200)) 
        model.fit(X_train, y_train) 
        y_train_pred = model.predict(X_train) 
        y_test_pred = model.predict(X_test) 
        train_error = mean_squared_error(y_train, y_train_pred) 
        test_error = mean_squared_error(y_test, y_test_pred) 
        train_errors.append(train_error) 
        test_errors.append(test_error) 

    plt.figure(figsize=(8, 6)) 
    plt.plot(degrees, train_errors, label='Training Error (Bias)', color='blue', marker="o") 
    plt.plot(degrees, test_errors, label='Test Error (Variance)', color='red', marker="o") 
    plt.xlabel("Model Complexity (Polynomial Degree)") 
    plt.ylabel('Mean Squared Error') 
    plt.title('Bias-Variance Tradeoff') 
    plt.legend() 
    plt.grid(True) 
    plt.show() 

plot_bias_variance()
