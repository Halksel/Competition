import System.IO

main = do
    n <- readLn
    k <- readLn
    x <- readLn
    y <- readLn
    print $ ( if n < k then n * x else k * x + (n - k) * y)
