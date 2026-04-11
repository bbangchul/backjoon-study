import numpy as np
import matplotlib.pyplot as plt

# 벡터 정의
u = np.array([1, 3, 4])
v = np.array([3, 4, 7])

# ===== cosθ 계산 =====
dot = np.dot(u, v)
norm_u = np.linalg.norm(u)
norm_v = np.linalg.norm(v)

cos_theta = dot / (norm_u * norm_v)

# 각도 (라디안 → 도)
theta = np.arccos(cos_theta)
theta_deg = np.degrees(theta)

print("cosθ =", cos_theta)
print("θ (degrees) =", theta_deg)

# ===== 3D 시각화 =====
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

origin = [0, 0, 0]

# 벡터 그리기
ax.quiver(*origin, *u)
ax.quiver(*origin, *v)

# 라벨
ax.text(*u, ' u')
ax.text(*v, ' v')

# 축 범위
ax.set_xlim([-10, 10])
ax.set_ylim([-10, 10])
ax.set_zlim([-10, 10])

# 축 이름
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# 제목에 cosθ 표시
ax.set_title(f'cosθ = {cos_theta:.3f}, θ ≈ {theta_deg:.2f}°')

plt.show()