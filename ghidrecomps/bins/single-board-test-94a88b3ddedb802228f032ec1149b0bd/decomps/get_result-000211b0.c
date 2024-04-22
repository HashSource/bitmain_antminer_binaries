
undefined4 get_result(int param_1,int param_2,undefined4 param_3)

{
  FILE *pFVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_14;
  uint local_10;
  
  puts(
      "\n------------------------------------------------------------------------------------------------------"
      );
  if (conf._40_4_ == 0) {
    puts("Command mode is VIL");
  }
  else {
    puts("Command mode is FIL");
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: require nonce number:%d\n","driver-bitmain.c",0x127c,param_2);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: require validnonce number:%d\n","driver-bitmain.c",0x127e,param_3);
    }
    fclose(pFVar1);
  }
  for (local_10 = 0; (int)local_10 < 0x54; local_10 = local_10 + 1) {
    if (5 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: \n Chain[%d], %dMhz, asic received valid nounce detail:\n",
                "driver-bitmain.c",0x1282,param_1,
                *(undefined4 *)(last_success_freq + param_1 * 0x400));
      }
      fclose(pFVar1);
    }
    for (local_10 = 0; (int)local_10 < 0x54; local_10 = local_10 + 1) {
      if (5 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"asic%02d:%03d  ",local_10,
                  *(undefined4 *)(asic_nonce_num + (local_10 + param_1 * 0x100) * 4));
        }
        fclose(pFVar1);
      }
      if (((local_10 + 1 & 7) == 0) && (5 < log_level)) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
    }
    if (5 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  for (local_10 = 0; (int)local_10 < 0x54; local_10 = local_10 + 1) {
    uVar2 = get_TestRet_ByCore(param_1,local_10,param_2);
    *(undefined4 *)(last_result + (local_10 + param_1 * 0x100) * 4) = uVar2;
    if (*(int *)(asic_nonce_num + (local_10 + param_1 * 0x100) * 4) < param_2) {
      for (local_14 = 0; local_14 < 0x72; local_14 = local_14 + 1) {
      }
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: \n\n","driver-bitmain.c",0x1300);
    }
    fclose(pFVar1);
  }
  for (local_10 = 0; (int)local_10 < 0x54; local_10 = local_10 + 1) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"freq[%02d]=%s  ",local_10,
                *(undefined4 *)
                 (freq_pll_1385 + *(int *)(last_freq + (local_10 + param_1 * 0x100) * 4) * 0x10));
      }
      fclose(pFVar1);
    }
    uVar3 = local_10 & 7;
    if ((int)local_10 < 1) {
      uVar3 = -(-local_10 & 7);
    }
    if ((uVar3 == 7) && (1 < log_level)) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  if (1 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite(&DAT_0012f5c0,1,2,pFVar1);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: total valid nonce number:%d\n","driver-bitmain.c",0x1312,
              *(undefined4 *)(valid_nonce_num + param_1 * 4));
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: total send work number:%d\n","driver-bitmain.c",0x1313,
              *(undefined4 *)(send_work_num + param_1 * 4));
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: require valid nonce number:%d\n","driver-bitmain.c",0x1314,param_3);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: repeated_nonce_num:%d\n","driver-bitmain.c",0x1316,
              *(undefined4 *)(repeated_nonce_num + param_1 * 4));
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: err_nonce_num:%d\n","driver-bitmain.c",0x1317,
              *(undefined4 *)(err_nonce_num + param_1 * 4));
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: last_nonce_num:%d\n","driver-bitmain.c",0x1318,
              *(undefined4 *)(last_nonce_num + param_1 * 4));
    }
    fclose(pFVar1);
  }
  return *(undefined4 *)(valid_nonce_num + param_1 * 4);
}

