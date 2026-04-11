import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# 벡터 정의
u1 = (-6, -6, -6)   # -6u1
u2 = (3, 6, 9)      # 3u2
u3 = (4, -2, 2)     # 2u3
v  = (1, -2, 5)     # 결과 벡터

# 원점
origin = (0, 0, 0)

# 그래프 생성
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 벡터 그리기
ax.quiver(*origin, *u1)
ax.quiver(*origin, *u2)
ax.quiver(*origin, *u3)
ax.quiver(*origin, *v)

# 라벨 표시
ax.text(*u1, ' -6u1')
ax.text(*u2, ' 3u2')
ax.text(*u3, ' 2u3')
ax.text(*v, ' v')

# 축 범위 설정
ax.set_xlim([-10, 10])
ax.set_ylim([-10, 10])
ax.set_zlim([-10, 10])

# 축 이름
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# 출력
plt.show()