
int single_BM1385_get_result(byte param_1)

{
  int iVar1;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_14 = 0;
  local_18 = 1;
  local_1c = Conf._204_4_;
  local_20 = Conf._208_4_;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("every CORE require nonce number: %lu\n\n",Conf._64_4_);
  printf("Open core number : Conf.OpenCoreNum1 = %u = 0x%08x\n",Conf._204_4_,Conf._204_4_);
  printf("Open core number : Conf.OpenCoreNum2 = %u = 0x%08x\n",Conf._208_4_,Conf._208_4_);
  printf("Open core number : Conf.OpenCoreNum3 = %u = 0x%08x\n",Conf._212_4_,Conf._212_4_);
  printf("Open core number : Conf.OpenCoreNum4 = %u = 0x%08x\n\n",Conf._216_4_,Conf._216_4_);
  for (local_c = 0; local_c < 0x32; local_c = local_c + 1) {
    if (local_c % 10 == 0) {
      putchar(10);
    }
    printf("core[%02d]=%02d\t",local_c,
           *(undefined4 *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + local_c) * 4));
  }
  puts("\n\n");
  for (local_c = 0; local_c < 0x32; local_c = local_c + 1) {
    if (local_c < 0x20) {
      if ((local_1c & 1) == 0) {
        local_1c = local_1c >> 1;
      }
      else {
        iVar1 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
        if (*(uint *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + local_c) * 4) <
            (uint)Conf._64_4_) {
          local_18 = 0;
          printf("core[%02d] = %d,      lost these nonce : ",local_c,
                 *(undefined4 *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + local_c) * 4));
          for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
            if (*(int *)(iVar1 + local_10 * 0x74 + (param_1 + 0xc) * 4 + 4) == 0) {
              printf("%d  ",local_10);
            }
          }
          putchar(10);
        }
        local_1c = local_1c >> 1;
        local_14 = local_14 + 1;
      }
    }
    else if ((local_c < 0x20) || (0x3f < local_c)) {
      printf("%s: which_core = %d, error!!!\n","single_BM1385_get_result",local_c);
    }
    else if ((local_20 & 1) == 0) {
      local_20 = local_20 >> 1;
    }
    else {
      iVar1 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
      if (*(uint *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + local_c) * 4) <
          (uint)Conf._64_4_) {
        local_18 = 0;
        printf("core[%02d] = %d,      lost these nonce : ",local_c,
               *(undefined4 *)(gAsic_Core_Nonce_Num + ((uint)param_1 * 0x4000 + local_c) * 4));
        for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
          if (*(int *)(iVar1 + local_10 * 0x74 + (param_1 + 0xc) * 4 + 4) == 0) {
            printf("%d  ",local_10);
          }
        }
        putchar(10);
      }
      local_20 = local_20 >> 1;
      local_14 = local_14 + 1;
    }
  }
  puts(
      "\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("Chain%d total valid nonce number: %d\n\n",(uint)param_1,
         *(undefined4 *)(gValid_Nonce_Num + (uint)param_1 * 4));
  if (local_18 == 0) {
    puts("Pattern NG\n");
  }
  else {
    puts("Pattern OK\n");
  }
  printf("HW number = %d\n\n",*(undefined4 *)(gHw_Nonce_Num + (uint)param_1 * 4));
  return local_18;
}

