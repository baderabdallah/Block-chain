#ifndef BLOCK_CHAIN_BLOCK_H
#define BLOCK_CHAIN_BLOCK_H

#include <vector>
#include <utility>
#include <ctime>
#include "block_chain/data_types/transaction_data.h"

class Block
{

public:
    Block(int index, TransactionData data, size_t prev_hash);

    int GetIndex();
    TransactionData GetData();
    void SetData(TransactionData data);
    size_t GetHash();
    size_t GetPreviousHash();
    bool IsHashValid();

private:
    int index_{};
    size_t previous_hash_{};
    size_t block_hash_{};
    TransactionData data_{};

    size_t GenerateHash();
};

#endif /* BLOCK_CHAIN_BLOCK_H */