import Text.Printf
import Data.List
import Numeric (showOct, showHex)


--http://stackoverflow.com/questions/4978578/how-to-split-a-string-in-haskell
--
wordsWhen     :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'
--文字cで文字列を分割する
split c = wordsWhen (== c)
splitComma = split ','

--文字列から文字cを取り除く
remChar c = filter (/= c)

--http://stackoverflow.com/questions/11870536/all-list-rotations-in-haskell
rotate xs = init (zipWith (++) (tails xs) (inits xs))

--http://tnomura9.exblog.jp/17398261
i2b = concat . (map show) . reverse . i2b'
	where
		i2b' 0 = [];
		i2b' n = mod n 2 : i2b' (div n 2)
--i2o = printf "%o"
i2o n = showOct n ""
--i2h = printf "%x"
i2h n = showHex n ""

isPalindrome s = s == reverse s

main = print $ isPalindrome "ab"
--main = print $ remChar ',' "a,b,c"
--main = print $ splitComma "a,b,c"
--main = putStrLn . i2b $ 585
