#!/usr/bin/python3

import sys

def to_csv(file_name: str):
    date = '-'.join(file_name.split("-")[1:]).split(".")[0].strip()

    print(date, end="\t")

    try:
        with open(file_name, "r") as f:
            for line in f:
                line = line[:-1]
                print(line, end="\t")
    except:
        pass
    finally:
        print()

def main():
    try:
        arg = sys.argv[1]
        to_csv(arg)
    except:
        print("")
        sys.exit("Please provide log file")

if __name__ == "__main__":
    main()