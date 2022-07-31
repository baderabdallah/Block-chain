#include <string>
#include <stdio.h>
#include "block_chain/block_chain.h"

Blockchain::Blockchain()
{
    Block genesis = CreateGenesisBlock();
    chain_.push_back(genesis);
}

Block *Blockchain::GetLatestBlock()
{
    return &chain_.back();
}

void Blockchain::AddBlock(TransactionData d)
{
    int index = static_cast<int>(chain_.size());
    std::size_t previousHash = static_cast<int>(chain_.size()) > 0 ? GetLatestBlock()->GetHash() : 0;
    Block new_block(index, d, previousHash);
    chain_.push_back(new_block);
}

bool Blockchain::IsChainValid()
{
    std::vector<Block>::iterator it;

    for (it = chain_.begin(); it != chain_.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.IsHashValid())
        {
            return false;
        }

        if (it != chain_.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.GetPreviousHash() != previousBlock.GetHash())
            {
                return false;
            }
        }
    }

    return true;
}

void Blockchain::PrintChain()
{
    std::vector<Block>::iterator it;

    for (it = chain_.begin(); it != chain_.end(); ++it)
    {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.GetIndex());
        printf("\nAmount: %f", currentBlock.GetData().amount);
        printf("\nsender_key: %s", currentBlock.GetData().sender_key.c_str());
        printf("\nreceiver_key: %s", currentBlock.GetData().receiver_key.c_str());
        printf("\nTimestamp: %ld", currentBlock.GetData().timestamp);
        printf("\nHash: %zu", currentBlock.GetHash());
        printf("\nPrevious Hash: %zu", currentBlock.GetPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.IsHashValid());
    }
}

Block Blockchain::CreateGenesisBlock()
{
    std::time_t current;

    TransactionData d{0, "Genesis", "Genesis", time(&current)};

    Block genesis(0, d, 0);
    return genesis;
}