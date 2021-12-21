from collections import deque, defaultdict

n, m = input().strip().split(' ')
n, m = int(n), int(m)

grid = [[0 for _ in range(m)] for _ in range(n)] # 1: wall, 2: poached, 0: unpoached, 3: goal

q, bq = deque(), deque()
boris = None

for i in range(n):
  s = input().strip()
  for j, c in enumerate(s):
    if c == '#':
      grid[i][j] = 1
    elif c == 'P':
      grid[i][j] = 2
      q.append((i, j))
    elif c == '-':
      grid[i][j] = 3 if i == 0 or i == n-1 or j == 0 or j == m-1 else 0
    elif c == 'B':
      grid[i][j] = 0
      boris = (i, j)
      bq.append((i, j))

def neigh(pt):
  ns = [
    (pt[0]-1, pt[1]),
    (pt[0]+1, pt[1]),
    (pt[0], pt[1]-1),
    (pt[0], pt[1]+1)
  ]

  return [p for p in ns if p[0] >= 0 and p[0] < n and p[1] >= 0 and p[1] < m and grid[p[0]][p[1]] != 1]

visited = defaultdict(tuple)

found = None
d = 0
while found is None:
  level = len(q)
  for _ in range(level):
    p = q.popleft()
    grid[p[0]][p[1]] = 2
    
    for ne in neigh(p):
      if grid[ne[0]][ne[1]] != 2:
        q.append(ne)

  level = len(bq)
  if level == 0:
    break

  for _ in range(level):
    p = bq.popleft()
    if grid[p[0]][p[1]] == 3:
      found = p
      break

    for ne in neigh(p):
      if ne not in visited:
        bq.append(ne)
        visited[ne] = p
    
  d += 1

if found is None:
  print('NO')
  exit()

path = []
p = found
while p != boris:
  path.append(p)
  p = visited[p]

path.append(boris)
path = path[::-1]

dirs = []
for i, p in enumerate(path):
  if i == len(path)-1:
    break

  if path[i+1][1] == path[i][1]+1:
    dirs.append('E')
  elif path[i+1][1] == path[i][1]-1:
    dirs.append('W')
  elif path[i+1][0] == path[i][0]-1:
    dirs.append('N')
  elif path[i+1][0] == path[i][0]+1:
    dirs.append('S')

print('YES')
print(''.join(dirs))
exit()
