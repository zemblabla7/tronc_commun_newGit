import numpy as np
import matplotlib.pyplot as plt

#x and y for straight lines (formula: 𝑓𝑤,𝑏(𝑥(𝑖))=𝑤𝑥(𝑖)+𝑏)

# x_train is the input variable (size in 1000 square feet)
# y_train is the target (price in 1000s of dollars)
x_train = np.array([1.0, 2.0])
y_train = np.array([300.0, 500.0])
print(f"x_train = {x_train}") #python f-string print format https://docs.python.org/3/tutorial/inputoutput.html
print(f"y_train = {y_train}")

# m is the number of training examples
m = len(x_train) #or m = x_train.shape[0]
print(f"Number of training examples is: {m}")

#to print the ith element of the lists x and y
i = 0 # Change this to 1 to see (x^1, y^1)
x_i = x_train[i]
y_i = y_train[i]
print(f"(x^({i}), y^({i})) = ({x_i}, {y_i})")

#to show the graph (regression line between the two points) : scatter() in the matplotlib library
# Plot the data points
plt.scatter(x_train, y_train, marker='x', c='r') #marker & c show the points as red crosses (the default is blue dots)
# Set the title
plt.title("Housing Prices")
# Set the y-axis label
plt.ylabel('Price (in 1000s of dollars)')
# Set the x-axis label
plt.xlabel('Size (1000 sqft)')
plt.show()

#------------------------------------------------------------------
#w and b for different straight lines
w = 200 #on choisit les valeurs à la mano, en essayant des valeurs jusqu'à ce qu'elles fit les deux croix
b = 100
print(f"w: {w}")
print(f"b: {b}")

#to compute the value of 𝑓𝑤,𝑏(𝑥(𝑖)) for the data points
def compute_model_output(x, w, b):
    """
    Computes the prediction of a linear model
    Args:
      x (ndarray (m,)): Data, m examples 
      w,b (scalar)    : model parameters  
    Returns
      y (ndarray (m,)): target values
    """
    m = x.shape[0]
    f_wb = np.zeros(m) #np.zero(n) will return a one-dimensional numpy array with 𝑛 entries
    for i in range(m):
        f_wb[i] = w * x[i] + b
        
    return f_wb
#(ndarray (m,)) describes a Numpy n-dimensional array of shape (m,). 
#(scalar) describes an argument without dimensions, just a magnitude.

#to show the graph
tmp_f_wb = compute_model_output(x_train, w, b,)

# Plot our model prediction
plt.plot(x_train, tmp_f_wb, c='b',label='Our Prediction')

# Plot the data points
plt.scatter(x_train, y_train, marker='x', c='r',label='Actual Values')

# Set the title
plt.title("Housing Prices")
# Set the y-axis label
plt.ylabel('Price (in 1000s of dollars)')
# Set the x-axis label
plt.xlabel('Size (1000 sqft)')
plt.legend()
plt.show()

#to print the house price prediction:
w = 200                         
b = 100    
x_i = 1.2 #house of 1200 sqft.
cost_1200sqft = w * x_i + b    

print(f"${cost_1200sqft:.0f} thousand dollars")