import Control.Applicative
import System.IO

main = do
    a <- words <$> getLine
    let [b1,b2,b3] = map (read) a
--     print (b1,b2,b3)
    print $ ((b3 + (b3-b2)*(b3-b2)/(b2-b1)))
