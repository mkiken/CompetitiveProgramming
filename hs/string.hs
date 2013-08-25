--http://stackoverflow.com/questions/4978578/how-to-split-a-string-in-haskell
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

main = print $ remChar ',' "a,b,c"
--main = print $ splitComma "a,b,c"
