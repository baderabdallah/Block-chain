#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "block_chain\block_chain.h"
using ::testing::Eq;

class BlockChainFixture : public ::testing::Test
{

protected:
  Blockchain unit_{};

  time_t time_stamp_t1{};
  TransactionData transaction_data_1_{1.5, "Joe", "Sally", time(&time_stamp_t1)};

  time_t time_stamp_t2{61};
  TransactionData transaction_data_2_{0.2233, "Martha", "Fred", time(&time_stamp_t2)};
};

TEST_F(BlockChainFixture, GivenAddingTwoValidBlocksToChain_ExpectValidBlockChain)
{
  // Given - // When
  unit_.AddBlock(transaction_data_1_);
  unit_.AddBlock(transaction_data_2_);

  // Then
  unit_.PrintChain();
  printf("\nIs chain still valid? %d\n", unit_.IsChainValid());
  EXPECT_TRUE(unit_.IsChainValid());
}

TEST_F(BlockChainFixture, GivenValidBlockChain_ExpectInvalidWhenBlockIsModified)
{
  // Given
  unit_.AddBlock(transaction_data_1_);
  unit_.AddBlock(transaction_data_2_);

  // When
  Block *hack_block = unit_.GetLatestBlock();
  TransactionData data{10000, "Jon"};
  hack_block->SetData(data);

  // Then
  unit_.PrintChain();
  printf("\nIs chain still valid? %d\n", unit_.IsChainValid());
  EXPECT_FALSE(unit_.IsChainValid());
}