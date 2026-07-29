from collections import Counter
from math import factorial

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        freq = Counter(s)

        middle = ""
        half = {}

        for ch in sorted(freq):
            if freq[ch] % 2:
                middle = ch
            half[ch] = freq[ch] // 2

        remaining = sum(half.values())

        ways = factorial(remaining)
        for count in half.values():
            ways //= factorial(count)

        if k > ways:
            return ""

        left = []

        while remaining > 0:
            for ch in sorted(half):
                if half[ch] == 0:
                    continue

                permutations = ways * half[ch] // remaining

                if k > permutations:
                    k -= permutations
                else:
                    left.append(ch)
                    ways = permutations
                    half[ch] -= 1
                    remaining -= 1
                    break

        left = "".join(left)
        return left + middle + left[::-1]
        