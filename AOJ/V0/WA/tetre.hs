tetre n 1 = n
tetre n k = power n (tetre n (k -1))
power x n
  | n == 0    = 1
  | even n    = power (x*x) (n `div` 2)
  | otherwise = x * power x (n - 1)

primes = sieve [2..]
    where
      sieve (x:xs) = x : sieve ([y| y <- xs, x*x > y || y `mod` x /= 0])

listtoInt [] t = t
listtoInt (x:xs) t = listtoInt xs (t + (x * (power 10 (length xs))))

makenum 0 t = t+1
makenum n t = makenum (n-1) ( t + (power 10 n) )
