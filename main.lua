function fizzbuzz(i)
    if i % 15 == 0 then
        return "fizzbuzz"
    elseif i % 3 == 0 then
        return "fizz"
    elseif i % 5 == 0 then
        return "buzz"
    else
        return tostring(i)
    end
end

print("Hello")
local cores = getESPChipInfo()
print("I have "..tostring(math.floor(cores)).." cores")

sleep(1000)

for i = 1, 100 do
    print(fizzbuzz(i))
    sleep(100)
end

print("Goodbye!")
sleep(10000)
