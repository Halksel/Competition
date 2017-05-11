import Control.Applicative
import System.IO

main = do
    s <- (map read . words) <$> getLine
    putStrLn $ if (s !! 1 - s !! 0) == (s !! 2 - s !! 1) then "YES" else "NO"
