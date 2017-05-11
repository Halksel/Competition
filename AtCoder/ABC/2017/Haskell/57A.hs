import Control.Applicative
import System.IO

main = do
    s <- (map read . words) <$> getLine
    print $ mod (s !! 0 + s !! 1) 24
