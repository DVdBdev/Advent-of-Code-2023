# get a dictionary with key value pairs like:
# 'Game 1': ['13 red','18 green','5 green','3 red','5 blue','5 green','9 red','6 blue','3 blue','3 green']
d = {}
for line in open("data.txt").readlines(): 
    game = line.split(":")[0] 
    cubes = [x.strip() for x in line.split(":")[1].replace(";",",").split(",")] 
    d[game] = cubes
# Part 1 & 2
sum_of_possible_game_ids = 0 
sum_of_power = 0 
for key, value in d.items(): 
    red, green, blue = 0, 0, 0 
    for i, x in enumerate(value): 
        color = x.split()[1] 
        num = int(x.split()[0]) 
        if color == "red" and num > red: 
            red = num
        if color == "green" and num > green: 
            green = num 
        if color == "blue" and num > blue: 
            blue = num
    if red <= 12 and green <= 13 and blue <= 14:              
        sum_of_possible_game_ids += int(key.split()[1]) 
    sum_of_power += red * green * blue
# result Part 1
print(sum_of_possible_game_ids)
# result Part 2
print(sum_of_power)