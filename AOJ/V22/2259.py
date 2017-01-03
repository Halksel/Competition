# coding: utf-8
n, m = map(int, raw_input().split());

ans = 0;

for i in range(n):
    nums = map(int, raw_input().split());
    cnt = 0;
    for num in nums:
        if num == 1:
            cnt = cnt + 1;
            ans = max(ans,cnt);
print ans;
