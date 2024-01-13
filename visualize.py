# import numpy as np
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D

# # Charger les données depuis le fichier CSV
# data = np.genfromtxt('theta.csv', delimiter=',')

# # Extraire les colonnes theta0, theta1 et mse
# theta0_vals = data[:, 0]
# theta1_vals = data[:, 1]
# mse_vals = data[:, 2]

# # Afficher la surface de la fonction de coût
# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# ax.plot_trisurf(theta0_vals, theta1_vals, mse_vals, cmap='viridis')

# # Afficher les points du gradient
# ax.scatter(theta0_vals, theta1_vals, mse_vals, color='red', marker='o')

# ax.set_xlabel('Theta0')
# ax.set_ylabel('Theta1')
# ax.set_zlabel('MSE')

# plt.show()

import numpy as np
import matplotlib.pyplot as plt

# Charger les données depuis le fichier CSV (theta.csv)
data = np.genfromtxt('theta.csv', delimiter=',')

# Extraire les colonnes theta0, theta1 et mse
theta0_vals = data[:, 0]
theta1_vals = data[:, 1]
mse_vals = data[:, 2]

# Afficher la surface de la fonction de coût (Première fenêtre)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_trisurf(theta0_vals, theta1_vals, mse_vals, cmap='viridis')
ax.scatter(theta0_vals, theta1_vals, mse_vals, color='red', marker='o')
ax.set_xlabel('Theta0')
ax.set_ylabel('Theta1')
ax.set_zlabel('MSE')

# Afficher la première fenêtre
plt.show()

# Deuxième fenêtre
plt.figure(2)


# Charger les données depuis le fichier model.txt
model_data = np.genfromtxt('model.txt', delimiter=' ')

# Tracer la ligne représentée par les points dans le fichier model.txt
plt.plot(model_data[:, 0], model_data[:, 1], color='blue', marker='o', linestyle='-')


# Charger les données depuis le fichier CSV (autre fichier CSV par exemple)
other_data = np.genfromtxt('data.csv', delimiter=',')

# Tracer le contenu de la deuxième fenêtre (par exemple, scatter plot)
plt.scatter(other_data[:, 0], other_data[:, 1], color='green', marker='x')
plt.xlabel('X Axis Label')
plt.ylabel('Y Axis Label')

# Afficher la deuxième fenêtre
plt.show()
