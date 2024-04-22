
/* WARNING: Unknown calling convention */

void get_BM1385_plldata(uint freq,uint32_t *reg_data,uint16_t *reg_data2,uint32_t *vil_data)

{
  undefined4 uVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint32_t uVar5;
  int iVar6;
  char *__s;
  char freq_str [10];
  char plldivider1 [32];
  char plldivider2 [32];
  char vildivider [32];
  
  memset(plldivider1,0,0x20);
  memset(plldivider2,0,0x20);
  memset(vildivider,0,0x20);
  iVar4 = 0;
  sprintf(freq_str,"%d",freq);
  do {
    iVar6 = iVar4 * 0x10;
    __s = freq_pll_1385[iVar4].freq;
    __n = strlen(__s);
    iVar2 = memcmp(__s,freq_str,__n);
    if (iVar2 == 0) {
      printf("%s: i = %d, sizeof(freq_pll_1385)/sizeof(freq_pll_1385[0]) = %d\n",DAT_00011198,iVar4,
             0x7c);
      goto LAB_000110ec;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x7c);
  iVar6 = 0x40;
  printf("%s: i = %d, sizeof(freq_pll_1385)/sizeof(freq_pll_1385[0]) = %d\n",DAT_00011198,0x7c,0x7c)
  ;
  printf("%s: Freq set Err!!!!\n",DAT_00011198);
  printf("%s: Using 200M\n",DAT_00011198);
LAB_000110ec:
  sprintf(plldivider1,"%08x",*(undefined4 *)((int)&freq_pll_1385[0].fildiv1 + iVar6));
  sprintf(plldivider2,"%04x",*(undefined4 *)((int)&freq_pll_1385[0].fildiv2 + iVar6));
  sprintf(vildivider,"%04x",*(undefined4 *)((int)&freq_pll_1385[0].vilpll + iVar6));
  printf("%s: Freq %s, PLL1 %s, PLL2 %s, vilpll %s\n",DAT_00011198,freq_str,plldivider1,plldivider2,
         vildivider);
  uVar1 = DAT_00011198;
  *reg_data = *(uint32_t *)((int)&freq_pll_1385[0].fildiv1 + iVar6);
  uVar3 = *(uint *)((int)&freq_pll_1385[0].fildiv2 + iVar6);
  uVar5 = *(uint32_t *)((int)&freq_pll_1385[0].vilpll + iVar6);
  *reg_data2 = (uint16_t)uVar3;
  *vil_data = uVar5;
  printf("%s: PLL1 %#x, PLL2 %#x, vilpll %#x\n",uVar1,*reg_data,uVar3 & 0xffff,uVar5);
  return;
}

