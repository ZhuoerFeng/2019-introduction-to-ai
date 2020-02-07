import sys
import math

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
    with open(filename, 'r') as f:
        s = f.readline()
        for i in range(0, len(s)):
            charid[s[i]] = i
    

def load_mydict(filename):
    global mydict
    with open(filename, 'r') as f:
        entries = map(lambda s: compact(s.split(' ')), f.readlines())
        for entry in entries:
            mydict[entry[0]] = entry[1:]
    
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

def init():
    load_charid('01_pinyin/src/characters.txt')
    load_mydict('01_pinyin/src/dictionary.txt')
    load_data()

def translate(sentence):
    f = []
    g = []
    candidates = []
    
    for item in sentence:
        candidates.append(mydict[item])
        f.append([-1e9] * len(candidates[-1]))
        g.append([0] * len(candidates[-1]))

    n = len(f)

    for i in range(n):
        m = len(f[i])
        if i == 0:
            for j in range(m):
                cid = charid[candidates[i][j]]
                t1 = freq_1.get(cid)
                if t1:
                    f[i][j] = math.log(t1)
        else:
            m_prev = len(f[i - 1])
            for j in range(m):
                cid = charid[candidates[i][j]]
                for k in range(m_prev):
                    cid_prev = charid[candidates[i - 1][k]]
                    t1 = freq_1.get(cid_prev)
                    t2 = freq_2.get((cid_prev, cid))
                    if t1 and t2:
                        p = f[i - 1][k] + math.log(t2) - math.log(t1)
                        if p > f[i][j]:
                            f[i][j] = p
                            g[i][j] = k

    result = []
    now_i = n - 1
    now_j = 0
    for j in range(len(f[now_i])):
        if f[now_i][j] > f[now_i][now_j]:
            now_j = j
    
    max_p = f[now_i][now_j]
    result.append(candidates[now_i][now_j])
    while now_i > 0:
        now_j = g[now_i][now_j]
        now_i -= 1
        result.append(candidates[now_i][now_j])
    result.reverse()
    return result, max_p

"""
params
[
    "a",
    "a",
    "a",
]

returns
[
    ([], 0.xx),
    ([], 0.xx),
]
"""

def compact(arr):
    result = []
    for item in arr:
        if item.strip():
            result.append(item.strip())
    return result

def main():
    if len(sys.argv) != 3:
        print('usage: pinyin [input_file] [output_file]')
        sys.exit(1)
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    with open(input_file, 'r') as f:
        sentences = map(lambda s: compact(s.split(' ')), f.readlines())
    with open(output_file, 'w') as f:
        for sentence in sentences:
            solution = translate(sentence)
            f.write('%s\n' % ''.join(solution[0]))

if __name__ == '__main__':
    init()
    main()
