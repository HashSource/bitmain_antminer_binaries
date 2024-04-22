
/* WARNING: Unknown calling convention */

int get_pll_index(int freq)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char freq_str [10];
  
  iVar1 = DAT_0002ec30;
  iVar3 = 0;
  sprintf(freq_str,DAT_0002ec2c,freq);
  do {
    iVar2 = memcmp(*(void **)(iVar1 + iVar3 * 0x10),freq_str,4);
    if (iVar2 == 0) {
      return iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x72);
  return -1;
}

