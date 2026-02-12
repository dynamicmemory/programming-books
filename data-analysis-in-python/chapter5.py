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

