li1 = list(input().split())
li4 = [int(li1[i]) for i in range(len(li1))]
li2 = []
li3 = []
for i in range(li1[0]):
    for j in range(li1[1]):
        if j == li1[2]-1:
            li2.append(li1[3])
        else:
            li2.append(int(input()))
    li3.append(tuple(li2))
    li2 = []
print(li3)