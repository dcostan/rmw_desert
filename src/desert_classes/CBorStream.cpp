#include "CBorStream.h"

namespace cbor
{

TxStream::TxStream(size_t hint)
{
}

TxStream & TxStream::operator<<(const uint64_t n)
{
  return *this;
}

TxStream & TxStream::operator<<(const uint32_t n)
{
  printf("INCOMING UINT32: %u\n", n);
  return *this;
}

TxStream & TxStream::operator<<(const uint16_t n)
{
  return *this;
}

TxStream & TxStream::operator<<(const uint8_t n)
{
  printf("INCOMING UINT8: %u\n", n);
  return *this;
}

TxStream & TxStream::operator<<(const int64_t n)
{
  return *this;
}

TxStream & TxStream::operator<<(const int32_t n)
{
  return *this;
}

TxStream & TxStream::operator<<(const int16_t n)
{
  return *this;
}

TxStream & TxStream::operator<<(const int8_t n)
{
  return *this;
}

TxStream & TxStream::operator<<(const float f)
{
  return *this;
}

TxStream & TxStream::operator<<(const double d)
{
  return *this;
}

TxStream & TxStream::operator<<(const std::string s)
{
  printf("INCOMING STRING: %s\n", s.c_str());
  return *this;
}

TxStream & TxStream::operator<<(const std::u16string s)
{
  return *this;
}

template<typename T>
TxStream & TxStream::operator<<(const std::vector<T> v)
{
  return serialize_sequence(v.data(), v.size());
}

TxStream & TxStream::operator<<(const std::vector<bool> v)
{
  for (size_t i = 0; i < v.size(); ++i) {
    *this << v[i];
  }
  return *this;
}

template<typename T>
TxStream & TxStream::serialize_sequence(const T * items, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    *this << items[i];
  }
  return *this;
}

}