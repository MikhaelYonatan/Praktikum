module SecondLargest where

maxList :: [Int] -> Int
maxList l =
  if null (tail l) then
    head l
  else
    let 
      big = maxList (tail l)
    in
      if (head l > big) then
        head l
      else
        big

del :: [Int] -> Int -> [Int]
del l n =
  if (null l) then
    l
  else
    if (head l /= n) then
      [head l] ++ del (tail l) n
    else
      del (tail l) n


secondLargest :: [Int] -> Int
secondLargest l =
  maxList (del l (maxList l))