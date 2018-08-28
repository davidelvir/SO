--problema 1
esPermutacion::[Int]->[Int]->Bool
esPermutacion x y = if qsort x == qsort y then True else False

qsort::[Int]->[Int]
qsort [] = []
qsort (x:xs) = qsort small ++ mid ++ qsort large
  where
    small = [y | y<-xs, y<x]
    mid   = [y | y<-xs, y==x] ++ [x]
    large = [y | y<-xs, y>x]
--
--problema 2
mult::Int->Int->Int
mult a 0 = 0
mult 0 b = 0
mult a b = a + mult a (b-1)

main = do
    putStrLn("Ejercicio 1")
    putStrLn("La lista: " ++ "[1,2,2,3,4,4]"++" es permutación de: "++"[1,3,3,2,1,4] ?")
    print(esPermutacion [1,2,2,3,4,4] [1,3,3,2,1,4])
    putStrLn("La lista: " ++ "[1,2,1]"++" es permutación de: "++"[2,1,1] ?")
    print(esPermutacion [1,2,1] [2,1,1])
    putStrLn("La lista: " ++ "[1,2,2,3,4,4]"++" es permutación de: "++"[2,4,3,2,1,4] ?")
    print(esPermutacion [1,2,2,3,4,4] [2,4,3,2,1,4])
    putStrLn("Ejercicio 2")
    putStrLn("La multipicación de 4 y 7 es:")
    print(mult 4 7)
    putStrLn("La multipicación de 6 y 9 es:")
    print(mult 6 9)
