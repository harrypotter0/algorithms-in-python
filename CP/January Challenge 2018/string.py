def longest_common_subsequence(sequence1, sequence2):
    cols = len(sequence1) + 1   # Add 1 to represent 0 valued column for DP
    rows = len(sequence2) + 1   # Add 1 to represent 0 valued row for DP

    T = [[0 for _ in range(cols)] for _ in range(rows)]

    max_length = 0

    for i in range(1, rows):
        for j in range(1, cols):
            if sequence2[i - 1] == sequence1[j - 1]:
                T[i][j] = 1 + T[i - 1][j - 1]
            else:
                T[i][j] = max(T[i - 1][j], T[i][j - 1])

            max_length = max(max_length, T[i][j])

    return max_length

