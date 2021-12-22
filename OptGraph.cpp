#include "Graph.h"

/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// DO NOT MODIFY ANY CODE BELOW THIS POINT
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

static const int s_blockQuantity = 1000;
static const int s_attributesPerBlock = 250;

static const int s_distinctAttributes = 300;
static const int s_distinctBlockNames = 10;
static std::string s_blockBaseName("blockNameBase_");
static std::string s_attrBaseName("attributeBase_");

static std::vector<std::string> s_attrs;
static std::vector<std::string> s_blockNames;

void createBlockNames() {
    std::ostringstream s;
    for (int i = 0; i < s_distinctBlockNames; ++i) {
        s << s_blockBaseName;
        s_blockNames.push_back(s.str());
    }
}

void createAttrNames() {
    for (int i = 0; i < s_distinctAttributes; ++i) {
        std::ostringstream s;
        s << s_attrBaseName << i;
        s_attrs.push_back(s.str());
    }
}

std::chrono::milliseconds Measure_AddBlocks(Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    int blockNameNum = 0;
    int attrNum = 0;

    for (int i = 0; i < s_blockQuantity; ++i)
    {
        blockNameNum = ++blockNameNum % s_distinctBlockNames;

        Block* b = new Block;
        b->SetName(s_blockNames[blockNameNum]);
        for (int j = 0; j < s_attributesPerBlock; ++j)
        {
            attrNum = ++attrNum % s_distinctAttributes;
            b->AddAttribute(s_attrs[attrNum]);
        }
        graph.AddBlock(b);
    }
    auto end = std::chrono::system_clock::now();

    // Post-measurement verification

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

std::chrono::milliseconds Measure_FindAttributesByBlock(Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    int compareLength = s_attrBaseName.length();

    for (auto block : graph.GetBlocks()) {
        for (const auto& attr : block->GetAttributes()) {
            assert(attr.compare(0, compareLength, s_attrBaseName) == 0);
        }
    }

    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

std::chrono::milliseconds Measure_FindBlocksByAttribute(Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    int compareLength = s_blockBaseName.length();

    for (const auto& attr : s_attrs) {
        for (auto block : graph.GetBlocksWithAttribute(attr)) {
            assert(block->GetName().compare(0, compareLength, s_blockBaseName) == 0);
        }
    }
    auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

int main(int argc, char* argv[])
{
    Graph graph;
    createBlockNames();
    createAttrNames();

    auto timeAddBlocks = Measure_AddBlocks(graph);
    std::cout << "Measure_AddBlocks took: " << timeAddBlocks.count() << "ms." << std::endl;

    auto timeFindAttributesByBlock = Measure_FindAttributesByBlock(graph);
    std::cout << "Measure_FindAttributesByBlock took: " << timeFindAttributesByBlock.count() << "ms." << std::endl;

    auto timeFindBocksByAttribute = Measure_FindBlocksByAttribute(graph);
    std::cout << "Measure_FindBlocksByAttribute took: " << timeFindBocksByAttribute.count() << "ms." << std::endl;

    std::cout << "Total program time: " << timeAddBlocks.count() + timeFindAttributesByBlock.count() + timeFindBocksByAttribute.count() << "ms." << std::endl;
    
    std::getchar();
    return 0;
}

/*

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
*/