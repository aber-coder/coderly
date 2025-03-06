# %%
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.multiclass import OneVsRestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

iris = datasets.load_iris()
X = iris.data
y = iris.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)

binary_classifier = LogisticRegression(max_iter=200)

ovr_classifier = OneVsRestClassifier(binary_classifier)

ovr_classifier.fit(X_train, y_train)

y_pred = ovr_classifier.predict(X_test)

# %%
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy of One-vs-Rest classifier: {accuracy * 100:.2f}%")


conf_matrix = confusion_matrix(y_test, y_pred)
print("Confusion Matrix:")
print(conf_matrix)

print("\nPredictions vs Actual labels:")
for i in range(5):
    print(f"Predicted: {y_pred[i]}, Actual: {y_test[i]}")


