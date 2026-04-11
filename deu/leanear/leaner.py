import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection


# input Data
print("A의 좌표를 입력하시오")
A = np.array(list(map(float, input().split())))
print("B의 좌표를 입력하시오")
B = np.array(list(map(float, input().split())))
print("C의 좌표를 입력하시오")
C = np.array(list(map(float, input().split())))
print("D의 좌표를 입력하시오")
D = np.array(list(map(float, input().split())))
print("E의 좌표를 입력하시오")
E = np.array(list(map(float, input().split())))

# 방향벡터
u = B - A
v = C - A

# 삼각형의 법선 벡터
n = np.cross(u, v)

# 직선 DE의 방향 벡터
d = E - D

# 평행 여부 확인
denom_t = np.dot(n, d)

intersection_point = None
intersects = False

if denom_t == 0:
    print("직선이 삼각형의 평면과 평행하거나 평면 위에 있습니다.")

else:
    # 평면식에 직선식을 대입
    t = np.dot(n, (A - D)) / denom_t

    # 직선의 방정식으로 교점 구하기
    p = D + t * d

    if 0 <= t <= 1:
        # barycentric coordinate 계산
        w = p - A

        uu = np.dot(u, u)
        uv = np.dot(u, v)
        vv = np.dot(v, v)
        wu = np.dot(w, u)
        wv = np.dot(w, v)

        denom_bary = uu * vv - uv * uv

        alpha = (vv * wu - uv * wv) / denom_bary
        beta = (uu * wv - uv * wu) / denom_bary
        gamma = 1 - alpha - beta

        if alpha >= 0 and beta >= 0 and gamma >= 0:
            print("t =", t)
            print("교점 p =", p)
            print("alpha =", alpha)
            print("beta =", beta)
            print("gamma =", gamma)
            print("선분 DE는 삼각형 ABC와 교차함")
            intersection_point = p
            intersects = True
        else:
            print("p는 삼각형 밖에 있음")
            print("선분 DE는 삼각형 ABC와 교차하지 않음")

    else:
        print("교점이 선분 DE 밖에 있음")
        print("삼각형과 교점 없음")

# 3D 시각화
fig = plt.figure(figsize=(9, 7))
ax = fig.add_subplot(111, projection='3d')

# 삼각형 면
tri = Poly3DCollection([[A, B, C]], alpha=0.3, facecolor='cyan', edgecolor='blue', linewidth=1.5)
ax.add_collection3d(tri)

# 삼각형 꼭짓점
for point, label in zip([A, B, C], ['A', 'B', 'C']):
    ax.scatter(*point, color='blue', s=60, zorder=5)
    ax.text(*point, f'  {label}', color='blue', fontsize=11, fontweight='bold')

# 선분 DE
ax.plot(*zip(D, E), color='red', linewidth=2, label='line DE')
for point, label in zip([D, E], ['D', 'E']):
    ax.scatter(*point, color='red', s=60, zorder=5)
    ax.text(*point, f'  {label}', color='red', fontsize=11, fontweight='bold')

# 교점
if intersection_point is not None:
    color = 'green' if intersects else 'orange'
    label = f'intersection point P (intersection {"O" if intersects else "X"})'
    ax.scatter(*intersection_point, color='green', s=120, zorder=6, label='intersection point P')
    ax.text(*intersection_point, '  P', color='green', fontsize=11, fontweight='bold')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('intersection check for a triangle')
ax.legend()
plt.tight_layout()
plt.show()