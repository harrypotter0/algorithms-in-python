

# !/usr/bin/env python
# coding=utf-8
import math
import pdb


def turn(angel, action):
    if action == 'L':
        angel += math.pi / 2
    elif action == 'R':
        angel -= math.pi / 2
    return angel
    # angel = turn(angel, time_action[i])
    # speed = [-1 * int(math.sin(angel)), int(math.cos(angel))]


def change_speed(speed, action):
    if speed[0] == 0 and speed[1] == 1:
        if action == 'L':
            return [-1, 0]
        else:
            return [1, 0]
    elif speed[0] == 1 and speed[1] == 0:
        if action == 'L':
            return [0, 1]
        else:
            return [0, -1]
    elif speed[0] == 0 and speed[1] == -1:
        if action == 'L':
            return [-1, 0]
        else:
            return [1, 0]
    else:
        if action == 'L':
            return [0, -1]
        else:
            return [0, 1]


def length_snake(s, r, c, actions):
    """
    return the length of gsnake
    """
    pos = [0, 0]
    length = 1
    body = ['0,0']
    time_action = {}
    for i in range(len(actions)):
        time_action[actions[i][0] - 1] = actions[i][1]
    speed = [0, 1]
    angel = 0
    board = []
    for i in range(r):
        temp = []
        for j in range(c):
            if (i + j) % 2 == 0:
                temp.append(0)
            else:
                temp.append(1)
        board.append(temp)
    for i in range(actions[-1][0]):
        pos[0] += speed[0]
        pos[1] += speed[1]
        pos[0] %= r
        pos[1] %= c
        stemp = "%d,%d" % (pos[0], pos[1])
        if stemp in body[:-1]:
            return length
        body.insert(0, stemp)
        if board[pos[0]][pos[1]] > 0:
            length += 1
            board[pos[0]][pos[1]] = 0
        else:
            body.pop()
        try:
            speed = change_speed(speed, time_action[i])
        except:
            pass
    for i in range(max([c, r])):
        pos[0] += speed[0]
        pos[1] += speed[1]
        pos[0] %= r
        pos[1] %= c
        stemp = "%d,%d" % (pos[0], pos[1])
        if stemp in body[:-1]:
            return length
        body.insert(0, stemp)
        if board[pos[0]][pos[1]] > 0:
            length += 1
            board[pos[0]][pos[1]] = 0
        else:
            body.pop()
    return length


def quick_length_snake(s, r, c, actions):
    pos = [0, 0]
    length = 1
    body = ['0,0']
    time_action = {}
    speed = [0, 1]
    angel = 0
    board = []
    last = 0
    for index, temp in enumerate(actions):
        rtime = temp[0] - last
        last = temp[0]
        action = temp[1]
        road = rtime
        if speed[0] == 0:
            road %= c
            if road == 0 and rtime != 0:
                road = c
        else:
            road %= r
            if road == 0 and rtime != 0:
                road = r
        for i in range(road):




if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        temp = input_parameters[pos].split(' ')
        pos += 1
        s = int(temp[0])
        r = int(temp[1])
        c = int(temp[2])
        action = []
        for i in range(s):
            temp = input_parameters[pos].split(' ')
            pos += 1
            action.append((int(temp[0]), temp[1]))
        print "Case #%d: %d" % (index + 1, quick_length_snake(s, r, c, action))
