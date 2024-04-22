
undefined4 get_works(void)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char acStack_134 [256];
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  
  memset(acStack_134,0,0x100);
  local_14 = 0x54;
  local_28 = 0;
  local_18 = conf._92_4_;
  local_1c = conf._96_4_;
  local_20 = conf._100_4_;
  local_24 = conf._104_4_;
  local_c = 0;
  while( true ) {
    if (local_14 <= local_c) {
      cgpu._2562208_4_ = cgpu._2561696_4_;
      local_10 = 0;
      for (local_c = 0; local_c < local_14; local_c = local_c + 1) {
        if (*(int *)(cgpu + (int)(DES_ncbc_encrypt + local_c) * 4) < (int)cgpu._2562208_4_) {
          cgpu._2562208_4_ = *(undefined4 *)(cgpu + (int)(DES_ncbc_encrypt + local_c) * 4);
          local_10 = local_c;
        }
      }
      if (3 < log_level) {
        local_30 = fopen(log_file,"a+");
        if (local_30 != (FILE *)0x0) {
          fprintf(local_30,"%s:%d: min work minertest[%d]:%d\n\n\n","driver-bitmain.c",0x6a1,
                  local_10,cgpu._2562208_4_);
        }
        fclose(local_30);
      }
      if ((int)cgpu._2562208_4_ < (int)conf._0_4_) {
        if (1 < log_level) {
          local_34 = fopen(log_file,"a+");
          if (local_34 != (FILE *)0x0) {
            fprintf(local_34,"%s:%d: $$$$dataCount=%d, but min work subid=%d\n","driver-bitmain.c",
                    0x6a5,conf._0_4_,cgpu._2562208_4_);
          }
          fclose(local_34);
        }
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
      return uVar2;
    }
    sprintf(acStack_134,"%s%02i.bin",DAT_0001be34,local_c + 1);
    pFVar1 = fopen(acStack_134,"rb");
    *(FILE **)(cgpu + local_c * 4) = pFVar1;
    if (*(int *)(cgpu + local_c * 4) == 0) break;
    uVar2 = get_work(local_c,5000);
    *(undefined4 *)(cgpu + (int)(DES_ncbc_encrypt + local_c) * 4) = uVar2;
    fclose(*(FILE **)(cgpu + local_c * 4));
    local_c = local_c + 1;
  }
  if (1 < log_level) {
    local_2c = fopen(log_file,"a+");
    if (local_2c != (FILE *)0x0) {
      fprintf(local_2c,"%s:%d: Open test file %s error\n","driver-bitmain.c",0x68f,acStack_134);
    }
    fclose(local_2c);
  }
  return 0xffffffff;
}

