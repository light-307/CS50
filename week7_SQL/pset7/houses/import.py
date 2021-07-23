import sys
import csv
import cs50

def main():

    # Check for correct number of args
    if len(sys.argv) != 2:
        print("error")
        sys.exit(1)

    csvfile = sys.argv[1] if len(sys.argv) == 2 else "characters.csv"

    db = cs50.SQL("sqlite:///students.db")

    with open(csvfile, "r") as files:

        reader = csv.DictReader(files)

        for row in reader:
            name = row["name"].split()
            house = row["house"]
            birth = int(row["birth"])

            if len(name)== 2:
                db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", name[0], name[1], house, birth)
            else:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[0], name[1], name[2], house, birth)


main()