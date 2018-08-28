for i = 1, 10, 1 do
    print("Hello Make Tech Easier: ", i)
end

array = {}

for i = -2, 2 do
    array[i] = i * 2
end

for i = -2, 2 do
    print(array[i])
end

array2 = {}

for i = 1, 3 do
    array2[i] = {}

    for j = 1, 3 do
        array2[i][j] = i * j
    end
end

-- Accessing the array

for i = 1, 3 do
    for j = 1, 3 do
        print(array2[i][j])
    end
end

function max(num1, num2)
    if (num1 > num2) then
        result = num1
    else
        result = num2
    end

    return result
end

print("Ingrese un número: ")
num = io.read("*n")
print("The maximum of the two numbers is:",max(num,4))