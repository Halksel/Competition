import Control.Applicative
import Control.Monad
import Data.Bits
main = do
    ss <- string2int <$> getLine
    putStrLn $ show (((ss * 2 - (calc ss))`mod`1004535809))

calc :: Integer -> Integer
calc 2 = 1
calc n = n + calc (n`div`2)

string2int str = read str :: Integer

toString2 :: Integer -> String
toString2 m = iter m [] where
  iter 0 xs = if null xs then "0" else xs
  iter m xs = iter (m `div` 2) (show (m `mod` 2) ++ xs)
