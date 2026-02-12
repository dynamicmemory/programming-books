from warnings import warn
import numpy as np

my_arr = np.arange(1_000_000)
my_list = list(range(1_000_000))


data = np.array([[1.5, -0.1, 3, 4], [1, 0, -3, 6.5]])

print(f"dims {data.ndim}") 
print(f"shape {data.shape}") 

data1 = np.array([[1,2,3],[5,6,7]])

print(f"dtype 1 {data.dtype}")
print(f"dtype 2 {data1.dtype}")

zero = np.zeros(10)
zero1 = np.zeros((3,6))

print(zero1)

e = np.empty((2,3,4,4))
# print(e)

a = np.arange(15)
print(a)

a = np.ones((4,4))
print(a)
b = np.zeros_like(a)
print(b)

a = np.eye(3,3)
# b = np.identity(3,a)
print(a) 
# print(b)

a = np.array([1,2,3], dtype=np.float64)

a = np.array(["abc333","123","ooo"])
print(a, a.dtype)


a = np.array([1,2,3], dtype=np.float64)
b = a.astype(np.uint8)
print(f"a is {a.dtype}, b is {b.dtype}")

a = np.array([["1","2","3"], ["4","5","6"], ["7", "8", "9"]])
print(a.dtype)
a = a.astype(np.uint8)
print(a.dtype)

a = np.array([[1,2,3],[4,5,6]], dtype=np.float64)
a * a 
a - a 
print(1 / a)

print(a**2)

a = np.arange(10)
print(a)
a[4:9] = 12 
print(a)


a = np.array([[[1,2,3], [4,5,6]], [[7,8,9], [10,11,12]]])
print(a)
print(a[0])
print(a[0,1,1])

a = np.array([[1,2,3], [4,5,6], [7,8,9], [10,11,12]])
print(a[1, :2])

names = np.array(["Bob", "Joe", "Will", "Bob", "Will", "Joe", "Joe"])
data = np.array([[4,7], [0,2], [-5,6], [0,0], [1,2], [-12,-4], [3,4]])

print(data[names == "Bob"])

print(~(names == "Bob"))
cond = names == "Bob"
print(data[~cond])


def var(l, x):
    return l == x

mask = var(names, "Bob") | var(names, "Will")
data[mask]

print(data)
data[data < 0] = 0 
print(data)

z = np.zeros((4,4))
print(z)
for i in range(len(z)):
    z[i] = i 
print(z)

a = np.arange(15).reshape((3,5))
print(a) 
a = np.arange(15).reshape((-1,1))
print(a)
a = np.arange(15).reshape((-1,1))
print(a.T)

print(np.dot(a, a.T))
print(a @ a.T)


samples = np.random.standard_normal(size=(4,4))
print(samples)

from random import normalvariate 
N = 1_000_000

rng = np.random.default_rng(seed=1111)

x = rng.standard_normal(10)
y = rng.standard_normal(10)

print(x)
print(y)

np.maximum(x,y)

b = rng.standard_normal(10)
a = np.zeros_like(b)

np.add(b, 1, out=a)

import matplotlib.pyplot as plt 

points = np.arange(-5, 5, 0.01)
xs, ys = np.meshgrid(points,points)
z = np.sqrt(xs**2 + ys**2)

# plt.imshow(z, extent=[-5,5,-5,5])
# plt.colorbar()
# plt.title("Image plot of $\sqrt{x^2 + y^2}$ for a grid of values")
# plt.show()

x = np.array([1,2,3,4,5])
y = np.array([6,7,8,9,10])

cond = np.array([True, False, True, True, False])

result = np.where(cond, x, y)

print(result)


a = rng.standard_normal((4,4))
result = np.where(a > 0, 2, -2)
print(a)
print(result)

a = rng.standard_normal((5,5))

print(np.mean(a))
print(a.mean())

a.mean(axis=1)
a.mean(axis=0)

a = np.arange(15)
print(a.cumsum())

a = rng.standard_normal(100)
(a >= 0.7).sum()
(a < 0.7).sum()


names = np.array(["Bob", "Joe", "Will", "Bob", "Will", "Joe", "Joe"])
print(np.unique(names))

vals = np.array([66,4,2,4,5,5,6,9,8])
print(np.isin(vals, [3,2,5]))

a = np.arange(100)
np.save("some_array", a)
np.load("some_array.npy")
np.savez("array_archive.npz", a=a, b=b)

x=np.array([[1,2,3],[4,5,6]], dtype=np.float64)
y=np.array([[1,2],[4,5],[7,8]], dtype=np.float64)

print(x.dot(y))
print(np.dot(x,y))
print(x @ y)

print(x @ np.ones(3))

X = rng.standard_normal((3,3))
print(X)
mat = X.T @ X 
print(mat)
print(np.linalg.inv(mat))

print(mat@ np.linalg.inv(mat))

import random 

#! Block start 
position = 0 
walk = [position]
nsteps = 1000 
for _ in range(nsteps):
    step = 1 if random.randint(0, 1) else -1 
    position += step 
    walk.append(position)
plt.plot(walk)
# plt.show()

rng = np.random.default_rng(seed=808080)
draws = rng.integers(0,2, size=nsteps)
steps = np.where(draws == 0, 1, -1)
walk = steps.cumsum()

plt.plot(walk)
# plt.show()
print(walk.min())
print(walk.max())
print((np.abs(walk) >=10).argmax())


