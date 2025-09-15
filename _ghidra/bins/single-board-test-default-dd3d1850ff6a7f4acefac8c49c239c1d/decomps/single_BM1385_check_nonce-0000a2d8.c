
undefined4 single_BM1385_check_nonce(byte param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_18 = 0;
  local_1c = 0;
  uVar2 = (uint)param_2[3] |
          (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8;
  iVar1 = __udivsi3(*param_2,gChain_Asic_Interval);
  uVar3 = param_2[3] & 0x3f;
  uVar4 = param_2[4] & 0x7f;
  if (iVar1 == 0) {
    if (uVar3 < 0x32) {
      if (uVar4 < (uint)Conf._64_4_) {
        local_20 = Conf._204_4_;
        local_24 = Conf._208_4_;
        if (uVar3 < 0x20) {
          for (local_14 = 0; local_14 < uVar3 + 1; local_14 = local_14 + 1) {
            if ((local_20 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            local_20 = local_20 >> 1;
          }
        }
        else {
          for (local_14 = 0; local_14 < 0x20; local_14 = local_14 + 1) {
            if ((local_20 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            local_20 = local_20 >> 1;
          }
          for (local_14 = 0; local_14 < uVar3 - 0x1f; local_14 = local_14 + 1) {
            if ((local_24 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            local_24 = local_24 >> 1;
          }
        }
        iVar1 = *(int *)(cgpu + (local_18 + 0x4029) * 4 + 4) + uVar4 * 0x74;
        if (uVar2 == *(uint *)(iVar1 + 4)) {
          if (*(int *)(iVar1 + (param_1 + 0xc) * 4 + 4) == 0) {
            *(int *)(iVar1 + (param_1 + 0xc) * 4 + 4) =
                 *(int *)(iVar1 + (param_1 + 0xc) * 4 + 4) + 1;
            *(int *)(gValid_Nonce_Num + (uint)param_1 * 4) =
                 *(int *)(gValid_Nonce_Num + (uint)param_1 * 4) + 1;
            *(int *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + uVar3) * 4) =
                 *(int *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + uVar3) * 4) + 1;
          }
          else {
            *(int *)(gRepeated_Nonce_Id + (uint)param_1 * 4) =
                 *(int *)(gRepeated_Nonce_Id + (uint)param_1 * 4) + 1;
            *(int *)(iVar1 + (param_1 + 0xc) * 4 + 4) =
                 *(int *)(iVar1 + (param_1 + 0xc) * 4 + 4) + 1;
          }
        }
        else {
          pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + (uint)param_1 * 0x18));
          local_14 = 0;
          while ((local_14 < gWork_Num_For_Hw_Check &&
                 (local_1c = check_hw(gWorks_For_Hw_Check + (uint)param_1 * 0x488 + local_14 * 0x74,
                                      uVar2,0), local_1c != 0))) {
            local_14 = local_14 + 1;
          }
          pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + (uint)param_1 * 0x18));
          if (local_1c == 1) {
            *(int *)(gHw_Nonce_Num + (uint)param_1 * 4) =
                 *(int *)(gHw_Nonce_Num + (uint)param_1 * 4) + 1;
            printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",
                   "single_BM1385_check_nonce",(uint)param_1,0,uVar3,uVar2);
          }
        }
        uVar5 = 0;
      }
      else {
        printf("%s: received work_id = %02d nonce. error!!!\t","single_BM1385_check_nonce",uVar4);
        printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
               (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
        uVar5 = 0xffffffff;
      }
    }
    else {
      printf("%s: received core%02d nonce. error!!!\t","single_BM1385_check_nonce",uVar3);
      printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
      uVar5 = 0xffffffff;
    }
  }
  else {
    printf("%s: received ASIC%02d nonce. error!!!\t","single_BM1385_check_nonce",iVar1);
    printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
           (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

