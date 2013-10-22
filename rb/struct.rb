#AOJ1043 Selecting Teams Advanced to Regional

class Q1043
  def makeTeam n,team
    ary = Array.new(n)
    for i in 0..n-1
      s = gets.split(" ").map {|x| x.to_i}
      ary[i] = team.new(s[0], s[1], s[2], s[3])
    end
    ary = ary.sort{|a, b| (b.a == a.a) ? ((b.p == a.p) ? a.i <=> b.i : a.p <=> b.p) : b.a <=> a.a }
    mem = Array.new(1001, 0)
    sum = 0
    for i in 0..n-1
      if sum < 10 then
        if mem[ary[i].u] < 3 then
          sum += 1
          mem[ary[i].u] += 1
          puts ary[i].i
        end
      elsif sum < 20 then
        if mem[ary[i].u] < 2 then
          sum += 1
          mem[ary[i].u] += 1
          puts ary[i].i
        end
      elsif sum < 26 then
        if mem[ary[i].u] < 1 then
          sum += 1
          mem[ary[i].u] += 1
          puts ary[i].i
        end
      end
    end
  end

  def doIt
    n = gets.to_i
    team = Struct.new("Team", :i, :u, :a, :p)
    while n > 0
      makeTeam n,team
      n = gets.to_i
    end
  end
end

Q1043.new.doIt
