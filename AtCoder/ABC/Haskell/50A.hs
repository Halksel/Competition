import Control.Applicative

main = do
    [a,op,b] <- words <$> getLine
    let c = read a
        d = read b
    print $ if op == "+" then c+d else c - d
