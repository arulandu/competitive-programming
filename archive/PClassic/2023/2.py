def pathExists(w,h,portalArr):
    q = []
    visited = set()
    color_d = dict()
    coord_d = dict()
    for x,y,c in portalArr:
        if c not in color_d:
            color_d[c] = []
        color_d[c].append((x,y))
        if y not in coord_d:
            coord_d[y] = []
        coord_d[y].append((x,c))
    q.append((0,0))
    while(q):
        x,y = q.pop(0)
        # print(x,y)
        if y == h-1:
            return True
        if y in coord_d:
            for x1,c1 in coord_d[y]:
                if x1 >= x:
                    for x2,y2 in color_d[c1]:
                        if (x2,y2) not in visited:
                            q.append((x2,y2))
                            visited.add((x2,y2))
                            # print("debug:",color_d[c1])
                            color_d[c1].remove((x2,y2))
                            # print("debug:",color_d[c1])
                    # print("debug:",coord_d[y])
                    # coord_d[y].remove((x1,c1))
                    # print("debug:",coord_d[y])

    return False

print(pathExists(5, 5,
[(2, 0, 1),
(2, 1, 3),
(1, 2, 1),
(3, 2, 2),
(1, 3, 3),
(3, 3, 2),
(2, 4, 3)])
)

print(pathExists(2, 2,
[(0, 1, 0)])
)

print(pathExists(5, 1,
[(1, 0, 0),
(2, 0, 0)
])
)

print(pathExists(4, 3,
[(1, 0, 0),
(1, 2, 0),
(2, 0, 1),
(3, 1, 1)])
)