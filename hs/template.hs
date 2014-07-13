import Control.Applicative
import Control.Monad
--import Data.Char
--import Data.Time.Calendar
import Data.List as List
import Data.Maybe
import Text.Printf
-- import qualified Data.ByteString.Char8 as B
import qualified Data.Map as Map
import Data.Bits
import Debug.Trace

rsort :: [Int] -> [Int]
rsort = sortBy (\x y -> compare y x )
mjoin sp ary = intercalate sp (map show ary)
count p ls = (length . filter p) ls
readInt = (read :: String -> Int) <$> getLine
readInts = map (read :: String -> Int) . words <$> getLine
a % b = mod a b
a // b = div a b
a != b = a /= b



solve = do
  print 1


main = do
  -- t <- readInt
  -- replicateM t solve
  replicateM 1 solve
