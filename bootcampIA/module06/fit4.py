import numpy as np
from vec_gradient import simple_gradient
#from module05.prediction import predict_

# Linear Gradient Descent

def fit_(x, y, theta, alpha, max_iter):
	"""
	Description:
	Fits the model to the training dataset contained in x and y.
	Args:
	x: has to be a numpy.ndarray, a vector of dimension m * 1: (number of training examples, 1).
	y: has to be a numpy.ndarray, a vector of dimension m * 1: (number of training examples, 1).
	theta: has to be a numpy.ndarray, a vector of dimension 2 * 1.
	alpha: has to be a float, the learning rate
	max_iter: has to be an int, the number of iterations done during the gradient descent
	Returns:
	new_theta: numpy.ndarray, a vector of dimension 2 * 1.
	None if there is a matching dimension problem.
	Raises:
	This function should not raise any Exception.
	"""

	b = theta[0]
	w = theta[1]
	for i in range(max_iter):
		gradient = simple_gradient(x, y, theta)
		g_b = gradient[0]
		g_w = gradient[1]
		b = b - alpha * g_b
		w = w - alpha * g_w
		#print(f"b: {b}, w: {w}, gb: {g_b}, gw: {g_w}")
	print(b, w)


x = np.array([[12.4956442], [21.5007972], [31.5527382], [48.9145838], [57.5088733]])
y = np.array([[37.4013816], [36.1473236], [45.7655287], [46.6793434], [59.5585554]])
theta = np.array([1.0, 1.0]).reshape((-1, 1)) #et non array([1, 1]) car si int au lieu de float ça ne marche pas!

#Exemple 1:
theta1 = fit_(x, y, theta, alpha=5e-8, max_iter=1500000)
# theta1
	# Output:
	# array([[1.40709365],
	# [1.1150909 ]])

# Example 2:
# predict_(x, theta1)
	# Output:
	# array([[15.3408728 ],
	# [25.38243697],
	# [36.59126492],
	# [55.95130097],
	# [65.53471499]])

