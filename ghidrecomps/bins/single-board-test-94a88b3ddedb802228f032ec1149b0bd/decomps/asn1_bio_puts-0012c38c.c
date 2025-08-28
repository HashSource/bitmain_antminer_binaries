
undefined4 asn1_bio_puts(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  
  sVar1 = strlen(param_2);
  iVar3 = 1 - (int)param_2;
  if ((char *)0x1 < param_2) {
    iVar3 = 0;
  }
  if ((iVar3 == 0 && -1 < (int)sVar1) && (*(int *)(param_1 + 0x24) != 0)) {
    uVar2 = asn1_bio_write_part_0(param_1,param_2,sVar1,param_4);
    return uVar2;
  }
  return 0;
}

