def getInts()
    gets.split.map(&:to_i)
end

def printArray(list)
    list.each_with_index{|elem, i|
        print list[i], i == list.length-1 ? "\n" : ' '
    }
end

def solve()
end

def doIt()
  t = gets.to_i
  t.times{
    solve
  }
end

# doIt
solve
