# !/usr/bin/env python
# coding=utf-8

def check_inefficient_road(n, m, route):
    """
    check inefficient roads, return the number of route
    """
    adj_table = []
    inefficient = []
    for i in range(n):
        temp = [-1] * len(n)
        adj_table.append(temp)
    for i in range(len(route)):
        current_route = route[i]
        adj_table[current_route[0]][current_route[1]] = current_route[2]
        # adj_table[current_route[1]][current_route[0]] = current_route[2]
    for k in range(len(route)):
        current_route = route[i]
        for i in range(n):
            for j in range(i, n):
                

        


if __name__ == '__main__':
    # begin
    open_file = open("../test.txt", 'rU')
    input_parameters = open_file.read()
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        temp = input_parameters[pos].split(' ')
        pos += 1
        n = int(temp[0])
        m = int(temp[1])
        route = []
        for i in range(m):
            temp = input_parameters[pos].split(' ')
            route.append(int(temp[0]), int(temp[1]), int(temp[2]))
            pos += 1
        result = check_inefficient_road(n, m, route)
        print "Case #%d:" % index + 1
        for i in range(result):
            print result[i]