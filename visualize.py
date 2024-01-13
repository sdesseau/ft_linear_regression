import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Charger les données depuis le fichier CSV
data = np.genfromtxt('theta.csv', delimiter=',')

# Extraire les colonnes theta0, theta1 et mse
theta0_vals = data[:, 0]
theta1_vals = data[:, 1]
mse_vals = data[:, 2]

# Afficher la surface de la fonction de coût
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_trisurf(theta0_vals, theta1_vals, mse_vals, cmap='viridis')

# Afficher les points du gradient
ax.scatter(theta0_vals, theta1_vals, mse_vals, color='red', marker='o')

ax.set_xlabel('Theta0')
ax.set_ylabel('Theta1')
ax.set_zlabel('MSE')

plt.show()