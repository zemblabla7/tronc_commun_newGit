def gradient(self, x, y):
	res = np.c_[np.ones(len(x)), x] @ self.thetas
	res -= y
	res = np.c_[np.ones(len(x)), x].transpose() @ res
	return res / len(y)

class MyLinearRegression():
	"""
	Description:
	My personnal linear regression class to fit like a boss.
	"""
	def __init__(self, thetas, alpha=0.001, max_iter=1000):
		self.alpha = alpha
		self.max_iter = max_iter
		self.thetas = thetas

	def fit_(self, x, y):
		for i in range(self.max_iter):
			self.thetas -= self.alpha * gradient(self, x, y)
		return self.thetas

	def predict_(self, x): #reprend le self.thetas de fit
		f = []
		for j in range (len(x)) :
			f.append(self.thetas[1] * x[j] + self.thetas[0])
		return f

	def loss_elem_(self, y, y_hat):
		'''other losses. Ex05 module05'''

	def loss_(self, y, y_hat):
		'''Computes the half mean squared error of two non-empty numpy.array'''
		J = 0
		for i in range(len(y)) :
			J = J + ((1/(2*len(y)) * (y_hat[i] - y[i])) * (y_hat[i] - y[i]))
		#return float(J)
		return float(J)



# import numpy as np
# from my_linear_regression import MyLinearRegression as MyLR
# x = np.array([[12.4956442], [21.5007972], [31.5527382], [48.9145838], [57.5088733]])
# y = np.array([[37.4013816], [36.1473236], [45.7655287], [46.6793434], [59.5585554]])
# lr1 = MyLR(np.array([[2], [0.7]]))

# lr1.fit_(x, y)

# y_hat = lr1.predict_(x)
# 		# Output:
# 		array([[10.74695094],
# 		[17.05055804],
# 		[24.08691674],
# 		[36.24020866],
# 		[42.25621131]])

# lr1.loss_(y, y_hat)
# 		# Output:
# 		195.34539903032385
