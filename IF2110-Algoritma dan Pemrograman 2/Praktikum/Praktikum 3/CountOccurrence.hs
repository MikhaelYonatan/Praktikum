module CountOccurrence where

-- count(ListOfList, n) menghitung berapa kali integer n muncul di dalam sebuah list of list.
-- CONTOH: count [[1,2,1],[3],[1,4]] 1 menghasilkan 3
count :: [[Int]] -> Int -> Int
count ll x =
    if null ll then 0
    else 
        if null (head ll) then count (tail ll) x
        else
            let count2 a b =
                    if null a then 0
                    else (if (head a) == b then 1 else 0) + count2 (tail a) b
            in count2 (head ll) x + count (tail ll) x