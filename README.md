# Hexagonal-Pathfinding
In the past few years, pathfinding algorithms have risen into prominence on  global scale. With use in various technologies like routing protocols in the internet, flight plan navigation, celestial body tracking and many more. Another very important use has been in cellular networks. A cellular network, also called mobile network, is a communication network where the last link is wireless. Rather than defining the path of connectivity, actual land areas covered as considered to be grids operating on certain frequencies.
These land areas are called cells, each served by at least one fixed-location transceiver called base stations.
![Rural Urban Zone](images/rural.png?raw=true)
The grid structure hence needs to be such that it satisfies all conditions and constraints required of a mobile network.
###1. Criteria for Grid Selection
####1.1 Frequency Re-use
Frequency reuse is the ability of the network to reuse frequencis to increase both the capacity as well as the coverage of the network. As it is noted that two adjacent cells cannot function on the same frequency, but two substantially far or non-adjacent grids can have the same frequency. So, frequency reuse is calculated using the reuse distance D, for a hexagonal structure as
![Frequency Re-Use](images/frequency-reuse.png?raw=true)
where R is equal to the cell radius and N is equal to the number of cells in a cluster.
####1.2 Coverage
One of the most vital aspect of cellular network is its coverage. In a mobile network you have to have all the spots covered in a specific cluster, leaving no blind spots between the cells.
####1.3 Connectivity
Connectivity of a cell can be defined as the number the average number of cells it can span over a specified number of jumps. Hence, more is the connectivity, better is the grid structure.
##2. Grid Selection
####2.1 Network on Circular/Elliptical Cells
Ideally, circular networks should have the best form of cells because usually Antennas are omni directional and circles don’t tesselate.
But a plethora of disadvantages and drawbacks makes it practically not feasible for cellular networks.
![Circular Ellpitical cells](images/circular.png?raw=true)
As shown in the figure, circular grids leave non- covered areas/ gaps in the structure which just cannot be afforded in cellular networks. Also, overlapping areas does work but it gets difficult to analyze them.
####2.2 Network on Square Cell Structure
As there are no blind spots left in a square structure, it does pretty well to overcome the drawbacks of a circular network.
But, the connectivity in a cellular network is not feasible for practical use due to its non-omnidirectional structure. The structure should be uniform in all directions and not just the x-axis and y-axis as in sqare structures.
![Square Structure](images/square.png?raw=true)
####2.3 Network on Hexagonal Cell Structure
Hexagonal shape is preferred over a square cell shape as it covers an entire area with comparatively lesser number of cells as compared to a square or a traingular structure.
Due to the uniform structure of a hexagon, the distances to the adjacent cells are same which makes the grids way more efficient for pathfindings.
![Hexagonal Design]()
##3. Algorithm
####3.1 Cube Design
![Cube Design](images/Cube-Design.png?raw=true)
####3.2 Fault Tolerance
It is vital to implement fault tolerance. The algorithm calculates whether the node is active or not before moving ahead for the path. This ensures that inactive nodes are discounted from the path.
####3.3 Algorithm Design
We use Breadth First Search to first find the cell that contains the destination user, and then, obtain a shortest path from the base station to that cell.
We implement BFS as:

![BFS](images/bfs.png?raw=true)

Now, we carry out an iterative algorithm where we calculate the distance from the current node to the destination and compare it with the current node’s neighbor’s distance from the distance node.
If the neighbor’s node’s distance is less than that of the current node, we traverse the neighbor and set it as current.

We carry on iterating until the current node becomes the destination node.

![algo](images/algo.png?raw=true)

Which can also be realized as an A* algorithm with a customized distance function as the heuristic function. This runs on a parallel loop for quickest result.

##Result

![result](images/result.png?raw=true)



