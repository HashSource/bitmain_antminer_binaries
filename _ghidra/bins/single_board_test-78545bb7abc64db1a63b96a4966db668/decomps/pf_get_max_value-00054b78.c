
int pf_get_max_value(int8_t *data,int data_length)

{
  int iVar1;
  int data_length_local;
  int8_t *data_local;
  int8_t max;
  uint8_t i;
  
  if ((data == (int8_t *)0x0) || (data_length == 0)) {
    iVar1 = 0xff;
  }
  else {
    max = '\0';
    for (i = '\0'; (int)(uint)i < data_length; i = i + '\x01') {
      if ((max < data[i]) && (data[i] != -1)) {
        max = data[i];
      }
    }
    iVar1 = (int)max;
  }
  return iVar1;
}

