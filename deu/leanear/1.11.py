import numpy as np
import matplotlib.pyplot as plt

u = np.array([3, -4])
u_hat = u / np.linalg.norm(u)

origin = [0, 0]

plt.figure()

plt.quiver(*origin, *u, angles='xy', scale_units='xy', scale=1)
plt.quiver(*origin, *u_hat, angles='xy', scale_units='xy', scale=1)

plt.text(u[0], u[1], ' u')
plt.text(u_hat[0], u_hat[1], ' u_hat')

plt.xlim(-5, 5)
plt.ylim(-5, 5)

plt.axhline(0)
plt.axvline(0)

plt.gca().set_aspect('equal')

plt.title('Vector Normalization')

plt.show()