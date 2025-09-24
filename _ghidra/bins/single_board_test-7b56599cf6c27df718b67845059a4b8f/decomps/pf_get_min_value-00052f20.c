
int pf_get_min_value(int8_t *data,int data_length)

{
  int iVar1;
  int data_length_local;
  int8_t *data_local;
  int8_t min;
  uint8_t i;
  
  if ((data == (int8_t *)0x0) || (data_length == 0)) {
    iVar1 = 0xff;
  }
  else {
    min = *data;
    for (i = '\0'; (int)(uint)i < data_length; i = i + '\x01') {
      if (data[i] < min) {
        min = data[i];
      }
    }
    iVar1 = (int)min;
  }
  return iVar1;
}

