import pandas as pd 
import numpy as np 
from pandas import Series, DataFrame 

obj = Series([4,7,-3,5])
# print(obj)

obj = Series([4,3,5,11], index=["d","b","a","c"])
print(obj)

print(obj[['a','b','c']])

sdata = {"open": 35000, "high": 71000, "low": 16000, "close": 5000}
obj3 = Series(sdata)
print(obj3)

obj3.to_dict

ohlc = Series(sdata, index=["vol", "open", "high", "low"])
print(ohlc)

print(pd.isna(ohlc))
print(pd.notna(ohlc))
print(ohlc.isna())
print(ohlc.notna())

print(obj3 + ohlc)

asset = np.array(("BTC", "BTC", "BTC", "ETH", "ETH", "ETH"))
year = np.array((2020,2021,2022,2021,2022,2023))
open = np.array((23000,54000,10100,1000,1500,3200))

df = DataFrame({"asset":asset,"year":year,"open":open})
print(df)

df.head()
df.tail()

print(DataFrame(df, columns=["open","asset","year", "close"]))
df.columns

df["year"]
df.year


print(df.loc[1])
print(df.iloc[1])

df["close"] = np.array((6 * df["open"]))
print(df)


print(df.T)
df.T
df = df.to_numpy()
print(df)

labels = np.arange(5)
df = Series([4,3,2,1,0], index=labels)
print(labels)
print(df.index)
print(df.index is labels)

obj = Series([4.5,7.2,-5.3, 3.6], index=['d','b','a','c'])
obj.reindex(['a','b','c','d'])

obj = Series(["blue", "purple","yellow"], index=[0,3,10])
print(obj)
obj = obj.reindex(np.arange(20), method="ffill")
print(obj)

obj = Series(np.arange(5), index=['a','b','c','d','e'])
print(obj)
obj.drop('c')
obj.drop(['c','d'])

data = DataFrame(np.arange(16).reshape((4,4)), index=["Ohio","Colorado","Utah","NY"],
                 columns=["one","two","three","four"])

print(data)
data.drop(index=["Colorado", "Ohio"])
data = data.drop("one", axis=1)
print(data)

obj = Series(np.arange(4, dtype=np.float64), index=['a','b','c','d'])
print(obj)
print(obj['b'])
print(obj[obj < 2])

print(obj.loc[['b']])

obj1 = Series([1,2,3], index=[2,0,1])
obj2 = Series([1,2,3], index=['a','b','c'])

print(obj1.loc[[0,1]])
print(obj2.loc[['a']])

print(obj2.iloc[[0]])

data = DataFrame(np.arange(16).reshape((4,4)),
                 index=["Ohio", "Colorado", "Utah", "NY"],
                 columns=["one", "two","three","four"])

print(data[["three","one"]])
print(data[:2])

print(data[data['three'] > 5])

data[data < 5] = 0
print(data)

print(data.loc[["Colorado","NY"],["two","three"]])

print(data.iloc[[2, 1]])

s1 = DataFrame([7.3,-2.5,3.4,1.5], index=['a','c','d','e'])
s2 = DataFrame([-2.1,3.6,-1.5,4,3.1], index=['a','c','e','f','g'])

print(s1 + s2)

df1 = DataFrame(np.arange(12).reshape((3,4)), columns=list("abcd"))
df2 = DataFrame(np.arange(20).reshape((4,5)), columns=list("abcde"))

df2.loc[1,'b'] = np.nan 

print(df1)
print(df2)
print(df1 + df2)
print(df1.add(df2, fill_value=0))
print(df2.add(df1, fill_value=0))

arr = np.arange(12).reshape((3,4))
arr[0]
print(arr - arr[0])












frame = DataFrame(np.arange(12).reshape((4,3)), columns=list("bde"),
                  index=["Utah","Colorado","Miami","NY"])

series = frame.iloc[0]
series2 = Series(np.arange(3), index=["b","e","f"])

print(frame - series)
print(frame + series2)


frame = DataFrame(np.random.standard_normal((4,3)),
                  columns=list("bde"), 
                  index=["Utah", "Ohio", "Texas", "Oregon"])

print(np.abs(frame))

print(frame)
frame2 = frame.apply(lambda x: x.max() - x.min(), axis="columns")
print(frame2)

# framef = frame.apply(lambda x: f"{x:.2f}")
# print(framef)

frame = DataFrame(np.arange(16).reshape((4,4)), 
                  index=["q","f","d","e"], 
                  columns=["one", "two", "three", "four"])
frame.sort_values
print(frame.sort_index(axis=0, ascending=False))
print(frame.one.sort_values(ascending=False))

df = DataFrame([[1.4, np.nan], [7.1, -4.5], [np.nan, np.nan], [0.75, -1.3]],
               index=["a","b","c","d"], columns=["one","two"])

print(df)
print(df.sum())
print(df.sum(axis=1))

print(df.sum(axis=1, skipna=False))
print(df.mean(axis=1))


print(df.idxmax())

# import sys
# import pandas.core.indexes
# sys.modules['pandas.indexes'] = pandas.core.indexes
#
# import pandas as pd
#
# price = pd.read_pickle("./examples/yahoo_price.pkl")
# volume = pd.read_pickle("./examples/yahoo_volume.pkl")
#
# returns = price.pct_change()
# print(returns.tail())



obj = Series(["c","a",'d','a','a','b','b','c','c'])
print(obj.unique())
print(obj.value_counts())

mask = obj.isin(['b','c'])
obj[mask]

data =DataFrame({"a":[1,1,1,2,2], "b":[0,0,1,0,0]})
print(data)
print(data.value_counts())











