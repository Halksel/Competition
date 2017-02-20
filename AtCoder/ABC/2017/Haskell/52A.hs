main = getLine >>= putStrLn . (\ s -> if s < "1200" then "ABC" else "ARC")
