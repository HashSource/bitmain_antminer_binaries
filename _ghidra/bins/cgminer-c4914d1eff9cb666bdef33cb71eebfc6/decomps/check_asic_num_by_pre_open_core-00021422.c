
_Bool check_asic_num_by_pre_open_core(int chain)

{
  _Bool _Var1;
  FILE *pFVar2;
  int chain_local;
  FILE *pFile_1;
  FILE *pFile;
  int try_count;
  int i;
  _Bool ret;
  
  ret = false;
  i = 0;
  while( true ) {
    if (1 < i) {
      return ret;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Try to find asic by pre core: times %d\n","driver-btm-soc.c",0xee7
                ,"check_asic_num_by_pre_open_core",i);
      }
      fclose(pFVar2);
    }
    ret = check_asic_num_without_power_off(chain,'\0');
    if (ret) break;
    _Var1 = is_T11();
    if ((!_Var1) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        get_average_voltage();
        fprintf(pFVar2,"%s:%d:%s: the current avg vol is %5.2f\n","driver-btm-soc.c",0xef3,
                "check_asic_num_by_pre_open_core");
      }
      fclose(pFVar2);
    }
    i = i + 1;
  }
  return ret;
}

