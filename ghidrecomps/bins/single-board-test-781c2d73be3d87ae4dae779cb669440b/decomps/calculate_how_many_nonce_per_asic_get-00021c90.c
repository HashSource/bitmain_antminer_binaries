
/* WARNING: Unknown calling convention */

uint calculate_how_many_nonce_per_asic_get(uchar which_chain,uchar which_asic,uint core_number)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  if (core_number != 0) {
    iVar2 = (uint)which_asic + (uint)which_chain * 0x80;
    uVar1 = 0;
    piVar3 = (int *)(iVar2 * 0x1000 + -4 + DAT_00021cc4);
    do {
      piVar3 = piVar3 + 1;
      uVar1 = uVar1 + *piVar3;
    } while (piVar3 != (int *)(DAT_00021cc4 + (core_number + 0x3fffffff + iVar2 * 0x400) * 4));
    return uVar1;
  }
  return 0;
}

