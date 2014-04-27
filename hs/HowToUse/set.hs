import Data.Set

--main = print $ toList $ fromList [1,2,3,3,4,5]

main = print $ toList $ insert 2 (insert 1 empty)
