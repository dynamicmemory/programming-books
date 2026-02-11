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

