s = int(input())
i=1
count=0
while(1):
    s-=i
    count+=1
    i+=1
    if(s<i):
        break
print(count)