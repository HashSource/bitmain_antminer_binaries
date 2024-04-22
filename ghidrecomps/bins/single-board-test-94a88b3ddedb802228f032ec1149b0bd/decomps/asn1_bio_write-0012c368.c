
undefined4 asn1_bio_write(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 1 - param_2;
  if (1 < param_2) {
    uVar2 = 0;
  }
  if (((uVar2 | param_3 >> 0x1f) == 0) && (*(int *)(param_1 + 0x24) != 0)) {
    uVar1 = asn1_bio_write_part_0();
    return uVar1;
  }
  return 0;
}

