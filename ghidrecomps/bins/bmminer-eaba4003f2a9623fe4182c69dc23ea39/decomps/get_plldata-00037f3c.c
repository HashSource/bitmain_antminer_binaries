
void get_plldata(int type,int freq,uint *reg_data,uint16_t *reg_data2,uint *vil_data)

{
  uint16_t *reg_data2_local;
  uint *reg_data_local;
  int freq_local;
  int type_local;
  char vildivider [32];
  char plldivider2 [32];
  char plldivider1 [32];
  uint i;
  
  plldivider1[0] = '\0';
  plldivider1[1] = '\0';
  plldivider1[2] = '\0';
  plldivider1[3] = '\0';
  plldivider1[4] = '\0';
  plldivider1[5] = '\0';
  plldivider1[6] = '\0';
  plldivider1[7] = '\0';
  plldivider1[8] = '\0';
  plldivider1[9] = '\0';
  plldivider1[10] = '\0';
  plldivider1[0xb] = '\0';
  plldivider1[0xc] = '\0';
  plldivider1[0xd] = '\0';
  plldivider1[0xe] = '\0';
  plldivider1[0xf] = '\0';
  plldivider1[0x10] = '\0';
  plldivider1[0x11] = '\0';
  plldivider1[0x12] = '\0';
  plldivider1[0x13] = '\0';
  plldivider1[0x14] = '\0';
  plldivider1[0x15] = '\0';
  plldivider1[0x16] = '\0';
  plldivider1[0x17] = '\0';
  plldivider1[0x18] = '\0';
  plldivider1[0x19] = '\0';
  plldivider1[0x1a] = '\0';
  plldivider1[0x1b] = '\0';
  plldivider1[0x1c] = '\0';
  plldivider1[0x1d] = '\0';
  plldivider1[0x1e] = '\0';
  plldivider1[0x1f] = '\0';
  plldivider2[0] = '\0';
  plldivider2[1] = '\0';
  plldivider2[2] = '\0';
  plldivider2[3] = '\0';
  plldivider2[4] = '\0';
  plldivider2[5] = '\0';
  plldivider2[6] = '\0';
  plldivider2[7] = '\0';
  plldivider2[8] = '\0';
  plldivider2[9] = '\0';
  plldivider2[10] = '\0';
  plldivider2[0xb] = '\0';
  plldivider2[0xc] = '\0';
  plldivider2[0xd] = '\0';
  plldivider2[0xe] = '\0';
  plldivider2[0xf] = '\0';
  plldivider2[0x10] = '\0';
  plldivider2[0x11] = '\0';
  plldivider2[0x12] = '\0';
  plldivider2[0x13] = '\0';
  plldivider2[0x14] = '\0';
  plldivider2[0x15] = '\0';
  plldivider2[0x16] = '\0';
  plldivider2[0x17] = '\0';
  plldivider2[0x18] = '\0';
  plldivider2[0x19] = '\0';
  plldivider2[0x1a] = '\0';
  plldivider2[0x1b] = '\0';
  plldivider2[0x1c] = '\0';
  plldivider2[0x1d] = '\0';
  plldivider2[0x1e] = '\0';
  plldivider2[0x1f] = '\0';
  vildivider[0] = '\0';
  vildivider[1] = '\0';
  vildivider[2] = '\0';
  vildivider[3] = '\0';
  vildivider[4] = '\0';
  vildivider[5] = '\0';
  vildivider[6] = '\0';
  vildivider[7] = '\0';
  vildivider[8] = '\0';
  vildivider[9] = '\0';
  vildivider[10] = '\0';
  vildivider[0xb] = '\0';
  vildivider[0xc] = '\0';
  vildivider[0xd] = '\0';
  vildivider[0xe] = '\0';
  vildivider[0xf] = '\0';
  vildivider[0x10] = '\0';
  vildivider[0x11] = '\0';
  vildivider[0x12] = '\0';
  vildivider[0x13] = '\0';
  vildivider[0x14] = '\0';
  vildivider[0x15] = '\0';
  vildivider[0x16] = '\0';
  vildivider[0x17] = '\0';
  vildivider[0x18] = '\0';
  vildivider[0x19] = '\0';
  vildivider[0x1a] = '\0';
  vildivider[0x1b] = '\0';
  vildivider[0x1c] = '\0';
  vildivider[0x1d] = '\0';
  vildivider[0x1e] = '\0';
  vildivider[0x1f] = '\0';
  if (type == 0x571) {
    for (i = 0; (i < 0xb3 && (freq_pll_1393[i].freq != freq)); i = i + 1) {
    }
  }
  if (i == 0xb3) {
    i = 4;
  }
  sprintf(plldivider1,"%08x",freq_pll_1393[i].fildiv1);
  sprintf(plldivider2,"%04x",freq_pll_1393[i].fildiv2);
  sprintf(vildivider,"%04x",freq_pll_1393[i].vilpll);
  *reg_data = freq_pll_1393[i].fildiv1;
  *reg_data2 = (uint16_t)freq_pll_1393[i].fildiv2;
  *vil_data = freq_pll_1393[i].vilpll;
  return;
}

