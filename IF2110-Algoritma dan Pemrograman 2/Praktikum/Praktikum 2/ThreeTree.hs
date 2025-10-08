module ThreeTree where

threeTree :: [Int] -> [Int]
threeTree l =
    if (null l) then []
    else
        if (mod (head l) 3 == 0) then 
             [(head l)] ++ (threeTree (tail l))
        else 
            threeTree (tail l)
