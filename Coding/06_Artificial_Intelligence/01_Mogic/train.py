import re

charid = {}
mydict = {}

freq_1 = {}
freq_2 = {}
freq_3 = {}

def compact(arr):
    result = []
    for item in arr:
        if item.strip():
            result.append(item.strip())
    return result

def load_charid(filename):
    global charid
    with open(filename, 'r', encoding='utf-8') as f:
        s = f.readline()
        for i in range(0, len(s)):
            charid[s[i]] = i

def load_mydict(filename):
    global mydict
    with open(filename, 'r') as f:
        entries = map(lambda s: compact(s.split(' ')), f.readlines())
        for entry in entries:
            mydict[entry[0]] = entry[1:]

h = []

def upd():
    global freq_1, freq_2, freq_3
    if not freq_1.get(h[-1]):
        freq_1[h[-1]] = 0
    freq_1[h[-1]] += 1
    if len(h) > 1:
        if not freq_2.get((h[-2], h[-1])):
            freq_2[(h[-2], h[-1])] = 0
        freq_2[(h[-2], h[-1])] += 1
        if len(h) > 2:
            if not freq_3.get((h[-3], h[-2], h[-1])):
                freq_3[(h[-3], h[-2], h[-1])] = 0
            freq_3[(h[-3], h[-2], h[-1])] += 1

def add_corpus():  #update freq_1
    pass
    """
        1. global once read, once update 
        char <-
        dict <- freq_1 prev
    """

def load_corpus_single(filename):
    global h
    with open(filename, 'r', encoding='gbk') as f:
        matches = f.readlines()
    counter = 0
    for s in matches:
        counter += 1
        print(counter)
        if (counter > 10000): 
            break

        L = len(s)
        i = 0
        h = []
        while i < L:
            if i < L:
                j = charid.get(s[i])
                if not j is None:
                    h.append(j)
                    i += 1
                    upd()
                else:
                    h = []
                    i += 1
            else:
                break

def gaota(fuck):
    gu = []
    for (key, value) in fuck.items():
        if isinstance(key, int):
            key = [key]

        gu += list(key)
        gu.append(value)
    return ' '.join(map(lambda x : str(x), gu))

def load_data():
    print("load data")
    global freq_1, freq_2, freq_3

    with open('./01_pinyin/src/freq_1.txt', 'r') as file1:
        dic1 = file1.readline().split(" ")
        for i in range(0, len(dic1), 2):
            freq_1[int(dic1[i])] = int(dic1[i + 1])

    with open('./01_pinyin/src/freq_2.txt', 'r') as file2:
        dic2 = file2.readline().split(" ")
        for i in range(0, len(dic2), 3):
            freq_2[int(dic2[i]), int(dic2[i + 1])] = int(dic2[i + 2])

    with open('./01_pinyin/src/freq_3.txt', 'r') as file3:
        dic3 = file3.readline().split(" ")
        for i in range(0, len(dic2), 4):
            freq_3[int(dic3[i]), int(dic3[i + 1]), int(dic3[i + 2])] = int(dic3[i + 3])

    print(str(freq_1))
    print(str(freq_2))
        


def output():
    with open('./01_pinyin/src/freq_1.txt', 'w') as file1:
        file1.write(gaota(freq_1))
    with open('./01_pinyin/src/freq_2.txt', 'w') as file2:
        file2.write(gaota(freq_2))
    with open('./01_pinyin/src/freq_3.txt', 'w') as file3:
        file3.write(gaota(freq_3))

def load_corpus(filenames):
    for filename in filenames:
        load_corpus_single(filename)
    output()

load_charid('./01_pinyin/src/characters.txt')
load_mydict('./01_pinyin/src/dictionary.txt')

load_corpus([
    'sina_news_gbk/2016-02.txt'
])

load_data()

"""
[
    [sina_news_loader, [
        "2016-01.txt",
    ]
]
"""