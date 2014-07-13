require 'mathn'

# https://www.hackerrank.com/contests/infinitum-jul14/challenges/sherlock-and-divisors
def solve()
  n = gets.to_i
  if n == 1
    puts 0
    return
  end
  divs = n.prime_division
  ans = 0
  if divs[0][0] == 2
    ans = divs[0][1]
    for i in 1..divs.length-1
      ans *= divs[i][1] + 1
    end
  end
  puts ans
end

def doIt()
  t = gets.to_i
  t.times{
    solve
  }
end

doIt
