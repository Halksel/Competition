import Control.Applicative

main = do
    n <- getLine
    a <- sum . (map solve . words . init) <$> getLine
    print a

solve :: String -> Int
solve "TAKAHASHIKUN" = 1
solve "Takahashikun" = 1
solve "takahashikun" = 1
solve _ = 0
