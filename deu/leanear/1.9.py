import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# ===== k 계산 =====
# 문제: 2 -5k -12 = 0
k = -2

print("k 값 =", k)

# ===== 벡터 정의 =====
u = (1, k, -3)
v = (2, -5, 4)

# ===== 그래프 =====
origin = (0, 0, 0)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 벡터 그리기
ax.quiver(*origin, *u)
ax.quiver(*origin, *v)

# 라벨
ax.text(*u, f'u = {u}')
ax.text(*v, f'v = {v}')

# 축 범위
ax.set_xlim([-5, 5])
ax.set_ylim([-5, 5])
ax.set_zlim([-5, 5])

# 축 이름
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# 제목
ax.set_title(f'Orthogonal Vectors (k = {k})')

# ===== 직교 확인 =====
dot_product = u[0]*v[0] + u[1]*v[1] + u[2]*v[2]
print("u · v =", dot_product)

plt.show()