a = [["a",'b'], ['c','d'], ['e','f']]
 
# for i in range(len(a)):            # 세로 크기
#     for j in range(len(a[i])):     # 가로 크기
#         print(a[i][j], end=' ')
#     print()
w = 'c'
for r in a:
    for j in w:
        if j in r:
            print(r.index(j))
            print(a.index(r))
    # print(r)