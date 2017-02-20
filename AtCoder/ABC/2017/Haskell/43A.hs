import System.IO

main = do
    n <- readLn
    print $ sum ([1..n] :: [Int])
