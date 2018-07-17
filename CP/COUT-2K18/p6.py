T = int(input())
for t in range(T):
  N = int(input())
  if N % 9 == 2 or N % 9 == 3:
    print('Sailaja')
  else:
    print('Supraja')
    
'''
Input:
5

Output:
Supraja


Sample - 2

Input:
3

Output:
Sailaja

'''
