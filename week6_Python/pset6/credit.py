from cs50 import get_int,get_string

def main():
    n = get_string("Number: ")

    # a = check(n)
    # print(a)
    # print(n[0:2])

    if check(n) and (len(n)==13 or len(n)==16) and int(n[0])==4:
        print("VISA")
    elif check(n) and len(n)==15 and (int(n[0:2])==34 or int(n[0:2])==37):
        print("AMEX")
    elif check(n) and len(n)==16 and (int(n[0:2])==51 or int(n[0:2])==55):
        print("MASTERCARD")
    else:
        print("INVALID")


def check(n):
    alter = n[::-1]
    sum1 = 0
    sum2 = 0
    cont = 0

    for i in alter:
        if cont%2 == 1:
            if int(i)>=5:
                sum1 = sum1 + int(str(int(i)*2)[0]) + int(str(int(i)*2)[1])
            else:
                sum1 = sum1 + int(i)*2
        else:
            sum2 = sum2 + int(i)
        cont = cont+1

    if (sum1+sum2)%10 ==0:
        return True
    else:
        return False

main()