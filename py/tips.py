# ABC#01 D
# http://abc001.contest.atcoder.jp/submissions/109841

def round5bef(t):
	d = t % 10
	if(d < 5):
		return t - d
	else:
		return t - (d - 5)

def round5aft(t):
	d = t % 10
	ret = 0
	if(d == 0):
		return t
	elif(d <= 5):
		ret =  t + (5 - d)
	else:
		ret =  t + (10 - d)
	if(ret % 100 == 60):
		ret = ret + 40
	return ret

def time2str(s, t):
	return '%04d-%04d' % (s, t)

def doIt():
	n = int(raw_input())
	pos = 0
	ls = []
	for i in range(0,n):
		time = map(int, raw_input().split('-'))
		ls.append([round5bef(time[0]), round5aft(time[1])])
		#print time
	list.sort(ls)
	ans = [[ls[0][0], ls[0][1]]]
	for i in range(1,n):
		if ls[i][0] <= ans[pos][1]:
			if ans[pos][1] < ls[i][1]:
				ans[pos][1] = ls[i][1]
		else:
			pos = pos + 1
			ans.append([ls[i][0], ls[i][1]])

	for i in range(0, pos+1):
		print time2str(ans[i][0], ans[i][1]) 
	#print ls
	#print ans

doIt()
#print(round5aft(1125))
