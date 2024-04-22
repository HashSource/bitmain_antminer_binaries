
uint single_board_get_result(byte param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_18 = 0;
  local_20 = 7;
  local_30 = 0;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("every ASIC require nonce number: %lu\n",Conf._112_4_ * Conf._64_4_);
  iVar2 = Conf._112_4_ * Conf._64_4_ * Conf._108_4_;
  puts("\n\nevery asic returned valid nonce count:");
  for (local_c = 0; local_c < (uint)Conf._108_4_; local_c = local_c + 1) {
    if (local_c % 9 == 0) {
      putchar(10);
    }
    uVar1 = calculate_how_many_nonce_per_asic_get(param_1,local_c & 0xff,Conf._112_4_);
    printf("asic[%02d]=%d\t",local_c,uVar1);
    if ((uVar1 <= (uint)(Conf._112_4_ * Conf._64_4_) && Conf._112_4_ * Conf._64_4_ - uVar1 != 0) &&
       (local_18 = local_18 + 1, (uint)Conf._232_4_ < local_18)) {
      local_20 = local_20 & 0xfffffffe;
    }
  }
  puts("\n\nevery asic returned all nonce count:");
  local_2c = 0;
  for (local_c = 0; local_c < (uint)Conf._108_4_; local_c = local_c + 1) {
    if (local_c % 9 == 0) {
      putchar(10);
    }
    local_24 = 0;
    for (local_10 = 0; local_10 < (uint)Conf._112_4_; local_10 = local_10 + 1) {
      for (local_14 = 0; local_14 < (uint)Conf._64_4_; local_14 = local_14 + 1) {
        local_24 = local_24 +
                   *(int *)(*(int *)(cgpu + (local_c + 0x20028) * 4) +
                            (local_10 * Conf._64_4_ + local_14) * 0xcc + (param_1 + 0x2e) * 4 + 4);
      }
    }
    printf("asic[%02d]=%d\t",local_c,local_24);
    local_2c = local_2c + local_24;
  }
  puts("\n\nevery asic returned repeated nonce count:");
  for (local_c = 0; local_c < (uint)Conf._108_4_; local_c = local_c + 1) {
    if (local_c % 9 == 0) {
      putchar(10);
    }
    local_28 = 0;
    for (local_10 = 0; local_10 < (uint)Conf._112_4_; local_10 = local_10 + 1) {
      for (local_14 = 0; local_14 < (uint)Conf._64_4_; local_14 = local_14 + 1) {
        iVar3 = *(int *)(cgpu + (local_c + 0x20028) * 4) +
                (local_10 * Conf._64_4_ + local_14) * 0xcc;
        if (*(int *)(iVar3 + (param_1 + 0x2e) * 4 + 4) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(iVar3 + (param_1 + 0x2e) * 4 + 4) + -1;
        }
        local_28 = local_28 + iVar3;
      }
    }
    printf("asic[%02d]=%d\t",local_c,local_28);
  }
  puts("\n");
  for (local_c = 0; local_c < (uint)Conf._108_4_; local_c = local_c + 1) {
    uVar1 = calculate_how_many_nonce_per_asic_get(param_1,local_c & 0xff,Conf._112_4_);
    if (uVar1 <= (uint)(Conf._112_4_ * Conf._64_4_) && Conf._112_4_ * Conf._64_4_ - uVar1 != 0) {
      printf("asic[%02d] = %d\n",local_c,uVar1);
      iVar3 = *(int *)(cgpu + (local_c + 0x20028) * 4);
      local_1c = 0;
      for (local_10 = 0; local_10 < (uint)Conf._112_4_; local_10 = local_10 + 1) {
        if (*(uint *)(gAsic_Core_Nonce_Num +
                     (((uint)param_1 * 0x100 + local_c) * 0x200 + local_10) * 4) < (uint)Conf._64_4_
           ) {
          local_1c = local_1c + 1;
          local_30 = local_30 + local_1c;
          if ((uint)Conf._236_4_ < local_1c) {
            local_20 = local_20 & 0xfffffffe;
          }
          if (*(uint *)(gAsic_Core_Nonce_Num +
                       (((uint)param_1 * 0x100 + local_c) * 0x200 + local_10) * 4) <
              (uint)Conf._240_4_) {
            local_20 = local_20 & 0xfffffffe;
          }
          printf("core[%02d] = %d,      lost these nonce : ",local_10,
                 *(undefined4 *)
                  (gAsic_Core_Nonce_Num + (((uint)param_1 * 0x100 + local_c) * 0x200 + local_10) * 4
                  ));
          for (local_14 = 0; local_14 < (uint)Conf._64_4_; local_14 = local_14 + 1) {
            if (*(int *)(iVar3 + (local_10 * Conf._64_4_ + local_14) * 0xcc + (param_1 + 0x2e) * 4 +
                        4) == 0) {
              printf("%d  ",local_14);
            }
          }
          putchar(10);
        }
      }
      puts("\n");
    }
  }
  if ((uint)Conf._248_4_ < *(uint *)(gHw_Nonce_Num + (uint)param_1 * 4)) {
    local_20 = local_20 & 0xfffffffe;
    printf("ret = %d\n",local_20);
  }
  if ((uint)Conf._244_4_ < (uint)(iVar2 - *(int *)(gValid_Nonce_Num + (uint)param_1 * 4))) {
    local_20 = local_20 & 0xfffffffe;
    printf("ret = %d\n",local_20);
  }
  puts(
      "\n------------------------------------------------------------------------------------------------------\n"
      );
  if (*(char *)((int)&gHigherThanAlarmTemp + (uint)param_1) != '\0') {
    local_20 = local_20 & 0xfffffffb;
  }
  printf("Chain%d total valid nonce number: %d\n\n",(uint)param_1,
         *(undefined4 *)(gValid_Nonce_Num + (uint)param_1 * 4));
  printf("Chain%d total returned nonce number: %d\n\n",(uint)param_1,local_2c);
  printf("Chain%d total repeated nonce number: %d\n\n",(uint)param_1,
         *(undefined4 *)(gRepeated_Nonce_Id + (uint)param_1 * 4));
  printf("Chain%d HW number = %d\n\n",(uint)param_1,
         *(undefined4 *)(gHw_Nonce_Num + (uint)param_1 * 4));
  printf("total invalid asic number %d\n",local_18);
  printf("total invalid core number %d\n",local_30);
  printf("total nonce expected %d lost %d allow most %d\n",iVar2,
         iVar2 - *(int *)(gValid_Nonce_Num + (uint)param_1 * 4),Conf._244_4_);
  if ((local_20 & 1) == 0) {
    puts("Pattern NG\n");
  }
  else {
    puts("Pattern OK\n");
  }
  if ((local_20 & 2) == 0) {
    puts("Sensor NG\n");
  }
  else {
    puts("Sensor OK\n");
  }
  if ((local_20 & 4) == 0) {
    puts("Temperature NG\n");
  }
  else {
    puts("Temperature OK\n");
  }
  return local_20;
}

