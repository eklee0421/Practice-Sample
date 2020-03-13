# soma practice

import sys
import math
input = sys.stdin.readline

N, k = map(int, input().split())
muk = list(map(int, input().split()))

ans = math.ceil(((N - 1) / (k-1)))

print(ans)
