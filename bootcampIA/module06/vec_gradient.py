import numpy as np

def simple_gradient(x, y, theta):
    """Computes a gradient vector from three non-empty numpy.array, without any for loop.
    The three arrays must have compatible shapes.
    Args:
    x: has to be a numpy.array, a matrix of shape m * 1.
    y: has to be a numpy.array, a vector of shape m * 1.
    theta: has to be a numpy.array, a 2 * 1 vector.
    Return:
    The gradient as a numpy.ndarray, a vector of dimension 2 * 1.
    None if x, y, or theta is an empty numpy.ndarray.
    None if x, y and theta do not have compatible dimensions.
    Raises:
    This function should not raise any Exception.
    """

    #gradient = (1/m) * x * 

    m = len(x)  
    w = 0
    b = 0
    
    for i in range(m):  
        f_wb = theta[1] * x[i] + theta[0]
        temp_w = (f_wb - y[i]) * x[i]
        temp_b = f_wb - y[i]
        b += temp_b
        w += temp_w
    w = w / m 
    b = b / m 
        
    print(b, w)
    return b, w


#soit on écrit "reshape" soit on utilise : transposed_X = x.transpose()
x = np.array([12.4956442, 21.5007972, 31.5527382, 48.9145838, 57.5088733]).reshape((-1, 1))
y = np.array([37.4013816, 36.1473236, 45.7655287, 46.6793434, 59.5585554]).reshape((-1, 1))

# Example 1:
theta1 = np.array([2, 0.7]).reshape((-1, 1))
simple_gradient(x, y, theta1)
# Output:
# array([[-19.0342...], [-586.6687...]])

# Example 2:
theta2 = np.array([1, -0.4]).reshape((-1, 1))
simple_gradient(x, y, theta2)
# Output:
# array([[-57.8682...], [-2230.1229...]])

