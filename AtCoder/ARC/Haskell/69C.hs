import Control.Applicative

main = do
    [b,c] <- (map read . words) <$> getLine
    print $ if (c - b * 2) > 0 then (b + (c - b * 2) `div` 4) else c `div` 2
