import Data.Array.IO
import Data.Array
import Control.Monad

--素数判定を行う配列
--リスト : エラトステネスの篩 (配列版)
--奇数のみ。[(0,True),(1,True),(2,True),(3,True),(4,False),(5,True),...]と[1,3,5,7,9,11,..]が対応
--http://www.geocities.jp/m_hiroi/func/haskell20.html
sieve :: Int -> IO (Array Int Bool)
sieve n = do
  ary <- newArray (0, n `div` 2 + 1) True :: IO (IOArray Int Bool)
  mapM_ (\x -> do f <- readArray ary (x `div` 2)
                  when f $ do delete_multiple ary x (x `div` 2))
        [3, 5 .. m]
  xs <- filterM (\x -> readArray ary (x `div` 2)) [3, 5 .. n]
  --return (2:xs)
  f <- freeze ary
  return f
    where m = (floor . sqrt . fromIntegral) n
          delete_multiple ary i j =
            mapM_ (\x -> writeArray ary x False) [j+i, j+i*2 .. n `div` 2 + 1]

--isPrime :: Int -> (Array Int Bool) -> Bool
isPrime n prms
	| n < 2 = False
	| n == 2 = True
	| even n = False
	| otherwise = prms ! (div n 2)


--素数の入ったリスト
--http://d.hatena.ne.jp/rst76/20091115
--32bit で収まるなら、primes :: [Int] と明示的に宣言した方が速い
_primes :: [Int]
_primes  = 2 : primes' where
  primes' = 3 : sieve 0 5
  sieve i x = filter isPrime [x,x+2..p*p-2] ++ sieve (i+1) (p*p+2) where
    (ps,p:_) = splitAt i primes'
    isPrime x = all ((/=0).rem x) ps

primes n = takeWhile (< n) _primes


main = do
	prm <- sieve 100
	print $ isPrime 15 prm
	--print prm
