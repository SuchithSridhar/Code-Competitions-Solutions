def convert_base(num: str, base: int) -> int:
    total = 0
    length = len(num)
    multiplier = 1
    for i in range(1, length+1):
        total += multiplier * int(num[length - i])
        multiplier *= base

    return total

def is_congruent(code: str, b: int, m: int, r: int):
    return convert_base(code, b) % m == r

def is_congruence_substrings(code: str, b: int, m: int, r: int):
    parts = []
    index = 0
    length = len(code)
    cur_part = ""
    
    while (True):
        cur_part += code[index]

        if is_congruent(cur_part, b ,m, r):
            if index == length-1:
                return True

            if code[index+1] != "0":
                parts.append(cur_part)
                cur_part = ""

        elif index == length-1:
            # we reached the end and it's not congruent
            if len(parts) == 0:
                return False

            index -= len(cur_part)
            cur_part = parts.pop()

        index += 1


def main(): 
    n = int(input()) # Number of test cases
    for _ in range(n):
        b, m, r = map(int, input().split(" "))
        code = input()

        if is_congruence_substrings(code, b, m, r):
            print("valid")
        else:
            print("invalid")


if __name__ == "__main__":
    main()
