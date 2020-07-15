using Plots
pyplot()

dimJulia_optim = Int64[];
timeJulia_optim = Float64[];

dimCPP_boost = Int64[];
timeCPP_boost = Float64[];

# read value
open("./MeasuredTime/time_quickSort.csv") do io
    readline(io);  # skip the header line
    for line in eachline(io)
        lang, algo, dim, time = split(line, ',')
		n = parse(Int64, dim)
		t = parse(Float64, time)
        if lang == "Julia" && algo == "quickSort_optim"
			push!(dimJulia_optim, n)
			push!(timeJulia_optim, t)
		elseif lang == "C++" && algo == "quickSort_boost"
			push!(dimCPP_boost, n)
			push!(timeCPP_boost, t)	
		end
    end
end

plot(title = "quickSort")
plot!(xlabel = "Size of the Array")
plot!(ylabel = "Time [s]")
plot!(grid = true)

plot!(dimJulia_optim, timeJulia_optim, label = "Julia_jway", markershape = :dtriangle)
plot!(dimCPP_boost, timeCPP_boost, label = "C++_boost", markershape = :star7)

# speichere Plots mit normaler und logarithmischer Y-Skala 
savefig("./Plots/quickSortTimeNormal.pdf")
savefig("./Plots/quickSortTimeNormal.png")

