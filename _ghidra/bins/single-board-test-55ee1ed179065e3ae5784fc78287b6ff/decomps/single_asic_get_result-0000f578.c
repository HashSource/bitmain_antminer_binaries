
int single_asic_get_result(byte param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_14 = 1;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("every CORE require nonce number: %lu\n\n",Conf._64_4_);
  puts("\n\nevery core returned valid nonce count:");
  uVar1 = cgpu._524448_4_;
  for (local_c = 0; local_c < (uint)Conf._112_4_; local_c = local_c + 1) {
    if (local_c % 10 == 0) {
      putchar(10);
    }
    printf("core[%02d]=%02d\t",local_c,
           *(undefined4 *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x20000 + local_c) * 4));
  }
  puts("\n\n");
  for (local_c = 0; local_c < (uint)Conf._112_4_; local_c = local_c + 1) {
    if (*(uint *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x20000 + local_c) * 4) <
        (uint)Conf._64_4_) {
      local_14 = 0;
      printf("core[%02d] = %d,      lost these pattern\'s nonce : ",local_c,
             *(undefined4 *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x20000 + local_c) * 4));
      for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
        if (*(int *)(uVar1 + (local_c * Conf._64_4_ + local_10) * 0xcc + (param_1 + 0x2e) * 4 + 4)
            == 0) {
          printf("%d  ",local_10);
        }
      }
      putchar(10);
    }
  }
  puts("\n\nevery core returned all nonce count:");
  for (local_c = 0; local_c < (uint)Conf._112_4_; local_c = local_c + 1) {
    local_18 = 0;
    if (local_c % 10 == 0) {
      putchar(10);
    }
    for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
      local_18 = local_18 +
                 *(int *)(uVar1 + (local_c * Conf._64_4_ + local_10) * 0xcc + (param_1 + 0x2e) * 4 +
                         4);
    }
    printf("core[%02d]=%02d\t",local_c,local_18);
  }
  puts("\n\nevery core returned repeated nonce count:");
  for (local_c = 0; local_c < (uint)Conf._112_4_; local_c = local_c + 1) {
    local_1c = 0;
    if (local_c % 10 == 0) {
      putchar(10);
    }
    for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
      iVar2 = uVar1 + (local_c * Conf._64_4_ + local_10) * 0xcc;
      if (*(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + (param_1 + 0x2e) * 4 + 4) + -1;
      }
      local_1c = local_1c + iVar2;
    }
    printf("core[%02d]=%02d\t",local_c,local_1c);
  }
  puts(
      "\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("Chain%d total valid nonce number: %d\n\n",(uint)param_1,
         *(undefined4 *)(gValid_Nonce_Num + (uint)param_1 * 4));
  printf("Chain%d total receive nonce number: %d\n\n",(uint)param_1,
         *(undefined4 *)(gReceive_Nonce_Num + (uint)param_1 * 4));
  printf("Chain%d total repeate nonce number: %d\n\n",(uint)param_1,
         *(undefined4 *)(gRepeated_Nonce_Id + (uint)param_1 * 4));
  printf("Chain%d HW number = %d\n\n",(uint)param_1,
         *(undefined4 *)(gHw_Nonce_Num + (uint)param_1 * 4));
  if (local_14 == 0) {
    puts("Pattern NG\n");
  }
  else {
    puts("Pattern OK\n");
  }
  return local_14;
}

