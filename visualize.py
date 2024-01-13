import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt('theta.csv', delimiter=',')

theta0_vals = data[:, 0]
theta1_vals = data[:, 1]
mse_vals = data[:, 2]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_trisurf(theta0_vals, theta1_vals, mse_vals, cmap='viridis')
ax.scatter(theta0_vals, theta1_vals, mse_vals, color='red', marker='o')
ax.set_xlabel('Theta0')
ax.set_ylabel('Theta1')
ax.set_zlabel('MSE')

plt.show()

plt.figure(2)

model_data = np.genfromtxt('model.txt', delimiter=' ')

plt.plot(model_data[:, 0], model_data[:, 1], color='blue', marker='o', linestyle='-')

other_data = np.genfromtxt('data.csv', delimiter=',')

plt.scatter(other_data[:, 0], other_data[:, 1], color='green', marker='x')
plt.xlabel('X Axis Label')
plt.ylabel('Y Axis Label')

plt.show()
