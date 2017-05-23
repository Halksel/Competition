import Control.Applicative
import System.IO

main = do
    [a,b,c] <- words <$> getLine
    putStrLn $ (if head b == last a && head c == last b then "YES" else "NO")
