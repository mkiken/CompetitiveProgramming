N = 30
$c = Array.new(N+2).map{Array.new(N+2, -1)}
def combi(n, k)
  return $c[n][k] if $c[n][k] != -1
  return $c[n][k] = 1 if k == 0 or n == k
  $c[n][k] = combi(n-1, k-1) + combi(n-1, k)
  $c[n][k]
end

ans = 0
for woman in 0..(N / 2 + N % 2)
  man = N - woman
  ans += combi(man + 1, woman)
end

puts ans
