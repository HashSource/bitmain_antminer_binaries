
void do_dump_core_reg(int chain,uint8_t asic,uint32_t core)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint32_t core_local;
  uint8_t asic_local;
  int chain_local;
  reg_status_t core_regs [8];
  FILE *pFile_1;
  FILE *pFile;
  uint8_t core_reg;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Dump core register start. chain = %d, asic = %d, core = %d\n",
              "register.c",0x4d0,"do_dump_core_reg",chain,(uint)asic,core);
    }
    fclose(pFVar2);
  }
  memset(core_regs,0,0x40);
  pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
  is_reading_core_reg = true;
  _Var1 = register_is_param_valid(chain,asic,(uint8_t)core);
  if (_Var1) {
    for (core_reg = '\0'; core_reg < 8; core_reg = core_reg + '\x01') {
      register_send_core_cmd_read_one(chain,asic,core,core_reg);
      register_receive_asic_response(chain,asic,'@',core_regs + core_reg);
      register_dump_core_reg(core_reg,core_regs + core_reg);
    }
  }
  is_reading_core_reg = false;
  pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Dump core register done.\n","register.c",0x4e7,"do_dump_core_reg");
    }
    fclose(pFVar2);
  }
  return;
}

