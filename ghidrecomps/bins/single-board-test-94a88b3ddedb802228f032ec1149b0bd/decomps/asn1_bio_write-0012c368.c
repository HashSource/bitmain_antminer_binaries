
undefined4 asn1_bio_write(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 1 - param_2;
  if (1 < param_2) {
    iVar2 = 0;
  }
  if ((iVar2 == 0 && -1 < param_3) && (*(int *)(param_1 + 0x24) != 0)) {
    uVar1 = asn1_bio_write_part_0();
    return uVar1;
  }
  return 0;
}

