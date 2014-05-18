import Control.Applicative
import Control.Monad
--import Data.Char
--import Data.Time.Calendar
import Data.List as List
import Data.Maybe
import Text.Printf

import qualified Data.ByteString.Char8 as B
import qualified Data.Map as Map

rsort :: [Int] -> [Int]
rsort = sortBy (\x y -> compare y x )

mjoin sp ary = intercalate sp (map show ary)


-- readInt = read <$> getLine
-- readInts = map read . words <$> getLine


solve = do
  print 1


main = do
  -- t <- readInt
  -- replicateM t solve
  replicateM 1 solve
