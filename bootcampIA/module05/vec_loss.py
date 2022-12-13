import numpy as np

def loss_(y, y_hat):
    """Computes the half mean squared error of two non-empty numpy.array, without any for loop.
    The two arrays must have the same dimensions.
    Args:
    y: has to be an numpy.array, a vector.
    y_hat: has to be an numpy.array, a vector.
    Returns:
    The half mean squared error of the two vectors as a float.
    None if y or y_hat are empty numpy.array.
    None if y and y_hat does not share the same dimensions.
    Raises:
    This function should not raise any Exceptions.
    """
    # deux lignes en dessous sont fausses par contre ça m'affiche bcp de points,je pense que ça me sert à afficher la ligne de vec_loss sur un graph
    # J = ((1/(2*len(y)) * (y_hat * y)) * (y_hat * y))
    # print(J)

    J = 0
    for i in range(len(y)) :
        J = J + ((1/(2*len(y)) * (y_hat[i] - y[i])) * (y_hat[i] - y[i]))
    print(float(J))
    

Y = np.array([[0], [15], [-9], [7], [12], [3], [-21]])
Ŷ = np.array([[2], [14], [-13], [5], [12], [4], [-19]])
# Example 1:
loss_(Y, Ŷ) # Output: 2.142857142857143
# Example 2:
loss_(Ŷ, Ŷ) # Output: 0.0


