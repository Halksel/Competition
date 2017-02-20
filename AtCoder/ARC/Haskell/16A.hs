import Control.Applicative
import System.IO

main = do
    ss <- words <$> getLine
    let n:m:xs = ss
    putStrLn $ show $ if m == "1" then 2 else (read m)-1
