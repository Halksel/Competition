import Control.Applicative
import System.IO

main = do
    s <- getLine
    print $ length $ dropWhile (/= 'Z') $ reverse $ dropWhile (/= 'A') s
