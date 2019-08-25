import Control.Applicative
import Data.Char
import System.IO

main = do
    [a,b,c] <- words <$> getLine
    putStrLn $ map toUpper (head a : head b : head c : [])
