# Utility function to read a list of numbers from stdin
def readInts():
    return map(int, raw_input().strip().split())

# Function f(x) = 1000 * sqr(max(x, 1))
def f(x):
    return 1000 * (max(x, 1) ** 2)

# Function to find the cost of the building
def calculateCost(changeInHeight, baseCost):
    sum = 0

    # f(B) + f(B-1) + f(B-2) + .... + f(B-(h-1))
    for i in range(baseCost - (changeInHeight - 1), baseCost + 1):
        sum += f(i)

    return sum

# Function to solve a test case
def solveTestCase():
    [n, b] = readInts()

    heights = readInts()
    new_heights = []

    # Copy heights into new_heights so we can calculate change in heights
    for i in range(n):
        new_heights.append(heights[i])

    # Compute the max height
    max_height = max(heights);

    # Find all occurrences of max_height
    max_indices = [i for i, x in enumerate(heights) if x == max_height]

    # Find the max_height index at the ends of the list
    max_index = reduce((lambda x, y: x if abs(x - (n / 2)) > abs(y - (n / 2)) else y), max_indices)

    center = n / 2

    # For odd length, index 5 / 2 = 2, 0, 1, 2, 3, 4 so it is correctly center
    # But for even it always splits into [0, 1, 2], [3, 4, 5]. The center should
    # be the one which is nearest to the max_index

    if n % 2 == 0 and max_index < n / 2:
        center -= 1

    max_height += abs(max_index - center)

    # print "max_index", max_index
    # print "center", center
    # print max_height

    # Calculate the new heights on both sides of the array
    for i in range(n / 2, n):
        new_heights[i] = max_height - (i - n / 2)

    for i in range(0, n / 2):
        new_heights[i] = new_heights[n - i - 1]

    # print new_heights

    # Calculate the cost for the buildings
    cost = 0

    for i in range(n):
        heightDiff = new_heights[i] - heights[i]

        # Add the cost for that building
        if heightDiff != 0:
            cost += calculateCost(heightDiff, b)

    print cost

# Read the number of test cases
[t] = readInts()
for i in range(t):
    solveTestCase()
