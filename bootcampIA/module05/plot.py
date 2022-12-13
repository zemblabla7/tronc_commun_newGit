import numpy as np
from matplotlib import pyplot

def plot(x, y, theta):
    """Plot the data and prediction line from three non-empty numpy.array.
    Args:
    x: has to be an numpy.array, a vector of dimension m * 1.
    y: has to be an numpy.array, a vector of dimension m * 1.
    theta: has to be an numpy.array, a vector of dimension 2 * 1.
    Returns: Nothing.
    Raises: This function should not raise any Exceptions.
    """
    #pour afficher les points de x et y
    pyplot.scatter(x, y)

    #pour afficher notre droite (l'hypothèse)
    f = []
    m = len(x)
    for j in range (0, m) : #pas besoin de spécifier 0 / n est exclus donc va jusqu'à n - 1
        f.append(theta[1] * x[j] + theta[0])
    pyplot.plot(f, color='red')

    pyplot.show()

x = np.arange(1,6)
y = np.array([3.74013816, 3.61473236, 4.57655287, 4.66793434, 5.95585554])

theta1 = np.array([[4.5],[-0.2]])
plot(x, y, theta1)

theta2 = np.array([[-1.5],[2]])
plot(x, y, theta2)

theta3 = np.array([[3],[0.3]])
plot(x, y, theta3)