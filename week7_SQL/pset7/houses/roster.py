import sys
import csv
import cs50

def main():

    # Check for correct number of args
    if len(sys.argv) != 2:
        print("error")
        sys.exit(1)

    house_name = sys.argv[1] if len(sys.argv) == 2 else "Gryffindor"

    db = cs50.SQL("sqlite:///students.db")

    names = db.execute("SELECT first,middle,last,birth FROM students WHERE house = (?) ORDER BY last,first", house_name)

    for row in names:
        if row["middle"] is None:
            print(row["first"] + " " + row["last"] + ", born " + str(row["birth"]))
        else:
            print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " + str(row["birth"]))


main()