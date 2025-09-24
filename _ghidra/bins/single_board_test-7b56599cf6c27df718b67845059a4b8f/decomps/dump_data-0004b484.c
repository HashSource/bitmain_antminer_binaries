
void dump_data(char *data,int len)

{
  int len_local;
  char *data_local;
  int i;
  
  for (i = 0; i < len; i = i + 1) {
    if ((i & 0xfU) == 0) {
      printf("\n0x%02x  ",i);
    }
    if ((i & 0xfU) == 8) {
      printf("   ");
    }
    printf("%02x ",(uint)(byte)data[i]);
  }
  putchar(10);
  return;
}

