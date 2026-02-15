import pandas as pd 
import numpy as np 

# 7.1 - Handling missing data 

df = pd.Series([1,2,np.nan,3,np.nan,0], dtype=np.float64)
print(df.isna())
df = df.dropna()
print(df)

df = pd.DataFrame([[1,2,3],[np.nan,5,6],[np.nan,np.nan,np.nan],[10,11,12]])
print(df)
print(df.dropna())
print(df.dropna(axis=1, how="all"))

df = pd.DataFrame(np.random.standard_normal((7,3)))
df.iloc[:4,1] = np.nan
df.iloc[:2,2] = np.nan 
print(df)
print(df.dropna(thresh=2))
# df = df.fillna({1: 0.5, 2: 0})
df = df.fillna(df.iloc[:, :].mean())
print(df)


# 7.2 - Data Transformation 

data = pd.DataFrame({"k1":["one","two"] * 3 + ["two"],
                     "k2": [1,1,2,3,3,4,4,]})
print(data.duplicated())
print(data)

data = pd.DataFrame({"food": ["bacon", "pulled pork", "bacon", "pastrami", 
                    "corned beef", "bacon", "pastrami", "honey ham", "nova lox"],
                    "ounces": [4,3,12,6,7.5,8,3,5,6]})

meat_to_animal = {"bacon": "pig", 
                  "pulled pork": "pig",
                  "pastrami": "cow",
                  "corned beef": "cow",
                  "honey ham": "pig",
                  "nova lox": "salmon",
                  }

print(data)
data["animal"] = data["food"].map(meat_to_animal)
print(data)

data = pd.Series([1,-999,2,-1000,3], dtype=np.float64)
data.replace(-999, np.nan)
data.replace([-999,1000], np.nan)

data = pd.DataFrame(np.arange(12).reshape((3,4)),
                    index=["Ohio", "Colorado", "NY"], 
                    columns=["one","two","three","four"])

data.index = data.index.map(lambda x: x[:4].upper())
print(data)

new = data.rename(index=str.title, columns=str.upper)
print(new)

ages = [20, 22, 25, 27, 21, 23, 37, 31, 61, 45, 41, 32]
bins = [18, 25, 35, 60, 100]

age_categories = pd.cut(ages, bins)
print(age_categories)

# print(age_categories.codes)
# print(age_categories.categories)
# print(age_categories.categories[0])
# print(pd.value_counts(age_categories))

group_names = ["Youth", "YoungAdult", "MiddleAged", "Senior"]

pd.cut(ages, bins, labels=group_names)

data = np.random.uniform(size=20)
data = pd.cut(data, 4, precision=2)
print(data)

data  = np.random.standard_normal(1000)
quartiles = pd.qcut(data, 4, precision=2)

data = pd.DataFrame(np.random.standard_normal((1000,4)))
print(data.describe())

col = data[2]
print(data[(data.abs() > 3).any(axis="columns")])


df = pd.DataFrame(np.arange(5*7).reshape((5,7)))

sampler = np.random.permutation(5)
print(sampler)
print(df.take(sampler))

df = pd.DataFrame({"key": ["b", "b", "a", "c", "a", "b"], "data1": range(6)})

print(df)
print(pd.get_dummies(df["key"]))

dummies = pd.get_dummies(df["key"], prefix="key")
df_w_dummies = df[["data1"]].join(dummies)
print(df_w_dummies)

mnames = ["movie_id", "title", "genres"]
movies = pd.read_table("./datasets/movielens/movies.dat", sep="::",
                       header=None, names=mnames, engine="python")

print(movies)
dummies = movies["genres"].str.get_dummies("|")
print(dummies.iloc[:10, :6])

movies_windic = movies.join(dummies.add_prefix("Genre_"))
print(movies_windic.iloc[0])

# 7.3 - Extentions Data Types





