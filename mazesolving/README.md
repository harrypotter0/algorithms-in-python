# mazesolving
A variety of algorithms to solve mazes from an input image.

# Input Example 

  python -m mazeProblem.png mazeSolution.png 


- The data structures and representations can probably be improved for speed - I only focused a little on efficiency. Mostly I wanted to keep memory usage down, to allow the use of very large mazes.
- The very large mazes use a lot of ram. If you don't have 16Gb at least for the 10k+ x 10k+ mazes, you may run out of memory!
- The current format of the test mazes (short paths, very dense) means that in fact dijkstra and a* usually operate more slowly than simple algorithms. In these cases Dijkstra usually performs the same function as breadth first search, but with more computational overhead. There will be some forms of maze where they are significantly faster.
- Mazes don't need to be square - as long as they are surrounded by black walls. The input image will obviously be square.
- Large areas of white, using my algorithm, will essentially degenerate into an inefficient flood fill - avoid!

