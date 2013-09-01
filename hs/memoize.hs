--http://www.haskell.org/haskellwiki/Memoization	
{- memoized_fib :: Int -> Integer -}
{- memoized_fib = (map fib [0 ..] !!) -}
   {- where fib 0 = 0 -}
         {- fib 1 = 1 -}
         {- fib n = memoized_fib (n-2) + memoized_fib (n-1) -}

lfib n
	| n == 0 = 1
	| n == 1 = 1
	| otherwise = lfib (n-1) + lfib(n-2)

memoized_fib :: Int -> Integer
memoized_fib = (map fib [0 ..] !!)
   where fib n | n == 0 = 0
			   | n == 1 = 1
               | otherwise = memoized_fib (n-2) + memoized_fib (n-1)

main = print $ memoized_fib (1000)
