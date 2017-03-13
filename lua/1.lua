-- Find the sum of all the multiples of 3 or 5 below 1000.

num = 1
sum = 0
while num < 1000 do
  if num % 5 == 0 or num % 3 == 0
  	then
  	sum = sum + num
  end
  num = num + 1
end
print(sum)