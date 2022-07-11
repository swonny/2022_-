# 3kg, 5kg

# n = int(input())

"""
1. 5kg 이상일 때
2. 3kg 이상일 때

3kg 미만일 때 : -1 출력

1. -1 출력해야하는 경우 : 3으로 나눈 나머지가 1~2 사이일 때 | 5로 나눈 나머지가 1~2 사이일 때 || 5로 나눈 나머지가 4일 때
2. 3kg -> 3의 배수
3. 5Kg -> 5의 배수
4. 
"""
# import sys

# num = sys.stdin.read().strip().split('\n')

# 2839 설탕배달

n = int(input())

if n%5 == 0 or (n%5)%3 == 0:
    print((n//5) + (n%5)//3)
elif n%3 == 0 or (n%3)%5 == 0:
    print((n//3) + (n%3)//5)
else:
    print(-1)