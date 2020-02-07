import json
import os

def load_news(name):
    data = []
    with open(name, 'r') as f:
        data.append(f.readlines())
    return data


news = load_news('./2016-02.txt')

print(news[0:10])

alpha_table = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
               'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
               'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
               'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
               'W', 'X', 'Y', 'Z' ]

symbol_table = ['，', '。', '！', '？', '；', '、', '/', '（', '）', '——', '\'', '\"'] # + alpha_table
num_table    = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
 
forbidden_table = ['&','#','，', '。', '！', '？', '；', '、', '/', '（', 
                '）', '——', '\'', '“', '”', '【', '】'] #+ symbol_table + alp_table + num_table

