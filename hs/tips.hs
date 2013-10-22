import Data.Char

--パスカルの三角形を表示
--https://www.hackerrank.com/challenges/pascals-triangle
fact n = product [1..n]
writeLine i = forM_ [0..i+1] (writeElement i)
writeElement row col
	| col == (row+1) = putChar '\n'
        | otherwise = do
        	printf "%d " $ div (fact (row)) ((fact (col)) * (fact (row-col)))
pascal n = forM_ [0..n-1] writeLin e

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

--isSqrtInt :: Int -> Bool
isSqrtInt n = n == rt*rt
	where rt = (round . sqrt . fromIntegral) n

main = print $ digitSum 123
