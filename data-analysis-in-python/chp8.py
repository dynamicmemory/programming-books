import pandas as pd 
import numpy as np 

data = pd.Series(np.random.uniform(size=9),
                 index=[["a", "a", "a", "b", "b", "c", "c", "d", "d"],
                 [1, 2, 3, 1, 3, 1, 2, 2, 3]])

print(data)
print(data.index)
print(data.unstack())

frame = pd.DataFrame(np.arange(12).reshape((4, 3)),
                     index=[["a", "a", "b", "b"], [1, 2, 1, 2]],
                     columns=[["Ohio", "Ohio", "Colorado"],
                     ["Green", "Red", "Green"]])

print(frame)
frame.index.names = ["key1", "key2"]
frame.columns.names = ["state", "color"]

print(frame)

frame = pd.DataFrame({"a": range(7), "b": range(7, 0, -1),
 "c": ["one", "one", "one", "two", "two",
 "two", "two"],
 "d": [0, 1, 2, 0, 1, 2, 3]})


print(frame)

df1 = pd.DataFrame({"key": ["b", "b", "a", "c", "a", "a", "b"],
 "data1": pd.Series(range(7), dtype="Int64")})
df2 = pd.DataFrame({"key": ["a", "b", "d"],
 "data2": pd.Series(range(3), dtype="Int64")})

pd.merge(df1, df2)

pd.merge(df1, df2, on="key")
pd.merge(df1,df2, how="outer")


df1 = pd.DataFrame({"key": ["b", "b", "a", "c", "a", "b"],
 "data1": pd.Series(range(6), dtype="Int64")})
df2 = pd.DataFrame({"key": ["a", "b", "a", "b", "d"],
 "data2": pd.Series(range(5), dtype="Int64")})

print(pd.merge(df1,df2, on="key", how="left"))

print(pd.merge(df1,df2, how="outer"))


left2 = pd.DataFrame([[1., 2.], [3., 4.], [5., 6.]],
      index=["a", "c", "e"],
      columns=["Ohio", "Nevada"]).astype("Int64")
right2 = pd.DataFrame([[7., 8.], [9., 10.], [11., 12.], [13, 14]],
      index=["b", "c", "d", "e"],
      columns=["Missouri", "Alabama"]).astype("Int64")

print(left2.join(right2, how="outer"))

