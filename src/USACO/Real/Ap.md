# A Plan
- Condensing grid into just cells may be helpful for debugging
- Some move cells require another move cell to be placed
- Total of 2^9 possible board configurations. 2^9 is only 512 so maybe check if a board state is possible using DFS?
    - Imagine I have a board state, how do I check it? Remove if it contains a cell that isn't in the grid. Check each M/O placed and check graph to see if anything in the component in not in the config.
- Sounds like a DFS/Flood-fill problem
- There may or may not be repeat moves in the grid.
- Each board config can be represented as 9 bits of trinary
- You need configurations not paths

## Strategy
- Use DFS/Flood-fill to build a dependency grph on which cells need other cells to be there first.
    - DFS maintaining a list of cells in the current recurrence and add this list to cells when you hit them
    - Time: O(V+E) should be fine
    - Space: idk? maybe fail here?

- Get all board configurations. For each config: O(512 * 9 * )
    - Check if it's winning and valid else discard
    - Check that all cells in config are at least in the haybale map
    - For each M/O (9 total max) in the config, check all dependendency paths to see if they are in the config.
    - If everything checks out, the board config should be reachable.

## Strategy
- For every reachable M on the board, run:
    - Get dependencies of the M and place them on the board. Then run a recursion to get all possible board end states. Try to "fill the gaps": for every board state that you just retrieved, go to each placing and get all such placings in the grid and see if something works. If it does, move to the next placing that hasn't been covered yet.

## Strategy
- Generate all valid board end state configurations which is < 512. For each config:
    - Pick a placing that hasn't been "satisfied" and get a list of cells with that coord.
    - Iterate and find something that works. When it works, mark everything in the dependency on the board as "satisfied". 
    - Go to the next satisfied cell and continue until all cells are satisfied.
    - Maybe sort by dependency size to optimize a bit?
- O(<512 * 9 * 625) = 1.8 * 10^9 max which could work
