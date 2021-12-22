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
    void AddBlock(Block* block);
    std::list<Block*> GetBlocks();
    std::list<Block*> GetBlocksWithAttribute(std::string const&  attribute);
    void GenerateUniqueName(Block* block);

private:
    void InsertBlock(std::unique_ptr<Block> newBlock);
    void ConstructBlockname(Block* block, std::string& newName, unsigned int& count);
    bool CompareBlockAttributes(Block* block, std::string const& attribute);
    std::unordered_map<std::string, std::unique_ptr<Block>> m_blockMap;
};