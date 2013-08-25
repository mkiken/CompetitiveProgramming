--http://hackage.haskell.org/packages/archive/time/1.1.2.1/doc/html/Data-Time-Calendar.html
import Data.Time.Calendar


--for Project Euler 19
getRes y m d a
	| m == 12 = a + progMonth (y+1) 1 (d + gregorianMonthLength y m)
	| otherwise = a + progMonth y (m+1) (d + gregorianMonthLength y m)

progMonth y m d
	| y == 2001 = 0
	| mod (d + gregorianMonthLength y m) 7 == 5 = getRes y m d 1
	| otherwise = getRes y m d 0

{-
leap n
	| mod n 400 == 0 = 366
	| mod n 100 == 0 = 365
	| mod n 4 == 0 = 366
	| otherwise = 365

getFeb y
	| (isLeapYear y) = 1
	| otherwise = 0

getMonth y m
	| m == 1 = 31
	| m == 2 = 28 + getFeb y
	| m == 3 = 31
	| m == 4 = 30
	| m == 5 = 31
	| m == 6 = 30
	| m == 7 = 31
	| m == 8 = 31
	| m == 9 = 30
	| m == 10 = 31
	| m == 11 = 30
	| m == 12 = 31
-}

--main = print $ div (sum (map leap [1900..2000])) 7
main = print $ progMonth 1901 1 1

