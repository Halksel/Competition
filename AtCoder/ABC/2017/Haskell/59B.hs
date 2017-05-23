import Control.Applicative
import System.IO

main = do
    a <- readLn :: IO Integer
    b <- readLn :: IO Integer
    putStrLn $ (if a == b then "EQUAL" else if a < b then "LESS" else "GREATER")
