# target_sum = 26
# coins = [1,2,5,10,20,50, 100]
# coin_count = 7
# i = 0
#
# def count_me(i,coins,coin_count,target_sum):
#     i += 1
#     print(i)
#     if (target_sum) == 0:
#         return 1
#     if (target_sum < 0) or (coin_count<= 0):
#         return 0
#     return count_me(i,coins,coin_count-1, target_sum) + count_me(i,coins, coin_count, target_sum-coins[coin_count-1])
#
# print(count_me(i,coins, coin_count, target_sum))

target = 11
coins = [1,2,5,10]
my_array = [0]*(target+1)

for coin in coins:
    for i in range(target+1):
        if coin == i:
            my_array[i]+=1
        if i-coin>0:
            my_array[i]=((my_array)[i]+my_array[i-coin])
print(my_array)
print(my_array[target])
