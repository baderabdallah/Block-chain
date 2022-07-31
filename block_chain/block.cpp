
#include <stdio.h>
#include <string>

#include "block.h"

Block::Block(int index, TransactionData data, size_t prev_hash)
{
    index_ = index;
    data_ = data;
    previous_hash_ = prev_hash;
    block_hash_ = GenerateHash();
}

int Block::GetIndex()
{
    return index_;
}

TransactionData Block::GetData()
{
    return data_;
}

void Block::SetData(TransactionData data)
{
    data_ = data;
}

size_t Block::GetHash()
{
    return block_hash_;
}

size_t Block::GetPreviousHash()
{
    return previous_hash_;
}

bool Block::IsHashValid()
{
    return GenerateHash() == GetHash();
}

size_t Block::GenerateHash()
{
    std::string to_hash_s = std::to_string(data_.amount) + data_.receiver_key + data_.sender_key + std::to_string(data_.timestamp);

    std::hash<std::string> t_data_hash{};
    std::hash<std::string> prev_hash{};

    return t_data_hash(to_hash_s) ^ (prev_hash(std::to_string(GetPreviousHash())) << 1);
}