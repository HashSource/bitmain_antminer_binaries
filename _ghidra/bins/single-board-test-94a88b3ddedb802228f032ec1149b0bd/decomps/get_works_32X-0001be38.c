
undefined4 get_works_32X(void)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char acStack_114 [256];
  FILE *local_14;
  int local_10;
  int local_c;
  
  memset(acStack_114,0,0x100);
  local_10 = 0;
  local_10 = calculate_asic_number(0x54);
  local_c = 0;
  while( true ) {
    if (local_10 <= local_c) {
      cgpu._2562208_4_ = cgpu._2561696_4_;
      for (local_c = 0; local_c < local_10; local_c = local_c + 1) {
        if (*(int *)(cgpu + (int)(DES_ncbc_encrypt + local_c) * 4) < (int)cgpu._2562208_4_) {
          cgpu._2562208_4_ = *(undefined4 *)(cgpu + (int)(DES_ncbc_encrypt + local_c) * 4);
        }
      }
      return 0;
    }
    sprintf(acStack_114,"%s/minertest64_%02d.bin","/etc/config/32xPatten",local_c + 1);
    pFVar1 = fopen(acStack_114,"rb");
    *(FILE **)(cgpu + local_c * 4) = pFVar1;
    if (*(int *)(cgpu + local_c * 4) == 0) break;
    uVar2 = get_work(local_c,5000);
    *(undefined4 *)(cgpu + (int)(DES_ncbc_encrypt + local_c) * 4) = uVar2;
    fclose(*(FILE **)(cgpu + local_c * 4));
    local_c = local_c + 1;
  }
  if (1 < log_level) {
    local_14 = fopen(log_file,"a+");
    if (local_14 != (FILE *)0x0) {
      fprintf(local_14,"%s:%d: Open test file %s error\n","driver-bitmain.c",0x6b9,acStack_114);
    }
    fclose(local_14);
  }
  return 0xffffffff;
}

