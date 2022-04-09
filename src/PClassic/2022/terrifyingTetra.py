# Contest: PClassic 2022
# Problem: [L] Terrifying Tetra
#
# Approach:
# Computational geometry to bash the 6 planes and concurrency point.
# Used Cramer's Rule, determinants, and math. Checked by plotly graphing.
#
# Complexity: O(1)

def terrifyingTetra(ps):
  # find equation of plane passing through A and perpendicular to segment BC
  def plane(a, b, c):
    # compute normalized normal vector
    norm = [c[i]-b[i] for i in range(3)]
    mag = sum([x**2 for x in norm])
    norm = [x/mag for x in norm]

    # ax + by + cz + d = 0
    d = -sum([a[i]*norm[i] for i in range(3)])
    return [norm[0], norm[1], norm[2], d]

  # 3D determinant
  def det3(mat):
    d = 0
    d += mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])
    d += -mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])
    d += mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0])
    return d

  # find point of concurrency of 3 planess
  def trisect(p1, p2, p3):
    # matrix equation
    A = [p1[:3], p2[:3], p3[:3]]
    b = [-p1[3], -p2[3], -p3[3]]
    detA = det3(A)
    if detA == 0: return None

    # replace ith column of A with b
    def repl(i):
      Ai = [p1[:3], p2[:3], p3[:3]]
      for r in range(3): Ai[r][i] = b[r]
      return Ai

    # Cramer's Rule
    sect = [0, 0, 0]
    for i in range(3):
      comp = det3(repl(i))/det3(A)
      sect[i] = comp
    
    return sect

  # for each side: find plane passing through midpoint that is perpendicular to opposite side
  planes = []
  for a in range(4):
    for b in range(a+1, 4):
      c, d = [x for x in range(4) if x != a and x != b]
      p = plane([(ps[a][i]+ps[b][i])/2 for i in range(3)], ps[c], ps[d])
      planes.append(p)

  # find trisection (point of concurrency) of any 3 valid planes
  conc = None
  for i in range(len(planes)):
    for j in range(i+1, len(planes)):
      for k in range(j+1, len(planes)):
        conc = trisect(planes[i], planes[j], planes[k])
        if conc is not None: break

  return conc

# Do not modify below this line
if __name__ == '__main__':
    tests = int(input())
    for test in range(tests):
        points = [[0, 0, 0] for _ in range(4)]
        for i in range(4):
            point = input()
            split = point.split()
            for j in range(3):
                points[i][j] = float(split[j])
        output = terrifyingTetra(points)
        s = ""
        for i in range(len(output)):
            s += str(round(output[i] * 10.0) / 10.0) + " "
        print(s[:-1])