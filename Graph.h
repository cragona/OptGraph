#pragma once
#include <stdio.h>
#include <chrono>
#include <iostream>
#include <sstream>
#include <cassert>
#include <unordered_map>
#include "Block.h"

class Graph
{
public:

    /**
    * Add Block into graph
    *
    * Takes a block, generates a unique name and then places it into the graph
    *
    * @param block Block to be placed into graph
    * @return void
    */
    void AddBlock(Block* block);

    /**
    * Generates a list of Blocks
    *
    * Takes all the blocks out of the graph and returns them in their own collection
    *
    * @param void
    * @return All blocks from the graph
    */
    std::list<Block*> GetBlocks();

    /**
    * Finds Blocks with pass attribute
    *
    * Searchs through a blocks collection and checks that blocks attribute collection
    * to see if the attribute exist. If it does it adds it to the list that will be returned.
    *
    * @param attribute Attribute requested to find in the block
    * @return All blocks that have the specified attribute
    */
    std::list<Block*> GetBlocksWithAttribute(std::string const& attribute);

private:    
    /**
    * Makes a unique block name
    *
    * Takes the intial block name and checks if its unique if not it generates a new one
    * until the name is unique in the graph
    *
    * @param block Block which name needs to be unique
    * @return void
    */
    void GenerateUniqueName(Block* block);

    /**
    * Helper to place blocks into the graph
    *
    * Places the block into the graph
    *
    * @param newBlock Block which is going in the graph
    * @return void
    */
    void InsertBlock(std::unique_ptr<Block> newBlock);

    /**
    * Helper to that contruct block string names
    *
    * Uses the count and newName reference to create a new block string name to be tested
    *
    * @param block Block which needs a new unique name
    * @param newName Name of block that will be constructed and set to block name if unqiue
    * @param count Counter starting at 0, incremented per each try of unqiueness
    * @return void
    */
    void ConstructBlockname(Block* block, std::string& newName, unsigned int& count);
    
    /**
    * Helper to check if a block contains an attribute
    *
    * Takes the specified block container and checks if the attribute is associated with it
    *
    * @param block Block container we want to check
    * @param attribute Attribute we want to check the block container for
    * @return bool true if it exist false if not
    */
    bool CompareBlockAttributes(Block* block, std::string const& attribute);

    /** Block Graph: Contains all blocks and their associated values */
    std::unordered_map<std::string, std::unique_ptr<Block>> m_blockMap;
};