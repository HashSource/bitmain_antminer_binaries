
undefined4 get_works(void)

{
  FILE *pFVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  char acStack_8c [64];
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  memset(acStack_8c,0,0x40);
  local_48 = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_4c = 0;
  local_38 = Conf._204_4_;
  local_3c = Conf._208_4_;
  local_40 = Conf._212_4_;
  local_44 = Conf._216_4_;
  printf("\n--- %s\n","get_works");
  if (Conf._108_4_ == 1) {
    for (local_18 = 0; local_18 < 0x20; local_18 = local_18 + 1) {
      if ((local_38 & 1) != 0) {
        local_28 = local_28 + 1;
      }
      local_38 = local_38 >> 1;
      if ((local_3c & 1) != 0) {
        local_28 = local_28 + 1;
      }
      local_3c = local_3c >> 1;
      if ((local_40 & 1) != 0) {
        local_28 = local_28 + 1;
      }
      local_40 = local_40 >> 1;
      if ((local_44 & 1) != 0) {
        local_28 = local_28 + 1;
      }
      local_44 = local_44 >> 1;
    }
    printf("%s: single ASIC : we need test %d cores\n\n","get_works",local_28);
  }
  local_38 = Conf._204_4_;
  local_3c = Conf._208_4_;
  local_40 = Conf._212_4_;
  local_44 = Conf._216_4_;
  if (Conf._116_4_ == 0x569) {
    local_24 = 0x32;
  }
  if (gHashBoard_V9 != '\0') {
    local_20 = 4;
  }
  local_2c = 0;
  if (Conf._108_4_ == 1) {
    for (local_14 = 0; local_14 < local_28; local_14 = local_14 + 1) {
      for (; local_2c < (int)local_24; local_2c = local_2c + 1) {
        if (local_2c < 0x20) {
          if ((local_38 & 1) != 0) {
            sprintf(acStack_8c,"%s%s%02i.txt",DAT_00021990,DAT_00021994,local_2c);
            local_2c = local_2c + 1;
            local_38 = local_38 >> 1;
            break;
          }
          local_38 = local_38 >> 1;
        }
        else if ((local_2c < 0x20) || (0x3f < local_2c)) {
          if ((local_2c < 0x40) || (0x5f < local_2c)) {
            if ((local_44 & 1) != 0) {
              sprintf(acStack_8c,"%s%s%02i.txt",DAT_00021990,DAT_00021994,local_2c);
              local_2c = local_2c + 1;
              local_44 = local_44 >> 1;
              break;
            }
            local_44 = local_44 >> 1;
          }
          else {
            if ((local_40 & 1) != 0) {
              sprintf(acStack_8c,"%s%s%02i.txt",DAT_00021990,DAT_00021994,local_2c);
              local_2c = local_2c + 1;
              local_40 = local_40 >> 1;
              break;
            }
            local_40 = local_40 >> 1;
          }
        }
        else {
          if ((local_3c & 1) != 0) {
            sprintf(acStack_8c,"%s%s%02i.txt",DAT_00021990,DAT_00021994,local_2c);
            local_2c = local_2c + 1;
            local_3c = local_3c >> 1;
            break;
          }
          local_3c = local_3c >> 1;
        }
      }
      pFVar1 = fopen(acStack_8c,"r");
      *(FILE **)(cgpu + local_14 * 4) = pFVar1;
      if (*(int *)(cgpu + local_14 * 4) == 0) {
        printf("%s: Open test file %s error\n","get_works",acStack_8c);
        return 0xffffffff;
      }
      uVar3 = get_work(local_14,Conf._64_4_);
      *(undefined4 *)(cgpu + (local_14 + 0x40aa) * 4 + 4) = uVar3;
      fclose(*(FILE **)(cgpu + local_14 * 4));
    }
  }
  else {
    for (local_34 = 0; local_34 < local_20; local_34 = local_34 + 1) {
      pvVar2 = malloc(local_24 * Conf._64_4_ * 0x38);
      *(void **)(cgpu + (local_34 + 0x402a) * 4 + 4) = pvVar2;
      if (*(int *)(cgpu + (local_34 + 0x402a) * 4 + 4) == 0) {
        printf("%s: malloc struct work err!\n","get_works");
        return 0xffffffff;
      }
      for (local_30 = 0; local_30 < local_24; local_30 = local_30 + 1) {
        sprintf(acStack_8c,"%s%02i%s%02i.txt",DAT_00021990,local_34,DAT_00021994,local_30);
        iVar4 = local_34 * local_24 + local_30;
        pFVar1 = fopen(acStack_8c,"r");
        *(FILE **)(cgpu + iVar4 * 4) = pFVar1;
        if (*(int *)(cgpu + (local_34 * local_24 + local_30) * 4) == 0) {
          printf("%s: Open test file %s error\n","get_works",acStack_8c);
          return 0xffffffff;
        }
        iVar4 = local_34 * local_24 + local_30;
        uVar3 = get_work_hash_board(local_34,local_30,
                                    *(undefined4 *)(cgpu + (local_34 * local_24 + local_30) * 4),
                                    Conf._64_4_);
        *(undefined4 *)(cgpu + (iVar4 + 0x40aa) * 4 + 4) = uVar3;
        fclose(*(FILE **)(cgpu + (local_34 * local_24 + local_30) * 4));
      }
    }
  }
  cgpu._131756_4_ = cgpu._66220_4_;
  local_1c = 0;
  if (Conf._108_4_ == 1) {
    for (local_14 = 0; local_14 < local_28; local_14 = local_14 + 1) {
      if (*(int *)(cgpu + (local_14 + 0x40aa) * 4 + 4) < (int)cgpu._131756_4_) {
        cgpu._131756_4_ = *(undefined4 *)(cgpu + (local_14 + 0x40aa) * 4 + 4);
        local_1c = local_14;
      }
    }
  }
  else {
    for (local_14 = 0; local_24 * local_20 - local_14 != 0 && local_14 <= (int)(local_24 * local_20)
        ; local_14 = local_14 + 1) {
      if (*(int *)(cgpu + (local_14 + 0x40aa) * 4 + 4) < (int)cgpu._131756_4_) {
        cgpu._131756_4_ = *(undefined4 *)(cgpu + (local_14 + 0x40aa) * 4 + 4);
        local_1c = local_14;
      }
    }
  }
  if ((uint)cgpu._131756_4_ < (uint)Conf._64_4_) {
    write_lcd(1,"Get Less Work",0xd);
    printf("%s: cgpu.subid[%d] = %d, is the least pattern number\n","get_works",local_1c,
           cgpu._131756_4_);
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

