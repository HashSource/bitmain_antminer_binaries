
void get_plldata(uint32_t freq,uint32_t *vil_data)

{
  uint32_t *vil_data_local;
  uint32_t freq_local;
  uint32_t i;
  
  for (i = 0; (i < 0x6e && (freq_pll[i].freq != freq)); i = i + 1) {
  }
  if (i == 0x6e) {
    i = 4;
  }
  *vil_data = freq_pll[i].vilpll;
  return;
}

