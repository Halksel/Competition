import Control.Applicative
import System.IO

main = do
    [a,b,c] <- (map read . words) <$> getLine
    putStrLn $ if a+b == c || b+c == a || c+a == b then "Yes" else "No"
