#ifndef CSTRING_HELPER_HPP_
#define CSTRING_HELPER_HPP_

#include "../classes.h"
#include <vector>
#include <string>

namespace CStringHelper
{
  std::string convert_to_std_string(void * str);
  std::vector<std::string> convert_to_std_vector_string(void * str_array, size_t size);
  std::vector<std::string> convert_sequence_to_std_vector_string(void * str_seq);
  
  std::u16string convert_to_std_u16string(void * str);
  std::vector<std::u16string> convert_to_std_vector_u16string(void * str_array, size_t size);
  std::vector<std::u16string> convert_sequence_to_std_vector_u16string(void * str_seq);
  
  void assign_string(cbor::RxStream & stream, void * field);
  void assign_vector_string(std::vector<std::string> cpp_string_vector, void * str_array, size_t size);
  
  void assign_u16string(cbor::RxStream & stream, void * field);
  void assign_vector_u16string(std::vector<std::u16string> cpp_string_vector, void * str_array, size_t size);
}


#endif
