
/* WARNING: Unknown calling convention */

int get_pll_index(int freq)

{
  int iVar1;
  int iVar2;
  char freq_str [10];
  
  iVar2 = 0;
  sprintf(freq_str,"%d",freq);
  do {
    iVar1 = memcmp(freq_pll_1385[iVar2].freq,freq_str,4);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x72);
  return -1;
}

