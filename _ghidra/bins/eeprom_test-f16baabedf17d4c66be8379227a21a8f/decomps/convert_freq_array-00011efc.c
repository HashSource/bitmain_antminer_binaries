
void convert_freq_array(uint8_t *chain_freq,uint16_t (*array) [9])

{
  uint16_t (*array_local) [9];
  uint8_t *chain_freq_local;
  int i;
  int j;
  
  for (j = 0; j < 0xc; j = j + 1) {
    for (i = 0; i < 9; i = i + 1) {
      chain_freq[i + (j * 0x6c) / 0xc] = (char)array[j][i] + '8';
    }
  }
  return;
}

