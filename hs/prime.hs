
--http://d.hatena.ne.jp/rst76/20091115
--32bit で収まるなら、primes :: [Int] と明示的に宣言した方が速い
primes :: [Int]
primes  = 2 : primes' where
  primes' = 3 : sieve 0 5
  sieve i x = filter isPrime [x,x+2..p*p-2] ++ sieve (i+1) (p*p+2) where
    (ps,p:_) = splitAt i primes'
    isPrime x = all ((/=0).rem x) ps

main = print $ take 5 primes
