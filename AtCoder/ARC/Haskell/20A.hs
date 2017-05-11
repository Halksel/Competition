import Control.Applicative
import System.IO

main = do
    [a,b] <- (map read . words) <$> getLine
    putStrLn $ if abs a < abs b then "Ant" else if abs a == abs b then "Draw" else "Bug"
