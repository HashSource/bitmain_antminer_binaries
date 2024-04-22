
/* WARNING: Unknown calling convention */

int BHB91603_check_nonce(uchar which_chain,uint *buf)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  work *pwVar5;
  int iVar6;
  pthread_mutex_t *__mutex;
  uint uVar7;
  uint nonce;
  uint uVar8;
  uint uVar9;
  
  uVar2 = (uint)which_chain;
  nonce = buf[1];
  uVar8 = *buf;
  uVar9 = nonce & 0xff;
  uVar3 = __udivsi3(nonce >> 0x18,gChain_Asic_Interval);
  uVar7 = (uVar8 << 1) >> 0x11;
  if ((uVar8 & 0x40) != 0) {
    printf("\n!!! %s: nonce crc error! nonce = 0x%08x, which_asic = %d, which_core = %d, which_pattern = %d\n"
           ,DAT_00017860,nonce,uVar3,uVar9,uVar7);
  }
  if ((uVar3 < BHB91603_ASIC_NUMBER) && (uVar7 < Conf.pattern_number)) {
    iVar6 = Conf.pattern_number * uVar9 + uVar7;
    pwVar5 = cgpu.works[uVar3];
    if (nonce == pwVar5[iVar6].nonce) {
      uVar7 = pwVar5[iVar6].is_nonce_return_back[uVar2][0];
      if (uVar7 == 0) {
        pwVar5[iVar6].is_nonce_return_back[uVar2][0] = 1;
        uVar7 = gAsic_Core_Nonce_Num[uVar2][uVar3][uVar9];
        gValid_Nonce_Num[uVar2] = gValid_Nonce_Num[uVar2] + 1;
        gAsic_Core_Nonce_Num[uVar2][uVar3][uVar9] = uVar7 + 1;
        return 0;
      }
      pwVar5[iVar6].is_nonce_return_back[uVar2][0] = uVar7 + 1;
      gRepeated_Nonce_Id[uVar2] = gRepeated_Nonce_Id[uVar2] + 1;
      return 0;
    }
    if (gHw_Nonce_Num[uVar2] <= Conf.Most_HW_Num) {
      __mutex = (pthread_mutex_t *)(HW_check_mutex + uVar2);
      pthread_mutex_lock(__mutex);
      if (gWork_Num_For_Hw_Check == '\0') {
        pthread_mutex_unlock(__mutex);
      }
      else {
        iVar6 = 0;
        pwVar5 = gWorks_For_Hw_Check[uVar2];
        do {
          iVar6 = iVar6 + 1;
          iVar4 = check_hw(pwVar5,nonce,false);
          if (iVar4 == 0) {
            pthread_mutex_unlock(__mutex);
            return 0;
          }
          pwVar5 = pwVar5 + 1;
        } while (iVar6 < (int)(uint)gWork_Num_For_Hw_Check);
        pthread_mutex_unlock(__mutex);
        uVar1 = DAT_00017860;
        if (iVar4 == 1) {
          gHw_Nonce_Num[uVar2] = gHw_Nonce_Num[uVar2] + 1;
          printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",uVar1,uVar2,uVar3,uVar9,
                 nonce);
        }
      }
    }
    return 0;
  }
  return -1;
}

