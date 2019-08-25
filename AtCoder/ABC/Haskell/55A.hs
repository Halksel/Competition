main = readLn >>= print . (\n -> 800 * n - 200 * div n 15)
