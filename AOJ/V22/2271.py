# coding: utf-8
s = raw_input();

k = u = p = c = 0;
for a in s:
    if a == 'K':
        k += 1;
        if a == 'U':
            u += 1;
        if a == 'P':
            p += 1;
        if a == 'C':
            c += 1;

print min(k,u,p,c);
