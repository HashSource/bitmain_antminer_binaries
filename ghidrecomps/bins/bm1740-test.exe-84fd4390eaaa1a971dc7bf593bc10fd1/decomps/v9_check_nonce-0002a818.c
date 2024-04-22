
undefined4 v9_check_nonce(byte param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int local_18;
  int local_14;
  
  local_14 = 0;
  uVar2 = (uint)param_2[3] |
          (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8;
  uVar1 = __udivsi3(*param_2,gChain_Asic_Interval);
  uVar3 = param_2[3] & 0x3f;
  uVar4 = param_2[4] & 0x7f;
  if (uVar1 < 4) {
    if (uVar3 < 0x32) {
      if (uVar4 < (uint)Conf._64_4_) {
        iVar6 = *(int *)(cgpu + (uVar1 + 0x402a) * 4 + 4) + (uVar3 * Conf._64_4_ + uVar4) * 0x38;
        if (uVar2 == *(uint *)(iVar6 + 4)) {
          if (*(int *)(iVar6 + (param_1 + 0xc) * 4 + 4) == 0) {
            *(int *)(iVar6 + (param_1 + 0xc) * 4 + 4) =
                 *(int *)(iVar6 + (param_1 + 0xc) * 4 + 4) + 1;
            (&gValid_Nonce_Num)[param_1] = (&gValid_Nonce_Num)[param_1] + 1;
            *(int *)(gAsic_Core_Nonce_Num + (((uint)param_1 * 0x80 + uVar1) * 0x80 + uVar3) * 4) =
                 *(int *)(gAsic_Core_Nonce_Num + (((uint)param_1 * 0x80 + uVar1) * 0x80 + uVar3) * 4
                         ) + 1;
          }
          else {
            (&gRepeated_Nonce_Id)[param_1] = (&gRepeated_Nonce_Id)[param_1] + 1;
            *(int *)(iVar6 + (param_1 + 0xc) * 4 + 4) =
                 *(int *)(iVar6 + (param_1 + 0xc) * 4 + 4) + 1;
          }
        }
        else {
          pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + (uint)param_1 * 0x18));
          local_18 = 0;
          while ((local_18 < (int)(uint)gWork_Num_For_Hw_Check &&
                 (local_14 = check_hw(gWorks_For_Hw_Check + (uint)param_1 * 0x230 + local_18 * 0x38,
                                      uVar2,0), local_14 != 0))) {
            local_18 = local_18 + 1;
          }
          pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + (uint)param_1 * 0x18));
          if (local_14 == 1) {
            (&gHw_Nonce_Num)[param_1] = (&gHw_Nonce_Num)[param_1] + 1;
            printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n","v9_check_nonce",
                   (uint)param_1,uVar1,uVar3,uVar2);
          }
        }
        uVar5 = 0;
      }
      else {
        printf("%s: received work_id = %02d nonce. error!!!\t","v9_check_nonce",uVar4);
        printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
               (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
        uVar5 = 0xffffffff;
      }
    }
    else {
      printf("%s: received core%02d nonce. error!!!\t","v9_check_nonce",uVar3);
      printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
      uVar5 = 0xffffffff;
    }
  }
  else {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

