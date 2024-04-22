
/* WARNING: Unknown calling convention */

int single_BM1385_check_nonce(uchar which_chain,uchar *nonce_data)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  char *__format;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  work *work;
  pthread_mutex_t *__mutex;
  
  uVar2 = (uint)which_chain;
  uVar9 = nonce_data[3] & 0x3f;
  uVar8 = (uint)*nonce_data << 0x18 | (uint)nonce_data[1] << 0x10 | (uint)nonce_data[3] |
          (uint)nonce_data[2] << 8;
  uVar3 = __udivsi3(*nonce_data,gChain_Asic_Interval);
  if (uVar3 == 0) {
    if (uVar9 < 0x32) {
      uVar3 = nonce_data[4] & 0x7f;
      if (uVar3 < Conf.pattern_number) {
        if (uVar9 < 0x20) {
          iVar6 = 0;
          uVar5 = 0;
          uVar4 = Conf.OpenCoreNum1;
          do {
            uVar5 = uVar5 + 1;
            if ((uVar4 & 1) != 0) {
              iVar6 = iVar6 + 1;
            }
            uVar4 = uVar4 >> 1;
          } while (uVar5 < uVar9 + 1);
        }
        else {
          iVar7 = 0x20;
          iVar6 = 0;
          uVar5 = Conf.OpenCoreNum1;
          do {
            uVar4 = uVar5 & 1;
            uVar5 = uVar5 >> 1;
            if (uVar4 != 0) {
              iVar6 = iVar6 + 1;
            }
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          uVar5 = 0;
          uVar4 = Conf.OpenCoreNum2;
          do {
            uVar5 = uVar5 + 1;
            if ((uVar4 & 1) != 0) {
              iVar6 = iVar6 + 1;
            }
            uVar4 = uVar4 >> 1;
          } while (uVar5 < uVar9 - 0x1f);
        }
        iVar6 = *(int *)(cgpu.workdataFilePrefix + iVar6 * 4 + 0x3c) + uVar3 * 0x44;
        if (uVar8 == *(uint *)(iVar6 + 4)) {
          iVar6 = iVar6 + uVar2 * 4;
          if (*(int *)(iVar6 + 0x34) != 0) {
            *(int *)(iVar6 + 0x34) = *(int *)(iVar6 + 0x34) + 1;
            gRepeated_Nonce_Id[uVar2] = gRepeated_Nonce_Id[uVar2] + 1;
            return 0;
          }
          uVar8 = gValid_Nonce_Num[uVar2];
          *(undefined4 *)(iVar6 + 0x34) = 1;
          uVar3 = gAsic_Core_Nonce_Num[uVar2][0][uVar9];
          gValid_Nonce_Num[uVar2] = uVar8 + 1;
          gAsic_Core_Nonce_Num[uVar2][0][uVar9] = uVar3 + 1;
          return 0;
        }
        __mutex = (pthread_mutex_t *)(HW_check_mutex + uVar2);
        pthread_mutex_lock(__mutex);
        if (gWork_Num_For_Hw_Check == '\0') {
          pthread_mutex_unlock(__mutex);
          return 0;
        }
        work = gWorks_For_Hw_Check[uVar2];
        uVar3 = 0;
        do {
          uVar3 = uVar3 + 1;
          iVar6 = check_hw(work,uVar8,false);
          work = work + 1;
          if (iVar6 == 0) {
            pthread_mutex_unlock(__mutex);
            return 0;
          }
        } while (uVar3 < gWork_Num_For_Hw_Check);
        pthread_mutex_unlock(__mutex);
        uVar1 = DAT_00011e7c;
        if (iVar6 == 1) {
          gHw_Nonce_Num[uVar2] = gHw_Nonce_Num[uVar2] + 1;
          printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",uVar1,uVar2,0,uVar9,
                 uVar8);
          return 0;
        }
        return 0;
      }
      __format = "%s: received work_id = %02d nonce. error!!!\t";
    }
    else {
      __format = "%s: received core%02d nonce. error!!!\t";
      uVar3 = uVar9;
    }
  }
  else {
    __format = "%s: received ASIC%02d nonce. error!!!\t";
  }
  printf(__format,DAT_00011e7c,uVar3);
  printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*nonce_data,(uint)nonce_data[1],
         (uint)nonce_data[2],(uint)nonce_data[3],(uint)nonce_data[4]);
  return -1;
}

