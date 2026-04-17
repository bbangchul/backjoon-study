import numpy as np
import matplotlib.pyplot as plt

# =========================
# 부분공간 S = {(x, y, z) in R^3 | x = y}
# 즉 x = y 인 점들의 집합
# =========================

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# 평면 x = y 를 그리기 위한 데이터 생성
t = np.linspace(-3, 3, 20)   # x=y 값
z = np.linspace(-3, 3, 20)   # z 값
T, Z = np.meshgrid(t, z)

X = T
Y = T   # x = y 조건

# 부분공간 평면 그리기
ax.plot_surface(X, Y, Z, alpha=0.4)

# 원점 표시
ax.scatter(0, 0, 0, s=80)
ax.text(0, 0, 0, '  O(0,0,0)', fontsize=11)

# 평면 위의 벡터 2개 (기저 역할)
# S의 모든 벡터는 a(1,1,0) + b(0,0,1) 꼴로 표현 가능
v1 = np.array([1, 1, 0])
v2 = np.array([0, 0, 1])

ax.quiver(0, 0, 0, v1[0], v1[1], v1[2], arrow_length_ratio=0.1, linewidth=2)
ax.quiver(0, 0, 0, v2[0], v2[1], v2[2], arrow_length_ratio=0.1, linewidth=2)

ax.text(v1[0], v1[1], v1[2], '  (1,1,0)', fontsize=11)
ax.text(v2[0], v2[1], v2[2], '  (0,0,1)', fontsize=11)

# 평면 위의 임의의 점 몇 개 표시
points = np.array([
    [1, 1, 2],
    [-2, -2, 1],
    [2, 2, -1],
    [-1, -1, -2]
])

ax.scatter(points[:, 0], points[:, 1], points[:, 2], s=50)
for p in points:
    ax.text(p[0], p[1], p[2], f'  ({p[0]},{p[1]},{p[2]})', fontsize=9)

# 축 라벨
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')

# 보기 좋게 범위 설정
ax.set_xlim(-3, 3)
ax.set_ylim(-3, 3)
ax.set_zlim(-3, 3)

ax.set_title(r'Subspace in $\mathbb{R}^3$: $S = \{(x,y,z)\mid x=y\}$')

plt.show()