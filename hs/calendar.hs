--http://wupc2012.contest.atcoder.jp/tasks/wupc2012_1

import Data.Time.Calendar

getArray str = map (read :: String -> Int) (words str)

main = do
	[ma, da] <- fmap getArray getLine
	[mb, db] <- fmap getArray getLine
	print $ diffDays (fromGregorian 2012 mb db) (fromGregorian 2012 ma da)