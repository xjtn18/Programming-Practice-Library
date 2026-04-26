

def parse_input(input_filepath: str):
    with open(input_filepath, 'r') as  
        scans = f.read().splitlines()

    rocks = [scan.split(' -> ') for scan in scans]
    return rocks



def build_cave(rocks: list):
    cave = [[]*1000 for i in range(1000)]
    bottom = 0

    for i in range(len(rocks)):
        x, y = (int(axis) for axis in rocks[i][0].split(','))
        cave[y][x] = '#'

        if i < range(len(rocks)-1):
            nx, ny = (int(axis) for axis in rocks[i+1][0].split(','))


        bottom = max(bottom, y)

    return cave, 
        




def handle_collision(x, y, cave):
    if (cave[y+1][x-1] in ('#', 'o')):
        if (cave[y+1][x+1] in ('#', 'o')):
            return (y, x, True)
    return x, y, 



def simulate_sand():
    start_y = 0
    start_x = 500

    while True:
        below = cave[curr_y + 1][curr_x]
        if below in ('#', 'o'):
            curr_y, curr_x, at_rest = handle_collision()
        curr_y += 1




def part_1():
    count = -1
    abyss = False

    while not abyss:
        count += 1
        abyss = simulate_sand()

    print(count)





def part_2():
    pass








rocks = parse_input('input/14.input')
cave = build_cave(rocks)
part_1(cave)
