include("../dimension.jl")
using Printf

function swap(list::Array{Int32, 1}, x, y)
	list[x], list[y] = list[y], list[x]
end

function partition(list::Array{Int32, 1}, left, right)
	i = left -1
	x = list[right]
	for j = left:right-1
		if list[j] <= x
			i += 1
			swap(list, i, j)
		end
	end
	swap(list, i+1, right)
	return i+1
end

function quickSort(list::Array{Int32, 1}, left, right)
	stack = zeros(Int32, right - left + 1)
	top = 0
	top = top + 1
	stack[top] = left
    top = top + 1
	stack[top] = right
	while top >= 1
		right = stack[top]
		top -= 1
		left = stack[top]
		top -= 1
		pivot = partition(list, left, right)
		if pivot-1 > left
			top += 1
			stack[top] = left
			top += 1
			stack[top] = pivot -1
		end
		if pivot+1 < right
			top += 1
			stack[top] = pivot+1
			top += 1
			stack[top] = right
		end
	end
end

function printSolution(list::Array{Int32, 1}, n::Int32)
	for i = 1:n
		print(list[i])
		if i != n
			print(",")
		end
	end
	println()
end

function execute()  
	n = getDimension()
	print(stderr, "Julia,quickSort,$n,");  # use default delimiter
	arr = zeros(Int64, n)
	for i = 1:n
		arr[i] = (777*(i-1)) % 10000
	end
	if n > 0
		quickSort(arr, 1, n)
	end
	if n > 0 && n < 1000000
		printSolution(arr, n)
	end
end

# executing ...
execute()
	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
	
		
	

