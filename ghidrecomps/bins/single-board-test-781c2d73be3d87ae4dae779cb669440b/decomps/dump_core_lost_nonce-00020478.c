
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void dump_core_lost_nonce(uchar which_chain,uchar which_asic)

{
  int iVar1;
  uint *puVar2;
  work *pwVar3;
  work *works;
  uint uVar4;
  
  pwVar3 = cgpu.works[which_asic];
  puVar2 = (uint *)(DAT_00020524 + ((uint)which_asic + (uint)which_chain * 0x80) * 0x1000);
  iVar1 = 0;
  do {
    while (puVar2 = puVar2 + 1, Conf.pattern_number <= *puVar2) {
      iVar1 = iVar1 + 1;
      if (iVar1 == 0x2a0) {
        return;
      }
    }
    printf("core[%03d] = %d,      lost these nonce : ",iVar1);
    uVar4 = 0;
    if (Conf.pattern_number != 0) {
      do {
        while (pwVar3[Conf.pattern_number * iVar1 + uVar4].is_nonce_return_back[which_chain][0] == 0
              ) {
          printf("%d  ",uVar4);
          uVar4 = uVar4 + 1;
          if (Conf.pattern_number <= uVar4) goto LAB_00020510;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < Conf.pattern_number);
    }
LAB_00020510:
    iVar1 = iVar1 + 1;
    putchar(10);
    if (iVar1 == 0x2a0) {
      return;
    }
  } while( true );
}

