#ifndef BLOCK_CHAIN_TRANSACTION_DATA_H
#define BLOCK_CHAIN_TRANSACTION_DATA_H

#include <vector>
#include <utility>
#include <ctime>

struct TransactionData
{
    double amount{};
    std::string sender_key{};
    std::string receiver_key{};
    time_t timestamp{};
};

#endif /* BLOCK_CHAIN_TRANSACTION_DATA_H */