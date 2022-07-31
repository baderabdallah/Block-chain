#ifndef BLOCK_CHAIN_BLOCK_CHAIN_H
#define BLOCK_CHAIN_BLOCK_CHAIN_H

#include <vector>
#include <utility>
#include <ctime>
#include "block_chain/data_types/transaction_data.h"
#include "block_chain/block.h"

#include <vector>

class Blockchain
{
public:
    Blockchain();

    void AddBlock(TransactionData data);
    Block *GetLatestBlock();
    bool IsChainValid();
    void PrintChain();

private:
    Block CreateGenesisBlock();
    std::vector<Block> chain_{};
};

#endif /* BLOCK_CHAIN_BLOCK_CHAIN_H */