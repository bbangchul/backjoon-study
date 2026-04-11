import sympy as sp

k = sp.symbols('k')

# 문제 1
expr1 = 1*2 + k*(-5) + (-3)*4
sol1 = sp.solve(expr1, k)

# 문제 2
expr2 = 2*6 + 3*k*(-1) + (-4)*3 + 1*7 + 5*(2*k)
sol2 = sp.solve(expr2, k)

print("문제1 k =", sol1)
print("문제2 k =", sol2)