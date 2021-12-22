#pragma once
#include "Graph.h"

void Graph::AddBlock(Block* block)
{
    GenerateUniqueName(block);
    InsertBlock(std::unique_ptr<Block>(block));
}

void Graph::InsertBlock(std::unique_ptr<Block> newBlock)
{
    m_blockMap.emplace(newBlock->GetName(), std::move(newBlock));
}

std::list<Block*> Graph::GetBlocks()
{
    std::list<Block*> list = {};
    
    for (auto const & item : m_blockMap)
    {
        list.push_back(item.second.get());
    }
    return list;
}

std::list<Block*> Graph::GetBlocksWithAttribute(std::string const &attribute)
{
    std::list<Block*> blocksWithAttribute = {};

    for (auto const& block : GetBlocks())
    {
        if (CompareBlockAttributes(block, attribute)) blocksWithAttribute.push_back(block);
    }

    return blocksWithAttribute;
}

bool Graph::CompareBlockAttributes(Block* block, std::string const& attribute)
{
    return block->GetAttributes().find(attribute) != block->GetAttributes().end();
}

void Graph::ConstructBlockname(Block *block, std::string& newName, unsigned int& count)
{
    std::ostringstream s;
    s << block->GetName() << count;
    count++;
    newName.clear();
    newName = s.str();
}

void Graph::GenerateUniqueName(Block *block)
{
    unsigned int count = 0;
    auto testName = block->GetName();
    
    while (m_blockMap.count(testName))
    {
        ConstructBlockname(block, testName, count);
    }

    block->SetName(testName);
}
