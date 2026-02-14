import pandas as pd 
import numpy as np 

pd.options.display.max_rows = 10 

df = pd.read_csv("./examples/ex1.csv")
print(df)

names = ["a", 'b', 'c', 'd', "message"]
df = pd.read_csv("./examples/ex2.csv", names=names, index_col="message")
print(df)

parsed = pd.read_csv("./examples/csv_mindex.csv", index_col=["key1","key2"])
print(parsed)

result = pd.read_csv("./examples/ex3.txt", sep="\s+")
print(result)

result = pd.read_csv("./examples/ex5.csv", na_values=["NULL"])
print(result)

result = pd.read_csv("./examples/ex5.csv", keep_default_na=False)
print(result)

result = pd.read_csv("./examples/ex6.csv")
print(result)

chunker = pd.read_csv("./examples/ex6.csv", chunksize=1000)

tot = pd.Series([], dtype='int64')
for piece in chunker:
    tot = tot.add(piece["key"].value_counts(), fill_value=0)
tot = tot.sort_values(ascending=True)

# data = pd.read_csv("./example/ex5.csv")
# data.to_csv("./examples/out.csv")

# import sys 

# data.to_csv(sys.stdout, sep='|', na_rep="NULL")

import csv 
f= open("./examples/ex7.csv")
reader = csv.reader(f)
for line in reader:
    print(line)
f.close()

with open("./examples/ex7.csv") as f:
    lines = list(csv.reader(f))
    header, values = lines[0], lines[1:]

    print(values)
    data_dict = {h: v for h, v in zip(header, zip(*values))}

    df = pd.DataFrame(data_dict)
    print(df)



import json 

obj = """
{"name": "Wes",
"cities_lived": ["Akron", "Nashville", "New York", "San Francisco"],
"pet": null,
"siblings": [{"name": "Scott", "age": 34, "hobbies": ["guitars", "soccer"]},
{"name": "Katie", "age": 42, "hobbies": ["diving", "art"]}]
}
"""

result = json.loads(obj)
print(type(result)) 

data = pd.DataFrame(result["siblings"])
print(data)

df = pd.read_json("./examples/example.json")
print(df)

df.to_json("./examples/out.json")


tables = pd.read_html("./examples/fdic_failed_bank_list.html")
print(tables)

failures = tables[0]
close_timestamps = pd.to_datetime(failures["Closing Date"])
print(close_timestamps.dt.year.value_counts())


from lxml import objectify

path = "./datasets/mta_perf/Performance_MNR.xml"

with open(path) as f:
    parsed = objectify.parse(f)

    root = parsed.getroot()

    data = []
    skipped = ["PARENT_SEQ", "INDICATOR_SEQ", "DESIRED_CHANGE", "DECIMAL_PLACES"]

    for elt in root.INDICATOR:
        el_data = {}
        for child in elt.getchildren():
            if child.tag in skipped:
                continue 
            el_data[child.tag] = child.pyval
        data.append(el_data)

    perf = pd.DataFrame(data)
    print(perf)

perf2 = pd.read_xml(path)
print(perf2)

# 6.2 Binary Data Formats

frame = pd.read_csv("./examples/ex1.csv")
frame.to_pickle("./examples/frame_pickle")

frame = pd.read_pickle("./examples/frame_pickle")
print(frame)

frame = pd.DataFrame({"a": np.random.standard_normal(100)})


# 6.3 Interacting with Web APIs

import requests 

url = "https://api.github.com/repos/pandas-dev/pandas/issues"
resp = requests.get(url)
resp.raise_for_status()

data = resp.json()
print(data[0]["title"])

# issues = pd.DataFrame(data, columns=["number", "title","labels","state"])
# print(issues)

# 6.4 Interacting with Databases

import sqlite3 

query = """
    CREATE TABLE test 
    (a VARCHAR(20), b VARCHAR(20), 
     c REAL, d INTEGER
     );"""

con = sqlite3.connect("mydata.sqlite")
# con.execute(query)
# con.commit()

data = [("Alanta", "georgia", 1.23, 6),
        ("Tallahassee","florida", 2.6, 3),
        ("Sacramento", "california", 1.7, 5)]

stmt = "INSERT INTO test VALUES(?,?,?,?)"

con.executemany(stmt, data)
con.commit()

cursor = con.execute("SELECT * FROM test")
rows = cursor.fetchall()
print(rows)

print(cursor.description)

df = pd.DataFrame(rows, columns=[x[0] for x in cursor.description])
print(df)

import sqlalchemy as sqla 

db = sqla.create_engine("sqlite:///mydata.sqlite")
data = pd.read_sql("SELECT * FROM test", db)
print(data)






















