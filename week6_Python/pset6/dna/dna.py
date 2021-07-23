import sys
import csv
import numpy as np


def main():

    # Check for correct number of args
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database = sys.argv[1] if len(sys.argv) == 3 else "databases/large.csv"
    txtdir = sys.argv[2] if len(sys.argv) == 3 else "sequences/10.txt"

    # the database "rows"
    csvfile = open(database, 'r')
    reader = csv.reader(csvfile)
    rows = [row for row in reader]
    csvfile.close()

    # the "txt"
    txtfile = open(txtdir, 'r')
    txt = txtfile.read()
    txtfile.close()


    strnum = np.zeros((len(rows[0])-1,len(txt)))  #txt中每个字符开始的 每个特征字符串重复次数

    for i in range(len(rows[0])-1):
        for j in range(len(txt)):
            tmp = txt[j : ]
            while(len(tmp) >= len(rows[0][i+1])):
                if tmp[0 : len(rows[0][i+1])] == rows[0][i+1]:
                    strnum[i][j] = strnum[i][j] +1
                else:
                    break
                tmp = tmp[len(rows[0][i+1]):]

    txtimes = np.zeros((len(rows[0])-1))
    for i in range(len(rows[0])-1):
        txtimes[i] = max(strnum[i])


    flag_no_all = 1
    for i in range(len(rows)-1):
        flag_no = 0
        for j in range(len(rows[0])-1):
            if txtimes[j] != int(rows[i+1][j+1]):
                flag_no = 1
                break
        if flag_no == 0:
            print(rows[i+1][0])
            flag_no_all = 0
            break
    if flag_no_all == 1:
        print("No match")

main()