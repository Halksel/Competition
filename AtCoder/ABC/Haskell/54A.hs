import Control.Applicative

main = do
    n <- readLn :: IO Int
    putStrLn $ show $ n * 800 - n `div` 15 * 200
