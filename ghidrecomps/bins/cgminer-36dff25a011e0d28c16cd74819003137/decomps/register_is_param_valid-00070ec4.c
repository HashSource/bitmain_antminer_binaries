
_Bool register_is_param_valid(int chain,uint8_t asic,uint8_t core)

{
  FILE *pFVar1;
  _Bool _Var2;
  uint8_t core_local;
  uint8_t asic_local;
  int chain_local;
  FILE *pFile;
  FILE *pFile_1;
  
  if ((chain < 0x10) && (dev->chain_exist[chain] != 0)) {
    if (asic < 0x30) {
      _Var2 = true;
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Invalid ASIC ID: %d\n","register.c",0x4bd,
                  "register_is_param_valid",(uint)asic);
        }
        fclose(pFVar1);
      }
      _Var2 = false;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Invalid chain ID: %d\n","register.c",0x4b7,
                "register_is_param_valid",chain);
      }
      fclose(pFVar1);
    }
    _Var2 = false;
  }
  return _Var2;
}

