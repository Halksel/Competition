import Control.Applicative
import System.IO

main = do
  s <- words <$> getLine
  let [a,b,c] = map read s :: [Int]
  putStrLn $ (if (a <= c && c <= b) then "Yes" else "No")
