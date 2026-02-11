from datetime import datetime, date, time 

dt = datetime(2011, 10, 29, 20, 30, 21)

print(dt.day)
print(dt.minute)

print(dt.date())
print(dt.time())

print(dt.strftime("%Y-%m-%d %H:%M"))


from collections import defaultdict

words = ["apple", "bat", "bar", "atom", "book"]

by_letter = defaultdict(list)
for word in words:
    by_letter[word[0]].append(word)


a = {1,2,3,4,5,6}
b = {5,6,7,8,9,10}

print(a|b)
print(a&b)

strings = ["a", "as", "bat", "car", "dove", "python"]

loc_mapping = {value: index for index, value in enumerate(strings)}



import re 

def clean_strings1(strings:list) -> list:
    result: list = []
    for val in strings:
        val = val.strip()
        val = re.sub("[!#?]", "", val)
        val = val.title()
        result.append(val)
    return result


def remove_punctuation(val:str) -> str:
    return re.sub("[!#?]", "", val)

clean_ops = [str.strip, remove_punctuation, str.title]

def clean_strings(strings: list, ops: list) -> list:
    res = []
    for val in strings:
        for func in ops:
            val = func(val)
        res.append(val)
    return res


def short(x):
    return x * 2 

equiv = lambda x: x*2 

def apply_to_list(some_list:list, f) -> list:
    return [f(x) for x in some_list]

ints = [1,2,3,4,5,6]
apply_to_list(ints, lambda x:x*2)

strings.sort(key=lambda x: len(x))



def squares(n=10):
    for i in range(1, n+1):
        yield i ** 2 

g = squares()

for x in g:
    print(x, end="")


import itertools

def first_letter(x):
    return x[0]

names = ["Alan", "Adam", "Wes", "Will", "Albert", "Steven"]

for letter, names in itertools.groupby(names, first_letter):
    print(letter, list(names))




def attempt_float(x):
    try:
        return float(x)
    except (ValueError, TypeError):
        return x 


path = "../examples/segismundo.txt"
f = open(path, encoding="utf-8")

for line in f:
    print(line)

f.close()











