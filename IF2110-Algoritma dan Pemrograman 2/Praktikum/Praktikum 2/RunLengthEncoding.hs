module RunLengthEncoding where

runLengthEncoding :: String -> [(Char, Int)]
runLengthEncoding s =
  if (length s == 1) then
    [(head s, 1)]
  else
    let
      l = runLengthEncoding (tail s)
      (huruf, banyak) = head l
    in
      if (head s == huruf) then
        [(huruf, banyak + 1)] ++ tail l
      else
        [(head s, 1)] ++ l
