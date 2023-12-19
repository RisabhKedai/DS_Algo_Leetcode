# -*- coding: utf-8 -*-
# @Author: lenovo
# @Date:   2023-12-04 01:37:57
# @Last Modified by:   lenovo
# @Last Modified time: 2023-12-04 01:38:50

class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()  # Sort the coins in ascending order
        reachable = 0  # The maximum value that can be obtained with the current set of coins
        added_coins = 0  # The minimum number of coins needed to be added

        for coin in coins:
            # If the current coin is greater than reachable + 1, we need to add coins to fill the gap
            while coin > reachable + 1:
                added_coins += 1
                reachable += reachable + 1  # Add the next reachable value

                # If the new reachable value is greater than or equal to the target, return added_coins
                if reachable >= target:
                    return added_coins

            # Update the reachable value with the current coin
            reachable += coin

            # If the new reachable value is greater than or equal to the target, return added_coins
            if reachable >= target:
                return added_coins

        # If the loop completes and the target is still not reached, add coins until it is reached
        while reachable < target:
            added_coins += 1
            reachable += reachable + 1

        return added_coins

# # Example usage:
# coins = [1, 2, 5]
# target = 11
# result = minAddToMakeValid(coins, target)
# print(result)

'''
Time complexity: O(N)
Space complexity : O(1)
'''