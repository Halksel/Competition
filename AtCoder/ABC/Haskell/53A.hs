import Control.Applicative

main = do
    [a,b] <- (map read . words) <$> getLine
    putStrLn $ solve a b

solve a b
  | a == b = "Draw"
  | a == 1 = "Alice"
  | b == 1 = "Bob"
  | otherwise = if a < b then "Bob" else "Alice"
