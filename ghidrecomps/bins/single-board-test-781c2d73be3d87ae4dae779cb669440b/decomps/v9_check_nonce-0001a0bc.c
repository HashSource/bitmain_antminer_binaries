
/* WARNING: Unknown calling convention */

int v9_check_nonce(uchar which_chain,uchar *nonce_data)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  char *__format;
  int iVar4;
  work *pwVar5;
  int iVar6;
  uint uVar7;
  pthread_mutex_t *__mutex;
  uint uVar8;
  
  uVar2 = (uint)which_chain;
  uVar8 = nonce_data[3] & 0x3f;
  uVar7 = (uint)*nonce_data << 0x18 | (uint)nonce_data[1] << 0x10 | (uint)nonce_data[3] |
          (uint)nonce_data[2] << 8;
  uVar3 = __udivsi3(*nonce_data,gChain_Asic_Interval);
  if (uVar3 < 0x2d) {
    if (uVar8 < 0x32) {
      if ((nonce_data[4] & 0x7f) < Conf.pattern_number) {
        iVar6 = Conf.pattern_number * uVar8 + (nonce_data[4] & 0x7f);
        pwVar5 = cgpu.works[uVar3];
        if (uVar7 == pwVar5[iVar6].nonce) {
          uVar7 = pwVar5[iVar6].is_nonce_return_back[uVar2][0];
          if (uVar7 != 0) {
            pwVar5[iVar6].is_nonce_return_back[uVar2][0] = uVar7 + 1;
            gRepeated_Nonce_Id[uVar2] = gRepeated_Nonce_Id[uVar2] + 1;
            return 0;
          }
          pwVar5[iVar6].is_nonce_return_back[uVar2][0] = 1;
          uVar7 = gAsic_Core_Nonce_Num[uVar2][uVar3][uVar8];
          gValid_Nonce_Num[uVar2] = gValid_Nonce_Num[uVar2] + 1;
          gAsic_Core_Nonce_Num[uVar2][uVar3][uVar8] = uVar7 + 1;
          return 0;
        }
        __mutex = (pthread_mutex_t *)(HW_check_mutex + uVar2);
        pthread_mutex_lock(__mutex);
        if (gWork_Num_For_Hw_Check == '\0') {
          pthread_mutex_unlock(__mutex);
          return 0;
        }
        iVar6 = 0;
        pwVar5 = gWorks_For_Hw_Check[uVar2];
        do {
          iVar6 = iVar6 + 1;
          iVar4 = check_hw(pwVar5,uVar7,false);
          if (iVar4 == 0) {
            pthread_mutex_unlock(__mutex);
            return 0;
          }
          pwVar5 = pwVar5 + 1;
        } while (iVar6 < (int)(uint)gWork_Num_For_Hw_Check);
        pthread_mutex_unlock(__mutex);
        uVar1 = DAT_0001a280;
        if (iVar4 == 1) {
          gHw_Nonce_Num[uVar2] = gHw_Nonce_Num[uVar2] + 1;
          printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",uVar1,uVar2,uVar3,uVar8,
                 uVar7);
          return 0;
        }
        return 0;
      }
      __format = "%s: received work_id = %02d nonce. error!!!\t";
    }
    else {
      __format = "%s: received core%02d nonce. error!!!\t";
    }
    printf(__format,DAT_0001a280);
    printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*nonce_data,(uint)nonce_data[1],
           (uint)nonce_data[2],(uint)nonce_data[3],(uint)nonce_data[4]);
  }
  return -1;
}

