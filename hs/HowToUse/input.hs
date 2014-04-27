import Control.Applicative
import Control.Monad

--http://tenka1-2013-quala.contest.atcoder.jp/submissions/94084
main = do
	n <- read <$> getLine
	input <- replicateM n $ sum . map read . words <$> getLine
	print $ length $ filter (<20) input
