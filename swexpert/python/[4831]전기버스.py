T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    K, N, M = map(int, input().split())    
    station = [0] * (N + 1)
    arr = list(map(int, input().split()))
    for i in range(0, N):
        station[arr[i]] = 1

