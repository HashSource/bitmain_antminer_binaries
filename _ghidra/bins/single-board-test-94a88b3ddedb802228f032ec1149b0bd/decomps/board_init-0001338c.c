
void board_init(uint param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int local_14;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: board_init enter, chain_index = %d\n","board_frq_tuning.c",0x143,
              param_1);
    }
    fclose(pFVar1);
  }
  testDone[param_1] = 0;
  uVar2 = getPICvoltageFromValue(0x3a2);
  set_pic_voltage(param_1 & 0xff,uVar2);
  if (Conf._124_4_ != 0) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: \n--- check asic number\n","board_frq_tuning.c",0x14c);
      }
      fclose(pFVar1);
    }
    local_14 = 0;
    check_asic_reg_oneChain(param_1,CHIP_ADDRESS & 0xff);
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: check chain[%d]: asicNum = %d\n","board_frq_tuning.c",0x152,param_1,
                (uint)(byte)cgpu[param_1 + 0x271924]);
      }
      fclose(pFVar1);
    }
    while (cgpu[param_1 + 0x271924] != 'T') {
      local_14 = local_14 + 1;
      if (6 < local_14) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            uVar2 = get_crc_count();
            fprintf(pFVar1,"%s:%d: After Get ASIC NUM CRC error counter=%d\n","board_frq_tuning.c",
                    0x15a,uVar2);
          }
          fclose(pFVar1);
        }
        isNoBoardError = 1;
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d: The AsicNum=%d on chain[%d]\n","board_frq_tuning.c",0x15e,
                    (uint)(byte)cgpu[param_1 + 0x271924],param_1);
          }
          fclose(pFVar1);
        }
        testDone[param_1] = 1;
        search_over[param_1] = 1;
        *(undefined4 *)(searchFreqMode + param_1 * 4) = 0x19;
        search_freq_result[param_1] = 0;
        if (isChipNumOK_Once == '\0') {
          sprintf(search_failed_info,"J%d:2",param_1 + 1);
        }
        else {
          sprintf(search_failed_info,"J%d:3",param_1 + 1);
        }
        saveSearchFailedFlagInfo();
        searchStatus = 2;
        do {
          processTEST();
          sleep(1);
        } while( true );
      }
      set_reset_hashboard(param_1,1);
      disable_pic_dac(param_1 & 0xff);
      sleep(1);
      enable_pic_dac(param_1 & 0xff);
      sleep(1);
      set_reset_hashboard(param_1,1);
      sleep(3);
      set_reset_hashboard(param_1,0);
      sleep(1);
      cgpu[param_1 + 0x271924] = 0;
      check_asic_reg_oneChain(param_1,CHIP_ADDRESS & 0xff);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: retry check chain[%d]: asicNum = %d\n","board_frq_tuning.c",0x183,
                  param_1,(uint)(byte)cgpu[param_1 + 0x271924]);
        }
        fclose(pFVar1);
      }
    }
  }
  return;
}

