import sys
import random

random.seed(int(sys.argv[1]))

def randchr():
  return chr(ord('a')+random.randint(0, 25))

t = 100
print(t)
for ti in range(t):
  n = random.randint(90000, 100000)
  s = ''.join([randchr() for i in range(n//2)])
  s = s+(randchr() if n%2 == 1 else "")+s[::-1]
  print(n)
  print(s)