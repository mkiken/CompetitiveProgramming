import Data.Array
import Control.Applicative

--Arrays配列の長さ
alen ary = (snd (snd (bounds ary)) + 1)

--二次元のnxnのIntフィールドをArraysに読み込む
getField :: String -> Array (Int,Int) Int
getField s = (listArray ((0,0),(len-1,len-1)) . map read . words) s
	where
		len = (length . lines) s

--Euler11
goR i j len ary jj
	| jj == 4 = 1
	| j == len = 0
	| otherwise = (ary ! (i,j)) * (goR i (j+1) len ary (jj+1))
goD i j len ary ii
	| ii == 4 = 1
	| i == len = 0
	| otherwise = (ary ! (i,j)) * (goD (i+1) j len ary (ii+1))
goRD i j len ary ii
	| ii == 4 = 1
	| i == len || j == len  = 0
	| otherwise = (ary ! (i,j)) * (goRD (i+1) (j+1) len ary (ii+1))
goLD i j len ary ii
	| ii == 4 = 1
	| i == len || j == len  = 0
	| otherwise = (ary ! (i,j)) * (goLD (i+1) (j-1) len ary (ii+1))
getElem i j len ary
	| i == len = 0
	| j == len = getElem (i+1) 0 len ary
	| otherwise = maximum [(goR i j len ary 0), (goD i j len ary 0), (goRD i j len ary 0), (goLD i j len ary 0),   (getElem i (j+1) len ary)]

main = do
	inp <- getField <$> getContents
	--print $ inp
	--inp <- getContents
	print $ inp
	print $ alen inp
	print $ getElem 0 0 (alen inp) inp
