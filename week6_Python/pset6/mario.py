from cs50 import get_int

def main():
    n = get_positive_int()
    
    for i in range(n):
        print(" "*(n-i-1) + "#"*(i+1) + "  " + "#"*(i+1))


# Prompt user for positive integer
def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n<=8:
            break
    return n


main()