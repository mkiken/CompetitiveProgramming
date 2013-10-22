#http://www.codechef.com/FEB13/problems/LECARDS/
#but TLE with Ruby

class CC_LECARDS
  BASE = 1000000007
  #function pow from Submission #49565
  def pow(n,p)
    ans = 1
    while p!=0 do
      ans = ans*n%BASE if p&1==1
      n=n*n%BASE
      p=p>>1
    end
    ans
  end
  def combi n,k
    if n - k < k
      a = n - k
    else a = k
    end
    m = 1
    c = 1
    for i in 0..a-1
      m = (m * (n - i)) % BASE
      c = (c * (a - i)) % BASE
    end
    (m * pow(c,(BASE - 2))) % BASE
  end
  def doIt
    t = gets.to_i
    for i in 1..t
      n = gets.to_i
      gets
      ans = 0
      half = n / 2.0
      counter = 0
      while(counter < half)
        ans += combi n,counter
        ans %= BASE
        counter += 1
      end
      puts ans
    end
  end
end
CC_LECARDS.new.doIt
