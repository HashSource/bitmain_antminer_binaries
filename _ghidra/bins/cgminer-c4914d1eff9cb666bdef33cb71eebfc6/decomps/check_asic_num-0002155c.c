
int check_asic_num(int chain)

{
  _Bool _Var1;
  FILE *pFVar2;
  int iVar3;
  int chain_local;
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_1;
  int i_1;
  int i;
  
  find_asic_with_count = find_asic_with_count + 1;
  i = 0;
  while( true ) {
    if (1 < i) {
      find_asic_with_pre_open_core_count = find_asic_with_pre_open_core_count + 1;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: check asic num with pre_open_core\n","driver-btm-soc.c",0xf0a,
                  "check_asic_num");
        }
        fclose(pFVar2);
      }
      _Var1 = check_asic_num_by_pre_open_core(chain);
      if (_Var1) {
        iVar3 = 0;
      }
      else {
        disable_pic_dac((uint8_t)chain);
        _Var1 = is_force_mode();
        if (((!_Var1) && (_Var1 = is_fixed_mode(), !_Var1)) ||
           (_Var1 = is_re_open_core_now(), _Var1)) {
          dev->chain_exist[chain] = 0;
          dev->chain_num = dev->chain_num + 0xff;
        }
        else {
          for (i_1 = 0; i_1 < 0x10; i_1 = i_1 + 1) {
            if (dev->chain_exist[i_1] == 1) {
              disable_pic_dac((uint8_t)i_1);
            }
          }
          freq_scan_error_code_set(1,chain);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: chian %d check asic number failed! \n","driver-btm-soc.c",
                    0xf20,"check_asic_num",chain);
          }
          fclose(pFVar2);
        }
        iVar3 = -1;
      }
      return iVar3;
    }
    check_asic_reg_oneChain(chain,0,false);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: without pre_open_core chain %d, find asic num = %d\n",
                "driver-btm-soc.c",0xf02,"check_asic_num",chain,(uint)dev->chain_asic_num[chain]);
      }
      fclose(pFVar2);
    }
    if (dev->chain_asic_num[chain] == '<') break;
    hash_board_reset(chain);
    i = i + 1;
  }
  return 0;
}

