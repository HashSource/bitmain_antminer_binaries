
int8_t pf_get_max_value(int8_t *data,uint8_t data_length)

{
  uint8_t data_length_local;
  int8_t *data_local;
  int8_t max;
  uint8_t i;
  
  if ((data == (int8_t *)0x0) || (data_length == '\0')) {
    max = -1;
  }
  else {
    max = *data;
    for (i = '\0'; i < data_length; i = i + '\x01') {
      if (max < data[i]) {
        max = data[i];
      }
    }
  }
  return max;
}

