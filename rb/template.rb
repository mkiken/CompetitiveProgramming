require 'mathn'

def getInts()
  gets.split.map{|i| i.to_i}
end

def pAry(list)
  list.each_with_index{|elem, i|
    print list[i], i == list.length-1 ? "\n" : ' '
  }
end

def solve()
end

def doIt()
  t = 1
  # t = gets.to_i
  t.times{
    solve
  }
end

# doIt
solve
