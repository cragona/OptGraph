#pragma once
#include <string>
#include <list>
#include <unordered_set>

class Block
{
public:
    std::string GetName() { return m_name; }
    void SetName(std::string name) { m_name = name; }
    void AddAttribute(std::string attribute) { m_attributes.insert(attribute); }
    std::unordered_multiset<std::string> & GetAttributes() { return m_attributes; }

private:
    std::string m_name = {};
    std::unordered_multiset<std::string> m_attributes = {};
};