import re

#IP Address Validation
#https://www.hackerrank.com/submissions/code/890170
def doIt():
	n = int(raw_input())
	ipv4 = r'([1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5]|\d{1,2})((\.([1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5]|\d{1,2})){3})';
	ipv6 = r'([0-9a-f]{1,4})((:([0-9a-f]{1,4})){7})';
	for i in range(0,n):
		s = raw_input()
		res = re.match(ipv4, s)
		if res != None and res.span()[0] == 0 and res.span()[1] == len(s):
			print "IPv4"
		else:
			res = re.match(ipv6, s)
			if res != None and res.span()[0] == 0 and res.span()[1] == len(s):
				print "IPv6"
			else:
				print "Neither"

doIt()
