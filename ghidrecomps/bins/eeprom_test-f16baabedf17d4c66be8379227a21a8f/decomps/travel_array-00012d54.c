
void travel_array(uint16_t (*array) [9])

{
  uint16_t (*array_local) [9];
  int i;
  int j;
  
  for (j = 0; j < 0xc; j = j + 1) {
    for (i = 0; i < 9; i = i + 1) {
      printf("IC[%03d]:%d ",(j * 0x6c) / 0xc + i,(uint)array[j][i]);
    }
    putchar(10);
  }
  return;
}

