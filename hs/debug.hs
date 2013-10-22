-- http://tenka1-2012-final.contest.atcoder.jp/tasks/tenka1_2012_final_ a

--import Control.Applicative
--import Debug.Trace

fibs  = fib 0 1
fib a b = a : fib b (a+b)

calc n f c count
	| n <= 0 = count
	| n >= f !! c = calc (n - (f !! c)) f c (count + 1)
	| otherwise = calc n f (c - 1) count
{-
calc_d n f c count = do
	trace ("n = " ++ show n) $ calc n f c count
-}
main = do
--	print $ fib 0 1 !! 50
	l <- getLine
	print $ calc ((read :: String -> Integer) l) fibs 49 0