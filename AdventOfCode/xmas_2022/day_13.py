
from functools import cmp_to_key


def compare(left, right):
    for i in range(max(len(left), len(right))):
        if i == len(left) and i < len(right):
            return True
        if i < len(left) and i == len(right):
            return False      

        lval = left[i]
        rval = right[i]

        if type(lval) is list and type(rval) is list:
            result = compare(lval, rval)
            if result is not None:
                return result

        elif type(lval) is int and type(rval) is list:
            result = compare([lval], rval)
            if result is not None:
                return result

        elif type(lval) is list and type(rval) is int:
            result = compare(lval, [rval])
            if result is not None:
                return result

        else:
            if lval < rval: return True
            if lval > rval: return False
            
    return None




def main():
    with (open('input/13.input', 'r')) as f:
        lines = [l.strip('\n') for l in f.readlines()]

    lines = list(filter(lambda x: x!='', lines))
    pairs = [(lines[i], lines[i+1]) for i in range(0, len(lines), 2)]
    
    # part 1

    good = []
    for i, p in enumerate(pairs):
        left = eval(p[0])
        right = eval(p[1])
        if compare(left, right): good.append(i+1)

    print(sum(good))


    # part 2
    lines.append('[[2]]')
    lines.append('[[6]]')
    packets = [eval(line) for line in lines]
    packets.sort(key = cmp_to_key(lambda a, b: -1 if compare(a,b) else 1))
    div1 = packets.index([[2]]) + 1
    div2 = packets.index([[6]]) + 1
    print(div1 * div2)





main()
