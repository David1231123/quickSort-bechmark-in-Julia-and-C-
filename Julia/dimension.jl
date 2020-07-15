# lese Dimension ein

function getDimension()   
    open("./../dim.txt") do file
        return parse(Int32, readuntil(file, " "))
    end
end
