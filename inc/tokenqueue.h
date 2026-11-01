#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <cstddef>
#include <deque>

#include "formats.h"

class TokenQueue {
public:
  TokenQueue() = default;
  ~TokenQueue() = default;
  TokenQueue(const TokenQueue &) = delete;
  TokenQueue &operator=(const TokenQueue &) = delete;
  TokenQueue(TokenQueue &&) noexcept = default;
  TokenQueue &operator=(TokenQueue &&) = default;

  Formats Pop();
  void Push(const Formats &);
  std::size_t Size();

private:
  std::deque<Formats> token_queue_;
};

#endif // TOKEN_QUEUE_H
