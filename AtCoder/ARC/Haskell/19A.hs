import Control.Applicative
import System.IO

main = do
    s <- getLine
    putStrLn $ map solve s

solve 'O' = '0'
solve 'D' = '0'
solve 'I' = '1'
solve 'Z' = '2'
solve 'S' = '5'
solve 'B' = '8'
solve c   = c
