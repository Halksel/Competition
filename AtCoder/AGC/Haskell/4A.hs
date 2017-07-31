import Control.Applicative
import Data.List
import System.IO

main = do
    [a,b,c] <- sort <$> map read <$> words <$> getLine :: IO [Int]
    putStrLn $ show $ a * b * abs (c `mod` 2)
