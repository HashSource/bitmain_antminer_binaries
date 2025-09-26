
int8_t get_max_value(int8_t *data,uint8_t data_length)

{
  uint8_t data_length_local;
  int8_t *data_local;
  uint8_t i;
  int8_t max;
  
  max = -0x80;
  for (i = '\0'; i < data_length; i = i + '\x01') {
    if (((max < data[i]) && (data[i] != -1)) && (data[i] != '\0')) {
      max = data[i];
    }
  }
  return max;
}

