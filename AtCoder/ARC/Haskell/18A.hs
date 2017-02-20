import Control.Applicative
import System.IO

main = do
    [h,b] <- (map (read :: String -> Double). words) <$> getLine
    print $ (h ^ 2) / 10000 * b
