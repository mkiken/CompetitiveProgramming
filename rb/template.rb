def getInts()
    gets.split.map(&:to_i)
end

def printArray(list)
    list.each_with_index{|elem, i|
        print list[i], i == list.length-1 ? "\n" : ' '
    }
end


def doIt()
end

doIt
