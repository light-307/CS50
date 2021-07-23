from cs50 import get_int,get_string

def main():
    n = get_string("Text: ")

    l, space, d = 0, 0, 0  # 分别统计字母、空格、句子个数
    for i in n:
        if i.isalpha():
            l = l + 1
        elif i == ' ':
            space = space + 1
        elif i=='.' or i=='!' or i=='?':
            d = d + 1

    result = 0.0588 * l/(space+1)*100 - 0.296 * d/(space+1)*100 - 15.8

    if result<1:
        print("Before Grade 1")
    elif result>=16:
        print("Grade 16+")
    else:
        print("Grade " + str(round(result)))




main()