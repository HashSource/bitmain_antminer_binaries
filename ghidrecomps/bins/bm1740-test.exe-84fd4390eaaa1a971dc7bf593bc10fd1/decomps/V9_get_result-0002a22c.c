
uint V9_get_result(byte param_1)

{
  uint uVar1;
  int iVar2;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_18 = 0;
  local_20 = 7;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("every ASIC require nonce number: %lu\n",Conf._64_4_ * 0x32);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (local_c % 9 == 0) {
      putchar(10);
    }
    uVar1 = calculate_how_many_nonce_per_asic_get(param_1,local_c,0x32);
    printf("asic[%02d]=%d\t",local_c,uVar1);
    if ((uVar1 <= (uint)(Conf._64_4_ * 0x32) && Conf._64_4_ * 0x32 - uVar1 != 0) &&
       (local_18 = local_18 + 1, (uint)Conf._244_4_ < local_18)) {
      local_20 = local_20 & 0xfffffffe;
    }
  }
  puts("\n");
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    uVar1 = calculate_how_many_nonce_per_asic_get(param_1,local_c,0x32);
    if (uVar1 <= (uint)(Conf._64_4_ * 0x32) && Conf._64_4_ * 0x32 - uVar1 != 0) {
      printf("asic[%02d] = %d\n",local_c,uVar1);
      iVar2 = *(int *)(cgpu + (local_c + 0x402a) * 4 + 4);
      local_1c = 0;
      for (local_10 = 0; local_10 < 0x32; local_10 = local_10 + 1) {
        if (*(uint *)(gAsic_Core_Nonce_Num +
                     (((uint)param_1 * 0x80 + local_c) * 0x80 + local_10) * 4) < (uint)Conf._64_4_)
        {
          local_1c = local_1c + 1;
          if ((uint)Conf._248_4_ < local_1c) {
            local_20 = local_20 & 0xfffffffe;
          }
          if (*(uint *)(gAsic_Core_Nonce_Num +
                       (((uint)param_1 * 0x80 + local_c) * 0x80 + local_10) * 4) <
              (uint)Conf._252_4_) {
            local_20 = local_20 & 0xfffffffe;
          }
          printf("core[%02d] = %d,      lost these nonce : ",local_10,
                 *(undefined4 *)
                  (gAsic_Core_Nonce_Num + (((uint)param_1 * 0x80 + local_c) * 0x80 + local_10) * 4))
          ;
          for (local_14 = 0; local_14 < (uint)Conf._64_4_; local_14 = local_14 + 1) {
            if (*(int *)(iVar2 + (local_10 * Conf._64_4_ + local_14) * 0x38 + (param_1 + 0xc) * 4 +
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
  if ((uint)Conf._256_4_ < (uint)(&gHw_Nonce_Num)[param_1]) {
    local_20 = local_20 & 0xfffffffe;
    printf("ret = %d\n",local_20);
  }
  puts(
      "\n------------------------------------------------------------------------------------------------------\n"
      );
  if (*(char *)(&gSensor_OK + param_1) != '\x01') {
    local_20 = local_20 & 0xfffffffd;
  }
  if (gHigherThanAlarmTemp != '\0') {
    local_20 = local_20 & 0xfffffffb;
  }
  printf("Chain%d total valid nonce number: %d\n\n",(uint)param_1,(&gValid_Nonce_Num)[param_1]);
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
  printf("HW number = %d\n\n",(&gHw_Nonce_Num)[param_1]);
  return local_20;
}

