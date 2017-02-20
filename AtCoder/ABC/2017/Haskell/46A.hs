import Control.Applicative
import Data.List
import System.IO

main = do
    ss <- (map read . words) <$> getLine
    print $ (length . nub) (ss :: [Int])
