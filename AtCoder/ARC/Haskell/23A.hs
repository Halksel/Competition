main = do
    y <- readLn
    m <- readLn
    d <- readLn
    print $ solve 2014 5 17 - solve y m d

-- solve :: Int -> Int -> Int -> Int
solve y 1 d = 365 * (y-1) + div (y-1) 4 - div (y-1) 100 + div (y-1) 400 + div (306 * 14) 10      + d - 429
solve y 2 d = 365 * (y-1) + div (y-1) 4 - div (y-1) 100 + div (y-1) 400 + div (306 * 15) 10      + d - 429
solve y m d = 365 * y + div y 4         - div y 100     + div y 400     + div (306 * (m + 1)) 10 + d - 429
