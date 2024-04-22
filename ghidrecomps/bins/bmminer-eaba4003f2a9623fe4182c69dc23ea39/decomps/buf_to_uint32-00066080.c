
uint32_t buf_to_uint32(char *data)

{
  char *data_local;
  uint32_t result;
  size_t i;
  
  result = 0;
  for (i = 0; i < 4; i = i + 1) {
    result = (uint)(byte)data[i] | result << 8;
  }
  return result;
}

