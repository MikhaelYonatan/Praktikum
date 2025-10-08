module ColumnOperations where

konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

-- REALISASI
konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

solver :: [[Int]] -> [Int]
solver matriks
  | null matriks = []
  | isEmpty (head matriks) = []
  | otherwise = let h = map last matriks
                    t = map init matriks
                    getMax l1 =
                        if null (tail l1) then head l1
                        else
                            let tmax = getMax (tail l1)
                            in if (head l1) > tmax then (head l1) else tmax
                    getMin l1 =
                        if null (tail l1) then head l1
                        else
                            let tmin = getMin (tail l1)
                            in if (head l1) < tmin then (head l1) else tmin
                    
                in
                    if (length (last t)) `mod` 3 == 0 then konso (getMax h) (solver t)
                    else if (length (last t)) `mod` 3 == 1 then konso (getMin h) (solver t)
                    else konso (sum h) (solver t)
-- Lengkapi Fungsi di bawah ini
columnOperations :: [[Int]] -> [Int]
columnOperations matriks = reverse (solver matriks)
