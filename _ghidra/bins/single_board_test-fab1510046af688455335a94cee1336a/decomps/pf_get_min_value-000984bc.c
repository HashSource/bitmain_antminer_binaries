
int8_t pf_get_min_value(int8_t *data,uint8_t data_length)

{
  uint8_t data_length_local;
  int8_t *data_local;
  int8_t min;
  uint8_t i;
  
  if ((data == (int8_t *)0x0) || (data_length == '\0')) {
    min = -1;
  }
  else {
    min = *data;
    for (i = '\0'; i < data_length; i = i + '\x01') {
      if (data[i] < min) {
        min = data[i];
      }
    }
  }
  return min;
}

