
import Control.Applicative
import Control.Monad
--import Data.Char
--import Data.Time.Calendar
import Data.List as List
import Data.Maybe
import Text.Printf

import qualified Data.ByteString.Char8 as B
import qualified Data.Map as Map

readInt :: B.ByteString -> Int
readInt = fst . fromJust . B.readInt

rsort :: [Int] -> [Int]
rsort = sortBy (\x y -> compare y x )

{- readInts = map read . words <$> getLine -}

main = print 0

