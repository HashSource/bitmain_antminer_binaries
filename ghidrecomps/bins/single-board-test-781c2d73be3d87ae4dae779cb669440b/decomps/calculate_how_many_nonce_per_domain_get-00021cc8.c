
/* WARNING: Unknown calling convention */
/* Local variable core_id_start:uint[r1:4] conflicts with parameter, skipped. */

uint calculate_how_many_nonce_per_domain_get(uchar which_chain,uchar which_domain)

{
  int iVar1;
  uint uVar2;
  int extraout_r1;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint asic_id_start;
  int *piVar6;
  uint core_id_end;
  
  uVar4 = BHB07601_ASIC_NUMBER / 0xc;
  iVar1 = __udivsi3(which_domain,uVar4,BHB07601_ASIC_NUMBER * -0x55555555);
  uVar5 = iVar1 * 4;
  __aeabi_uidivmod(which_domain,uVar4);
  uVar4 = extraout_r1 * 0xa8;
  if (uVar5 < uVar5 + 4) {
    iVar1 = 4;
    uVar2 = 0;
    piVar6 = (int *)(DAT_00021d3c + (uVar4 + (uVar5 + (uint)which_chain * 0x80) * 0x400) * 4);
    do {
      if (uVar4 < uVar4 + 0xa8) {
        piVar3 = piVar6;
        do {
          piVar3 = piVar3 + 1;
          uVar2 = uVar2 + *piVar3;
        } while (piVar3 != piVar6 + 0xa8);
      }
      iVar1 = iVar1 + -1;
      piVar6 = piVar6 + 0x400;
    } while (iVar1 != 0);
    return uVar2;
  }
  return 0;
}

