
_Bool check_asic_num_without_power_off(int chain,uchar set)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint uVar3;
  uchar set_local;
  int chain_local;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int open_core_count;
  
  hash_board_reset(chain);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Open %d core for chain %d\n","driver-btm-soc.c",0xec7,
              "check_asic_num_without_power_off",5,chain);
    }
    fclose(pFVar2);
  }
  open_core_BM1393_pre_open(chain,'\x05',set);
  check_asic_reg_oneChain(chain,0,false);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: chain %d, find asic num = %d\n","driver-btm-soc.c",0xecd,
              "check_asic_num_without_power_off",chain,(uint)dev->chain_asic_num[chain]);
    }
    fclose(pFVar2);
  }
  _Var1 = is_T11();
  if (!_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        get_average_voltage();
        fprintf(pFVar2,"%s:%d:%s: the current avg vol is %5.2f\n","driver-btm-soc.c",0xed0,
                "check_asic_num_without_power_off");
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        uVar3 = get_crc_count();
        fprintf(pFVar2,"%s:%d:%s: crc = %d\n","driver-btm-soc.c",0xed1,
                "check_asic_num_without_power_off",uVar3);
      }
      fclose(pFVar2);
    }
  }
  return dev->chain_asic_num[chain] == '<';
}

