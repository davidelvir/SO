longitud::[a]->Int
longitud [] = 0
longitud x = 1 + (longitud (tail x))

suma::[Int]->Int
suma [] = 0
suma x = (head x) + (suma(tail x))

minim :: [Int] -> Int
minim []       = 0
minim [x]      = x
minim (x:xs)   = mini x (minim xs)

mini :: Int -> Int -> Int
mini a b
    | a > b  = b
    | a < b  = a
    | a == b = a
reversa::[a]->[a]
reversa[]=[]
reversa[x] = [x]
reversa x = reversa (tail x) ++ [(head x)]

cuadrados::Int->Int
cuadrados 0 = 0
cuadrados x = (x*x) + cuadrados(x-1)
main = do 
    print(longitud [2,4,4,5,6,7,4,4])
    print(suma [2,4,4,5,6,7,4,4])
    print(minim [2,4,4,5,6,7,4,4])
    print(reversa [2,4,4,5,6,7,4,4])
    print(cuadrados 6)

