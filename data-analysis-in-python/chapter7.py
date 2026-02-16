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
# 7.4 - string methods 

import re 

text = "foo      bar\t bax   \tqux"
re.split(r"\s+", text)

regex = re.compile(r"\s+")
regex.split(text) 
regex.findall(text)

rng = np.random.default_rng(122)
rng.standard_normal(10)


text = """Dave dave@google.com
Steve steve@gmail.com
Rob rob@gmail.com
Ryan ryan@yahoo.com"""
pattern = r"[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}"

regex = re.compile(pattern, flags=re.IGNORECASE)
regex.findall(text)

m = regex.search(text)
print(regex.match(text))

print(regex.sub("REDACTED", text))

pattern = r"([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\.([A-Z]{2,4})"
regex = re.compile(pattern, flags=re.IGNORECASE)

m = regex.match("wesm@bright.net")
m.groups()

print(regex.findall(text))

print(regex.sub(r"Username: \1, Domain: \2, Suffix: \3", text))


data = {"Dave": "dave@google.com", "Steve": "steve@gmail.com",
        "Rob": "rob@gmail.com", "Wes": np.nan}

data = pd.Series(data)
print(data)
data.isna()

data =data.astype("string")
print(data.str.contains("gmail"))

print(data.str.findall(pattern, flags=re.IGNORECASE))

matches = data.str.findall(pattern, flags=re.IGNORECASE).str[0]
print(matches)

print(matches.str.get(1))


print(data.str.extract(pattern, flags=re.IGNORECASE))


# 7.6 categorical data
values = pd.Series(["apple", "orange", "apple", "apple"] * 2)

print(values)

pd.unique(values)

values = pd.Series([0,1,0,0] * 2)
dim = pd.Series(["apple", "orange"])

print(dim.take(values))

fruits = ["apple", "orange", "apple", "apple"]*2 
N = len(fruits)
rng = np.random.default_rng(seed=12345)

df = pd.DataFrame({'fruit': fruits,
 'basket_id': np.arange(N),
 'count': rng.integers(3, 15, size=N),
 'weight': rng.uniform(0, 4, size=N)},
 columns=['basket_id', 'fruit', 'count', 'weight'])

fruit_cat = df["fruit"].astype("category")
c = fruit_cat.array 
type(c)

my_cats = pd.Categorical(["foo", "bar", "bax", "foo", "bar"])
categories = ["foo", "baz", "bar"]
codes = [0,1,2,0,0,1]
my_cats_2 = pd.Categorical.from_codes(codes, categories)

print(my_cats_2)


rng = np.random.default_rng(seed=12345)
draws = rng.standard_normal(1000)
draws[:5]

bins = pd.qcut(draws, 4)
print(bins)

bins= pd.qcut(draws, 4, labels=["Q1","Q2","Q3","Q4"])
bins = pd.Series(bins, name="quartile")
result = (pd.Series(draws).groupby(bins).agg(["count", "min", "max"]).reset_index())
print(result)

# N = 10_000_000
# labels = pd.Series(["foo", "bar", "baz", "qux"] * (N // 4))
# print(labels)
#
# categories = labels.astype("category")
#
#
#
#
s = pd.Series(['a','b','c','d']*2)
cat_s = s.astype("category")
cat_s.cat.categories

print(cat_s)
print(cat_s.value_counts())

actual_categories = ['a','b','c','d','e']
cat_s2 = cat_s.cat.set_categories(actual_categories)
print(cat_s2)
print(cat_s2.value_counts())


cat_s = pd.Series(['a', 'b', 'c', 'd'] * 2, dtype='category')
print(pd.get_dummies(cat_s))
