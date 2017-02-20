import Prelude
import System.IO

main = do
    n <- readLn
    putStrLn $ solve n

solve :: Int -> String
solve k = (\ b -> if b then "YES" else "NO") $ all (\ x -> k `mod` x /= 0 ) $ take (ceiling (sqrt (realToFrac k))) $ slave 2 k [2..k]

slave :: Int -> Int -> [Int] -> [Int]
slave n k arr
  | n * n >= k     = arr
  | length arr > 1 = ret
  | otherwise      = [n]
  where a = filter (\ x -> x `mod` n /= 0) arr
        ret = n : slave (head a) k a
