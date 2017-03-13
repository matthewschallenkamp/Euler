-- 80 numbers per line, 80 lines

-- List implementation from lua.org
List = {}
function List.new ()
  return {first = 0, last = -1}
end
function List.pushleft (list, value)
  local first = list.first - 1
  list.first = first
  list[first] = value
end

function List.pushright (list, value)
  local last = list.last + 1
  list.last = last
  list[last] = value
end

function List.popleft (list)
  local first = list.first
  if first > list.last then error("list is empty") end
  local value = list[first]
  list[first] = nil        -- to allow garbage collection
  list.first = first + 1
  return value
end

function List.popright (list)
  local last = list.last
  if list.first > last then error("list is empty") end
  local value = list[last]
  list[last] = nil         -- to allow garbage collection
  list.last = last - 1
  return value
end

cost = {}
for i = 1, 80 do
	cost[i] = {}
	for j = 1, 80 do
		cost[i][j] = io.read("n")
		-- io.write(cost[i][j])
		-- io.write(" ")
	end
	-- io.write("\n")
end

to = {}
for i = 1, 80 do
	to[i] = {}
	for j = 1, 80 do
		to[i][j] = 10000000000000000 -- infinity
	end
end

to[1][1] = cost[1][1]

spots = List.new()

List.pushright(spots, {x = 1, y = 1})

while spots.first <= spots.last do
	--update in the 4 directions if possible
	--add them if they have changed
	pair = List.popleft(spots)
	if pair.x > 1
		then if to[pair.x][pair.y] + cost[pair.x-1][pair.y] < to[pair.x-1][pair.y]
			then
			to[pair.x-1][pair.y] = to[pair.x][pair.y] + cost[pair.x-1][pair.y]
			List.pushright(spots, {x = pair.x-1, y = pair.y})
		end
	end

	if pair.x < 80
		then if to[pair.x][pair.y] + cost[pair.x+1][pair.y] < to[pair.x+1][pair.y]
			then
			to[pair.x+1][pair.y] = to[pair.x][pair.y] + cost[pair.x+1][pair.y]
			List.pushright(spots, {x = pair.x+1, y = pair.y})
		end
	end

	if pair.y > 1
		then if to[pair.x][pair.y] + cost[pair.x][pair.y-1] < to[pair.x][pair.y-1]
			then
			to[pair.x][pair.y-1] = to[pair.x][pair.y] + cost[pair.x][pair.y-1]
			List.pushright(spots, {x = pair.x, y = pair.y-1})
		end
	end

	if pair.y < 80
		then if to[pair.x][pair.y] + cost[pair.x][pair.y+1] < to[pair.x][pair.y+1]
			then
			to[pair.x][pair.y+1] = to[pair.x][pair.y] + cost[pair.x][pair.y+1]
			List.pushright(spots, {x = pair.x, y = pair.y+1})
		end
	end
end

print(to[80][80])