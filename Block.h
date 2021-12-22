#pragma once
#include <string>
#include <list>
#include <unordered_set>

class Block
{
public:
    /**
    * Returns name
    *
    * Returns assocaited name of block
    *
    * @param void
    * @return string Name of block
    */
    std::string GetName() { return m_name; }

    /**
    * Set block's name
    *
    * Sets the block's name
    *
    * @param name Block's name
    * @return void
    */
    void SetName(std::string name) { m_name = name; }

    /**
    * Add attribute to block
    *
    * Adds and attribute to the blocks internal attribute bucket
    * Uniqueness doesnt matter
    * 
    * @param attribute Atrribute to be added
    * @return void
    */
    void AddAttribute(std::string attribute) { m_attributes.insert(attribute); }

    /**
    * Gets attributes of block
    *
    * Gets attributes of block in an unordered collection
    *
    * @param void
    * @return std::unordered_multiset<std::string> & Return collection of the blocks attributes
    */
    std::unordered_multiset<std::string> & GetAttributes() { return m_attributes; }

private:
    /** Name of block - to be unique for each block */
    std::string m_name = {};

    /** Collection of the block's attributes */
    std::unordered_multiset<std::string> m_attributes = {};
};