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
local LED_PIN = 4

for i = 1, 100 do
    gpioSetLevel(LED_PIN, i % 2 == 0)
    print(fizzbuzz(i))
    sleep(1000)
end

print("Goodbye!")
sleep(10000)
