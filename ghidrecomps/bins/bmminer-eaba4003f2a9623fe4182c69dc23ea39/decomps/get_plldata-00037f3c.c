
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
  plldivider1[11] = '\0';
  plldivider1[12] = '\0';
  plldivider1[13] = '\0';
  plldivider1[14] = '\0';
  plldivider1[15] = '\0';
  plldivider1[16] = '\0';
  plldivider1[17] = '\0';
  plldivider1[18] = '\0';
  plldivider1[19] = '\0';
  plldivider1[20] = '\0';
  plldivider1[21] = '\0';
  plldivider1[22] = '\0';
  plldivider1[23] = '\0';
  plldivider1[24] = '\0';
  plldivider1[25] = '\0';
  plldivider1[26] = '\0';
  plldivider1[27] = '\0';
  plldivider1[28] = '\0';
  plldivider1[29] = '\0';
  plldivider1[30] = '\0';
  plldivider1[31] = '\0';
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
  plldivider2[11] = '\0';
  plldivider2[12] = '\0';
  plldivider2[13] = '\0';
  plldivider2[14] = '\0';
  plldivider2[15] = '\0';
  plldivider2[16] = '\0';
  plldivider2[17] = '\0';
  plldivider2[18] = '\0';
  plldivider2[19] = '\0';
  plldivider2[20] = '\0';
  plldivider2[21] = '\0';
  plldivider2[22] = '\0';
  plldivider2[23] = '\0';
  plldivider2[24] = '\0';
  plldivider2[25] = '\0';
  plldivider2[26] = '\0';
  plldivider2[27] = '\0';
  plldivider2[28] = '\0';
  plldivider2[29] = '\0';
  plldivider2[30] = '\0';
  plldivider2[31] = '\0';
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
  vildivider[11] = '\0';
  vildivider[12] = '\0';
  vildivider[13] = '\0';
  vildivider[14] = '\0';
  vildivider[15] = '\0';
  vildivider[16] = '\0';
  vildivider[17] = '\0';
  vildivider[18] = '\0';
  vildivider[19] = '\0';
  vildivider[20] = '\0';
  vildivider[21] = '\0';
  vildivider[22] = '\0';
  vildivider[23] = '\0';
  vildivider[24] = '\0';
  vildivider[25] = '\0';
  vildivider[26] = '\0';
  vildivider[27] = '\0';
  vildivider[28] = '\0';
  vildivider[29] = '\0';
  vildivider[30] = '\0';
  vildivider[31] = '\0';
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

