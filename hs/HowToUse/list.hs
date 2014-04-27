--import Data.Char
--import Data.Time.Calendar
import Data.List
import Control.Applicative
import Control.Monad
import Text.Printf

plusIndex idx (x:xs)
	| xs == [] = [x + idx]
        | otherwise = (x + idx) : (plusIndex (idx + 1) xs)

solve = do
        getLine
        inp <- maximum . plusIndex 0 . map read . words <$> getLine
        print inp

-- http://www.codechef.com/MARCH14/problems/WALK/
-- (TLE..)
main = do
	t <- read <$> getLine
	replicateM t solve
