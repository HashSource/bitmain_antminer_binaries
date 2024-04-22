
undefined4 check_nonce(byte param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  if (Conf._116_4_ == 0x6ba) {
    local_20 = *param_2;
    local_14 = __udivsi3(*(byte *)((int)param_2 + 3),gChain_Asic_Interval);
    local_18 = *(byte *)param_2 & 0x7f;
    local_1c = *(byte *)((int)param_2 + 5) & 0x7f;
  }
  else if (Conf._116_4_ == 0x6bd) {
    local_20 = *param_2;
    local_14 = __udivsi3(*(byte *)(param_2 + 1),gChain_Asic_Interval);
    local_18 = (uint)*(byte *)((int)param_2 + 3) | (*(byte *)((int)param_2 + 2) & 1) << 8;
    local_1c = *(byte *)((int)param_2 + 6) & 0x7f;
  }
  if (local_14 < (uint)Conf._108_4_) {
    if (local_18 < (uint)Conf._112_4_) {
      if (local_1c < (uint)Conf._64_4_) {
        iVar2 = *(int *)(cgpu + (local_14 + 0x20028) * 4) +
                (local_18 * Conf._64_4_ + local_1c) * 0xcc;
        iVar3 = *(int *)(iVar2 + 4);
        *(int *)(gReceive_Nonce_Num + (uint)param_1 * 4) =
             *(int *)(gReceive_Nonce_Num + (uint)param_1 * 4) + 1;
        if (local_20 == iVar3) {
          if (*(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) == 0) {
            *(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) =
                 *(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) + 1;
            *(int *)(gValid_Nonce_Num + (uint)param_1 * 4) =
                 *(int *)(gValid_Nonce_Num + (uint)param_1 * 4) + 1;
            *(int *)(gAsic_Core_Nonce_Num +
                    (((uint)param_1 * 0x100 + local_14) * 0x200 + local_18) * 4) =
                 *(int *)(gAsic_Core_Nonce_Num +
                         (((uint)param_1 * 0x100 + local_14) * 0x200 + local_18) * 4) + 1;
          }
          else {
            *(int *)(gRepeated_Nonce_Id + (uint)param_1 * 4) =
                 *(int *)(gRepeated_Nonce_Id + (uint)param_1 * 4) + 1;
            *(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) =
                 *(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) + 1;
          }
        }
        else {
          pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + (uint)param_1 * 0x18));
          local_28 = 0;
          while ((local_28 < (int)(uint)*(byte *)((int)&gWork_Num_For_Hw_Check + (uint)param_1) &&
                 (local_24 = check_hw(gWorks_For_Hw_Check + (uint)param_1 * 0x7f8 + local_28 * 0xcc,
                                      local_20,*(byte *)(param_2 + 1),0), local_24 != 0))) {
            local_28 = local_28 + 1;
          }
          pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + (uint)param_1 * 0x18));
          if (local_24 == 1) {
            *(int *)(gHw_Nonce_Num + (uint)param_1 * 4) =
                 *(int *)(gHw_Nonce_Num + (uint)param_1 * 4) + 1;
            printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n","check_nonce",
                   (uint)param_1,local_14,local_18,local_20);
          }
        }
        uVar1 = 0;
      }
      else {
        printf("%s: received work_id = %02d nonce. error!!!\t","check_nonce",local_1c);
        printf(",received data is : 0x%02x%02x%02x%02x%02x%02x\n",(uint)*(byte *)param_2,
               (uint)*(byte *)((int)param_2 + 1),(uint)*(byte *)((int)param_2 + 2),
               (uint)*(byte *)((int)param_2 + 3),(uint)*(byte *)(param_2 + 1),
               (uint)*(byte *)((int)param_2 + 5));
        uVar1 = 0xffffffff;
      }
    }
    else {
      printf("%s: received core%02d nonce. error!!!\t","check_nonce",local_18);
      printf(",received data is : 0x%02x%02x%02x%02x%02x%02x\n",(uint)*(byte *)param_2,
             (uint)*(byte *)((int)param_2 + 1),(uint)*(byte *)((int)param_2 + 2),
             (uint)*(byte *)((int)param_2 + 3),(uint)*(byte *)(param_2 + 1),
             (uint)*(byte *)((int)param_2 + 5));
      uVar1 = 0xffffffff;
    }
  }
  else {
    printf("%s: received ASIC%02d nonce. error!!!\t","check_nonce",local_14);
    printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*(byte *)param_2,
           (uint)*(byte *)((int)param_2 + 1),(uint)*(byte *)((int)param_2 + 2),
           (uint)*(byte *)((int)param_2 + 3),(uint)*(byte *)(param_2 + 1));
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

