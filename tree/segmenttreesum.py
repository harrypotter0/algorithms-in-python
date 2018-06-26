def create_segment_tree(input):
    size = next_power_of_2(len(input));
    segment_tree = [0 for x in range(2*size - 1)]
    construct_tree(segment_tree, input, 0, len(input) - 1, 0)
    return segment_tree

def construct_tree(segment_tree, input, low, high, pos):
    if low == high:
        segment_tree[pos] = input[low]
        return

    mid = (low + high)/2
    construct_tree(segment_tree, input, low, mid, 2*pos + 1)
    construct_tree(segment_tree, input, mid + 1, high, 2*pos + 2)
    segment_tree[pos] = segment_tree[2*pos+1] + segment_tree[2*pos+2]

def sum_range_query(segment_tree, q_low, q_high, len):
    return sum_range_query_util(segment_tree, 0, len - 1, q_low, q_high, 0)

def sum_range_query_util(segment_tree, low, high, q_low, q_high, pos):
    if q_low <= low and q_high >= high:
        return segment_tree[pos]

    if q_high < low or q_low > high:
        return 0

    mid = (low + high)/2
    return sum_range_query_util(segment_tree, low, mid, q_low, q_high, 2*pos + 1)\
           + sum_range_query_util(segment_tree, mid + 1, high, q_low, q_high, 2*pos + 2)

def update_value(input, segment_tree, new_value, index):
    diff = new_value - input[index]
    input[index] = new_value
    update_value_util(segment_tree, 0, len(input)-1, diff, index, 0)


def update_value_util(segment_tree, low, high, diff, index, pos):
    if low > index or high < index:
        return
    segment_tree[pos] += diff

    if low >= high:
        return
    mid = (low + high)/2
    update_value_util(segment_tree, low, mid, diff, index, 2*pos + 1)
    update_value_util(segment_tree, mid + 1, high, diff, index, 2*pos + 2)

def updateSegmentTreeRangeLazy( input, segmentTree, lazy, startRange, endRange, delta):
    updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, 0, input.length - 1, 0)


def rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, leni):
    return rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, 0, leni - 1, 0)


def next_power_of_2(n):
    if n == 0:
        return 1
    if n & (n - 1) == 0:
        return n
    while n & (n - 1) > 0:
        n &= (n - 1)
    return n << 1

def updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, low, high, pos):
        if(low > high):
            return

        if (lazy[pos] != 0):
            segmentTree[pos] += lazy[pos]
            if (low != high):
                lazy[2 * pos + 1] += lazy[pos]
                lazy[2 * pos + 2] += lazy[pos]
            lazy[pos] = 0

        if(startRange > high || endRange < low):
            return

        if(startRange <= low && endRange >= high):
            segmentTree[pos] += delta
            if(low != high):
                lazy[2*pos + 1] += delta
                lazy[2*pos + 2] += delta
            return

        int mid = (low + high)/2
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange,delta, low, mid, 2*pos+1)
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange,delta, mid+1, high, 2*pos+2)
        segmentTree[pos] = Math.min(segmentTree[2*pos + 1], segmentTree[2*pos + 2])

def rangeMinimumQueryLazy(int segmentTree, int lazy[], int qlow, int qhigh, low, int high, int pos):
    if(low > high):
        return Integer.MAX_VALUE

    if (lazy[pos] != 0)
        segmentTree[pos] += lazy[pos]
        if (low != high):
            lazy[2 * pos + 1] += lazy[pos]
            lazy[2 * pos + 2] += lazy[pos]
        lazy[pos] = 0

    if(qlow > high || qhigh < low):
        return Integer.MAX_VALUE

    if(qlow <= low && qhigh >= high):
        return segmentTree[pos]

    int mid = (low+high)/2
    return Math.min(rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh,
                    low, mid, 2 * pos + 1),
            rangeMinimumQueryLazy(segmentTree, lazy,  qlow, qhigh,
                    mid + 1, high, 2 * pos + 2))



if __name__ == '__main__':
    input = [1,3,5,7,9,11]
    segment_tree = create_segment_tree(input)
    print(segment_tree)
    print(sum_range_query(segment_tree, 2, 5, len(input)))
    print(sum_range_query(segment_tree, 1, 3, len(input)))
    update_value(input, segment_tree, 4, 3)
    print(input)
    print(segment_tree)
    print(sum_range_query(segment_tree, 2, 5, len(input)))
    print(sum_range_query(segment_tree, 1, 3, len(input)))
    updateRange(len(input), 1, 5, 10)

    #lazy propagation example
    input1 = [-1,2,4,1,7,1,3,2]
    segTree1 = create_segment_tree(input)
    lazy1 = []
    updateSegmentTreeRangeLazy(input1, segTree1, lazy1, 0, 3, 1)
    updateSegmentTreeRangeLazy(input1, segTree1, lazy1, 0, 0, 2)
    print(1 == rangeMinimumQueryLazy(segTree1, lazy1, 3, 5, input1.length))
