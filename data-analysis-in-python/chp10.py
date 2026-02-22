import numpy as np 
import pandas as pd 

df = pd.DataFrame({"key1" : ["a", "a", None, "b", 'b','a', None],
                   "key2" : pd.Series([1,2,1,2,1,None,1], dtype="Int64"),
                   "data1" : np.random.standard_normal(7),
                   "data2" : np.random.standard_normal(7)})

print(df)

grouped = df["data1"].groupby(df["key1"])
means = df["data1"].groupby([df["key1"], df["key2"]]).mean()
print(grouped.mean())
print(means)


states = np.array(["OH", "CA", "CA", "OH", "OH", "CA", "OH"])
years = years = [2005,2005,2006,2005,2006,2005,2006]

df["data1"].groupby([states, years]).mean()

df.groupby("key1").mean()
# df.groupby("key2").mean()
df.groupby(["key1", "key2"]).mean()

df.groupby(["key1", "key2"]).size()

df.groupby("key1", dropna=False).size()

df.groupby("key1").count()


for name, group in df.groupby("key1"):
    print(name) 
    print(group) 

# for (k1,k2), group in df.groupby(["key1", "key2"]):
#     print((k1,k2))
    # print(group)

pieces = {name: group for name, group in df.groupby("key1")}
print(pieces)

df.groupby("key1")["data1"]

people = pd.DataFrame(np.random.standard_normal((5, 5)),
columns=["a", "b", "c", "d", "e"],
index=["Joe", "Steve", "Wanda", "Jill", "Trey"])


people.iloc[2:3, [1,2]] = np.nan

mapping = {'a':'red', 'b':'red','c':'blue','d':'blue','e':'red','f':'orange'}
by_column = people.groupby(mapping)
print(by_column.sum())
# by_column.sum()
#
#map_series = pd.Series(mapping)

print(people)
print(people.groupby(len).sum())

df = pd.DataFrame({"price": np.random.standard_normal(10),
                   "day": ['a','a','b','b','c','a','c','d','d','d']})

print(df.groupby("day").mean())



tips = pd.read_csv("./examples/tips.csv")
print(tips.head())






