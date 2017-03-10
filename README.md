# Steiner-Tree-simulations


A description of the NP-hard Steiner tree problem can be found in wikipedia

https://en.wikipedia.org/wiki/Steiner_tree_problem

A general approach:

The algorithm starts with finding individual polygons among the sets of vertices. It is easy to build steiner trees inside such convex ploygon subgraph. However, finding the set of individual convex ploygons that lead to a minimal Steiner tree is itself a NP-hard process. I am currently working on devising a maching learning agent that is trained on the common patterns of Steiner trees of smaller number of vertices. The methods of finding such patterns has already been articulated by Warren D. Smith in his article How to find Steiner minimal trees in euclideand-space (Smith, W.D. Algorithmica (1992) 7: 137. doi:10.1007/BF01758756).
