include("../dimension.jl")
using Printf

function execute()  
	n = getDimension()
	print(stderr, "Julia,quickSort_optim,$n,");  # use default delimiter
	arr = zeros(Int32, n) 
	for i = 1:n
		arr[i] = n - i + 1  # [n, ..., 1]  worst case
	end
	if n > 0
		sort!(arr; alg=QuickSort)
	end
end

# executing ...
execute()
	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
	
		
	

