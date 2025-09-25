
uint32_t get_min_value_uint32(uint32_t *data,uint8_t data_length)

{
  uint8_t data_length_local;
  uint32_t *data_local;
  uint8_t i;
  uint32_t min;
  
  min = 0xffffffff;
  for (i = '\0'; i < data_length; i = i + '\x01') {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}

