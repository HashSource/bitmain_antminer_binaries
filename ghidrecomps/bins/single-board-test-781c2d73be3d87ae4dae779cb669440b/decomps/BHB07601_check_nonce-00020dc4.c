
/* WARNING: Unknown calling convention */

int BHB07601_check_nonce(uchar which_chain,uint *buf)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint32_t uVar4;
  work *pwVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint32_t nonce;
  uint uVar9;
  uint uVar10;
  
  uVar2 = (uint)which_chain;
  nonce = buf[1];
  uVar10 = *buf;
  uVar3 = __udivsi3((nonce << 10) >> 0x18,gChain_Asic_Interval);
  uVar4 = BM1397_get_core_id(nonce);
  uVar8 = *buf;
  uVar9 = (uVar8 << 1) >> 0x18;
  if ((uVar10 & 0x40) != 0) {
    printf("\n!!! %s: nonce crc error! nonce = 0x%08x, which_asic = %d, which_core = %d, which_pattern = %d\n"
           ,DAT_00020f28,nonce,uVar3,uVar4,uVar9);
  }
  if ((uVar4 < 0x2a0 && uVar3 < BHB07601_ASIC_NUMBER) && (iVar7 = 0, uVar9 < Conf.pattern_number)) {
    iVar6 = Conf.pattern_number * uVar4 + uVar9;
    pwVar5 = cgpu.works[uVar3];
    if (nonce == pwVar5[iVar6].nonce) {
      uVar8 = pwVar5[iVar6].is_nonce_return_back[uVar2][0];
      if (uVar8 == 0) {
        pwVar5[iVar6].is_nonce_return_back[uVar2][0] = 1;
        uVar8 = gValid_Nonce_Num[uVar2];
        gAsic_Core_Nonce_Num[uVar2][uVar3][uVar4] = gAsic_Core_Nonce_Num[uVar2][uVar3][uVar4] + 1;
        gValid_Nonce_Num[uVar2] = uVar8 + 1;
        return 0;
      }
      pwVar5[iVar6].is_nonce_return_back[uVar2][0] = uVar8 + 1;
      gRepeated_Nonce_Id[uVar2] = gRepeated_Nonce_Id[uVar2] + 1;
      return 0;
    }
    iVar6 = check_hw(gWorks_For_Hw_Check[uVar2] + ((uVar8 << 9) >> 0x19),nonce,false);
    uVar1 = DAT_00020f28;
    if (iVar6 == 1) {
      gHw_Nonce_Num[uVar2] = gHw_Nonce_Num[uVar2] + 1;
      printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",uVar1,uVar2,uVar3,uVar4,
             nonce);
    }
  }
  else {
    iVar7 = -1;
  }
  return iVar7;
}

