# OptGraph
Mathworks software engineer c++ offline programing problem\
(console timing text at the bottom as well see images)

My solution was to use unordered STL containers. The Graph container is an unordered map. The key for the map is the unique 
block name while the value is pointer to the block. Block pointers are created in the main class and passed into the graph class
where they are given a unique name. After a unique name is specifed ownership of the block is passed to the graph container.

The Block class consist of your standard get/set for names and attributes. The underlying attributes container in the block class
is built with an unordered multiset. The decision to use this was based on the rule of unique name order does not matter, nor does
uniqueness need to be checked. Thus multiple of the same attribute name could be added and a multiset of this container was needed.

I am sure there are other solutions to this problem. This problem solution's run speed has nearly been increased by 100 times using
these unorder collections. I always try to apply solutions where the Standard Library is doing the heavy lifting of underlying container 
management. I believe there is always a time and place for such solutions and this is not one of them.

Below is a list of the instructions given in the main fle of the program.

This program is very simple. It contains two classes: Block and Graph.

- Graphs are responsible for ownership of a collection of Blocks.
- Blocks have two pieces of data: A name (std::string) and collection of (std::string) attributes.

This Graph class supports two operations:

1. Add a Block to the Graph (AddBlock)
- When a Block is added to a Graph, it cannot share a name with any Blocks already in the Graph. If the Block's name is
already elsewhere in the graph, its name will be modified to be unique. If the block's name is already unique, it must
not be changed.
- Calling AddBlock is resource acquisition. When it comes to data management, the Graph is the owner of the Block from
this point on.
- The order of blocks in a graph does not need to be preserved.

2. Return a collection of every Block in the Graph that has a specified attribute (GetBlocksWithAttribute)

- Blocks can have any number of attributes. Attributes of a block are assumed to be unique but it is not necessary to
  validate that. The order of attributes in a block does not need to be preserved.

There are functions below prefixed with Measure_. These _Measure functions exercise the two Graph operations previously
discussed. The goal of this exercise is to optimize the execution time of these functions:

- Measure_AddBlocks
- Measure_FindAttributesByBlock
- Measure_FindBlocksByAttribute

If you take a look at main() below, you'll see that it sends the execution time of these functions to stdout. Go ahead and
run the program as-is and it's obvious that the initial performance of these operations is very bad. If it doesn't build or
run, fix it so it does.

The program is also written very badly in many ways.

Goal: See how much better you can make it both in performance and coding style and best practices.
For reference, good solutions are able to speed up the execution time of the whole program by well
over 100 times without sacrificing code clarity or correctness.

Here are the rules:

- The dynamic behavior of the code cannot change. Don't just write code to generate the expected output, expect your solution
to be tested on different datasets.
- You ARE NOT allowed to modify the Measure_ functions or main() except to make them compile and run.
- You ARE allowed to modify the Block and Graph classes. Feel free to change the API, data structures, etc. as long as you can
do so without requiring a modification of Measure_ functions or main().
- Feel free to use any C++11 and C++14 language features, so long as they are supported on any platform. That means
  restricting yourself the standard library, and avoiding any platform-specific extensions.
- Feel free to make any obvious, simple improvements generally.

When you're done, please send me three things:

- Your modified OptGraph.cpp file. Please add a comment tagging where you've made changes.
- A copy/paste of the program output before and after you made your changes.
- A brief description of the changes that you made.

Good luck, and feel free to get in touch if you have any specific questions.


Optimzed:\
Measure_AddBlocks took: 1131ms.\
Measure_FindAttributesByBlock took: 33ms.\
Measure_FindBlocksByAttribute took: 951ms.\
Total program time: 2115ms.\
