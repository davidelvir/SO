--Problema 1
print("----------Problema 1----------")

Queue = {queue = {}}
function Queue:new()
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function Queue:enqueue(obj) --push
    table.insert(self.queue, obj)
end

function Queue:dequeue() --pop
    return table.remove(self.queue, 1)
end

function problema1()
    --crear queue de alumnos
    local alumnos = Queue:new()
    alumno1 = {"11641211", "David", "Ingeniería en Sistemas"}
    alumno2 = {"11431211", "Juan", "Gastronomía"}
    --insertar alumnos al queue
    alumnos:enqueue(alumno1)
    alumnos:enqueue(alumno2)

    --imprimir datos del alumno1
    tem = alumnos:dequeue()
    print("Número de cuenta", tem[1])
    print("Nombre del almuno", tem[2])
    print("Carrera del alumno", tem[3])
  
end
problema1()

print("----------Problema 2----------")
--problema 2
function problema2(...)
    result = ""
    local arg = {...}
    for i, v in ipairs(arg) do
        result = result .. tostring(v)
    end
    return result
end

print(problema2("hola", "como", "estas","hola","mundo"))
