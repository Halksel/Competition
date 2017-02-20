main = getLine >>= putStrLn . map (\ c -> if c == ',' then ' ' else c)
