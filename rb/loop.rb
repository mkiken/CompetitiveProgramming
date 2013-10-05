#http://www.codechef.com/SEPT13/problems/CAOS1
def doIt
	field = Array.new(50)
	t = gets.to_i
	t.times{
		ans = 0
		inp = gets.split.map{|e| e.to_i}
		r = inp[0]
		c = inp[1]
		r.times{ |ii|
			field[ii] = gets
		}
		for i in 0..r-1
			for j in 0..c-1
				if field[i][j] == '^'
					ele = 0
					(i+1).upto(i+2){|ii|
						ele+=1 if (ii<r && field[ii][j] == '^')
					}
					(i-1).downto(i-2){|ii|
						ele+=1 if (0 <= ii && field[ii][j] == '^')
					}
					(j+1).upto(j+2){|jj|
						ele+=1 if (jj<c && field[i][jj] == '^')
					}
					(j-1).downto(j-2){|jj|
						ele+=1 if (0<= jj && field[i][jj] == '^')
					}
					ans+=1 if ele==8
				end
			end
		end
		puts ans
	}
end

doIt
