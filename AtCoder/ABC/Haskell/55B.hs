main = readLn >>= print . (\n -> f [2..n])

f [] = 1
f (x:y) = x * mod (f y) (10^9 + 7)
