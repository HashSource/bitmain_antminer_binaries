
void scan_freq_init_highest_voltage(working_mode_e working_mode)

{
  _Bool _Var1;
  FILE *__stream;
  char *in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  working_mode_e working_mode_local;
  FILE *pFile;
  double max_volt;
  int chain;
  
  _Var1 = is_T11();
  if (_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        in_stack_ffffffc0 = "scan_freq_init_highest_voltage";
        fprintf(__stream,"%s:%d:%s: sweep open core at max voltage %.2f\n","driver-btm-soc.c",0x1f48
               );
      }
      fclose(__stream);
    }
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        set_highest_voltage_by_chain
                  ((uint8_t)chain,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
      }
    }
  }
  return;
}

