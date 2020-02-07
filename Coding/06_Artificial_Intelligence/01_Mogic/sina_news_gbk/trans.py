
def transfer(filename):
    with open(filename, 'r', encoding='gbk') as f:
        print("success")
        s = f.read()
        # s[1354920] = '\xa3'
    print("fail")
    with open('./16_04_re.txt', 'w', encoding='utf-8') as file_temp:
        file_temp.write(s)

def main():
    transfer('./2016-04.txt')
    print("FINISH")

main()