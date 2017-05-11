import Control.Applicative
import System.IO

main = do
    a <- getChar
    c <- getChar
    b <- getChar
    if a == 'H' then putStrLn (b:[]) else if b == 'H' then putStrLn "D" else putStrLn "H"
