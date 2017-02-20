import Control.Applicative
import System.IO

main = do
    getLine >>= putStrLn . map head . words
