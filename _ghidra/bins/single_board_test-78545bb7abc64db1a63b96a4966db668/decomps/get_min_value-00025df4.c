
int8_t get_min_value(int8_t *data,uint8_t data_length)

{
  uint8_t data_length_local;
  int8_t *data_local;
  uint8_t i;
  int8_t min;
  
  min = '\x7f';
  for (i = '\0'; i < data_length; i = i + '\x01') {
    if (((data[i] < min) && (data[i] != -1)) && (data[i] != '\0')) {
      min = data[i];
    }
  }
  return min;
}

