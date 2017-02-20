import System.IO

main = do
    n <- readLn
    putStrLn $ if even n then "Blue" else "Red"
