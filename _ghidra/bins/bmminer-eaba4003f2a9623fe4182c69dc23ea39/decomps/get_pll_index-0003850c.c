
int get_pll_index(int freq)

{
  int freq_local;
  int i;
  
  for (i = 0; ((uint)i < 0xb3 && (freq_pll_1393[i].freq != freq)); i = i + 1) {
  }
  if (i == 0xb3) {
    i = -1;
  }
  return i;
}

