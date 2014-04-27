--https://code.google.com/codejam/contest/889487/dashboard#s=p1

import Data.Map
import qualified Data.Map as Map
import Data.Maybe

getArgs str = Prelude.map (read :: String -> Integer) (words str)
getC ary i = fst (snd (ary !! i))
getS ary i = snd (snd (ary !! i))
calcHpy hpy now fut sat = hpy + (now - fut) * sat
i2d n = fromRational $ toRational $ fromIntegral n

calcNewKey key event
	| member key event = calcNewKey (key + 0.001) event
	| otherwise = key

multiInsert key value event = insert (calcNewKey key event) value event

addCoffee ary event now hpy sat e coffee j satdel satstart count
	| sat == 0 =
		if (now - c < 1) then passTime ary event now hpy s newCoffee (-1) now count
		else passTime ary newEvent now hpy s newCoffee newKey now count
	| s > sat =
		if (now - c < 1) then passTime ary (delete satdel event) now hpy s newCoffee (-1) now count
		else passTime ary (delete satdel newEvent) now hpy s newCoffee newKey now count
	| s == sat =
		if (satdel > 0) then
			let
				ndel = i2d ((floor satdel) - c)
			in
				if(0 < ndel) then passTime ary (insert ndel (1,sat) (delete satdel event)) now hpy s newCoffee ndel satstart count
				else passTime ary (delete satdel event) now hpy s newCoffee (-1) satstart count
		else
			if (now - c < 1) then passTime ary event now hpy s newCoffee (-1) satstart count
			else passTime ary newEvent now hpy s newCoffee newKey satstart count
	| otherwise = passTime ary event now hpy sat newCoffee satdel satstart count
	where
		newdel = i2d (now - c)
		newKey = calcNewKey newdel event
		newEvent = multiInsert newdel (1, s) event
		s = getS ary j
		c = getC ary j
		newCoffee = (insertWith (+) s c coffee)

removeCoffee ary event now hpy sat e coffee satdel satstart count
	| sat /= snd (snd e) = passTime ary event now hpy sat coffee satdel satstart count
	| Data.Map.size coffee == 1 = passTime ary event now hpy 0 newCoffee (-1) (-1) count
	| otherwise = let
		maxCoffee = findMax newCoffee
		s = fst maxCoffee
		c = snd maxCoffee
		newdel = i2d (now - c)
		newKey = calcNewKey newdel event
		in
			if (newdel < 1) then passTime ary event now hpy s newCoffee newKey now count
			else passTime ary (multiInsert newdel (1, s) event) now hpy s newCoffee newKey now count
	where
		newCoffee = delete sat coffee


passTime ary event now hpy sat coffee satdel satstart count
	| Data.Map.null event =
		if(sat == 0) then putStrLn $ "Case #" ++ show count ++ ": " ++ show hpy
		else putStrLn $ "Case #" ++ show count ++ ": " ++ show ( hpy + (min (now) (fromJust (Map.lookup sat coffee))) * sat)
	| otherwise =
		let
			i = fst (snd e)
			e = findMax event
			next = floor (fst e)
			in
				if(sat /= 0) then
					if (i == 0) then addCoffee ary (deleteMax event) next (calcHpy hpy now next sat) sat e (insertWith (+) sat (next - now) coffee) (fromIntegral (snd (snd e))) satdel satstart count
					else removeCoffee ary (deleteMax event) next (calcHpy hpy now next sat) sat e (insertWith (+) sat (next - now) coffee) satdel satstart count
				else
					if (i == 0) then addCoffee ary (deleteMax event) next hpy sat e coffee (fromIntegral (snd (snd e))) satdel satstart count
					else removeCoffee ary (deleteMax event) next hpy sat e coffee satdel satstart count

makeCoffee ary n event k count
	| 0 <= n = do
		[c, t, s] <- fmap getArgs getLine
		makeCoffee ( (t, (c, s)) : ary) (n - 1) (multiInsert (i2d t) (0, n) event) k count
	| otherwise = passTime ary event k 0 0 Data.Map.empty (-1) (-1) count



doIt m c
	| c <= m = do
		[n, k] <- fmap getArgs getLine
		makeCoffee ([] :: [(Integer, (Integer, Integer))]) (n - 1) Data.Map.empty k c
		doIt m (c + 1)
	| otherwise = return()

main = do
	l <- getLine
	doIt ((read :: String -> Int) l) 1