require "date"

ss1 = gets.split(":").map{|s| s.to_i}
ss2 = gets.split(":").map{|s| s.to_i}
d1 = Date.new(ss1[0],ss1[1],ss1[2])
d2 = Date.new(ss2[0],ss2[1],ss2[2])
sa = d2 - d1
puts sa.to_i.abs
