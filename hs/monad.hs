import Control.Applicative
import Control.Monad
import Text.Printf

calc n = sum $ map (calcTerm n) [0..9]
--calcTerm
calcTerm ele i = (ele**i) / (fact i)
fact n = product [2..n]

-- https://www.hackerrank.com/challenges/eval-ex
main = do
	n <- read <$> getLine
	input <- replicateM n ((read :: String -> Float) <$> getLine)
	forM_ [0..n-1] $ \i -> printf "%.4f\n" $ calc $ input !! i
	--forM_ [0..n-1] $ \i -> print $ calc $ input !! i
	--mapM (\i -> print $ calc $ input !! i) [0..n-1] 
