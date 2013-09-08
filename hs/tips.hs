import Data.Char

--digitSum : 整数nの各桁の総和を出す
mOrd n = (ord n) - (ord '0')
digitSum n = sum $ map mOrd (show n)


--getDiv : nの約数の数を数える
getDiv n = getD n 1

getD n i
	| i > d = 0
    | mod n i /= 0 = getD n (i+1)
    | d == i = 1
    | otherwise = 2 + (getD n (i + 1))
	where d = div n i


--getDivs : nの約数を列挙
--getDivs :: Int -> [Int]
getDivs n = getDs n 1

--getDs :: Int -> Int -> [Int]
getDs n i
	| i > d = []
    | mod n i /= 0 = getDs n (i+1)
    | d == i = [i]
    | otherwise = i : d : (getDs n (i + 1))
	where d = div n i

getAbundant i lim
	| i == lim = []
	| i < adt = i : getAbundant (i+1) lim
	| otherwise = getAbundant (i+1) lim
	where adt = (sum (getDivs i)) - i


main = print $ digitSum 123
