-- Portfolio Management System with Lambda Functions and Higher-Order Functions
module Portfolio where

-- Data type for Person in Portfolio
data Person = Person 
    { name :: String
    , age :: Int  
    , balance :: Double
    } deriving (Show, Eq)

-- Type alias for Portfolio (list of persons)
type Portfolio = [Person]

-- Constructor function using lambda
-- Hint: Kembalikan tipe bentukan Person yang telah terinisialisasi
-- name, age, balance -> Person
makePerson :: String -> Int -> Double -> Person
makePerson = \name age balance -> Person name age balance
    -- TODO: Implementasikan fungsi lambda makePerson di sini

-- Transfer function using lambda and higher-order functions
transfer :: String -> String -> Double -> Portfolio -> Portfolio
transfer fromName toName amount portfolio = 
    let updatePerson = \p -> 
            if name p == fromName then p { balance = balance p - amount }
            else if name p == toName then p { balance = balance p + amount }
            else p
    in map updatePerson portfolio
    
-- Withdraw function using lambda
-- name, amount, portfolio -> updated portfolio
--
-- Fungsi withdraw mengurangi saldo (balance) dari person dengan {nama} tertentu sebanyak {amount}
-- 
-- Hint: Gunakan fungsi map dan lambda
withdraw :: String -> Double -> Portfolio -> Portfolio  
-- TODO: Implementasikan fungsi withdraw di sini
withdraw nama amount portfolio =
    let updatePerson = \p -> 
            if name p == nama then p { balance = balance p - amount }
            else p
    in map updatePerson portfolio

-- Deposit function using lambda
-- name, amount, portfolio -> updated portfolio
--
-- Fungsi deposit menambah saldo (balance) dari person dengan {nama} tertentu sebanyak {amount}
-- 
-- Hint: Gunakan fungsi map dan lambda
deposit :: String -> Double -> Portfolio -> Portfolio
-- TODO: Implementasikan fungsi deposit di sini
deposit nama amount portfolio =
    let updatePerson = \p -> 
            if name p == nama then p { balance = balance p + amount }
            else p
    in map updatePerson portfolio

-- Generic sorting function that takes a comparison function as parameter
sortBy :: (Person -> Person -> Ordering) -> Portfolio -> Portfolio
sortBy compareFunc [] = []
sortBy compareFunc (x:xs) = 
    let smaller = sortBy compareFunc (filter (\y -> compareFunc y x == LT) xs)
        equal = filter (\y -> compareFunc y x == EQ) xs  
        greater = sortBy compareFunc (filter (\y -> compareFunc y x == GT) xs)
    in smaller ++ [x] ++ equal ++ greater

-- Sort by name using lambda for comparison
-- Hint: Gunakan compare dan lambda
sortByName :: Portfolio -> Portfolio
sortByName = \porto -> sortBy (\p1 p2 -> compare (name p1) (name p2)) porto

-- Sort by age using lambda for comparison  
-- Hint: Gunakan compare dan lambda
sortByAge :: Portfolio -> Portfolio
sortByAge = \porto -> sortBy (\p1 p2 -> compare (age p1) (age p2)) porto

-- Sort by balance using lambda for comparison
-- Hint: Gunakan compare dan lambda
sortByBalance :: Portfolio -> Portfolio
sortByBalance = \porto -> sortBy (\p1 p2 -> compare (balance p1) (balance p2)) porto
