
void do_dump_core_hash_clock_counter(int chain,uint8_t asic,uint32_t core)

{
  uint8_t core_00;
  _Bool _Var1;
  FILE *pFVar2;
  uint32_t core_local;
  uint8_t asic_local;
  int chain_local;
  core_reg_status_t core_regs;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(register_file_str,3);
    pFVar2 = fopen(register_file_str,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: chain[%d] asic[%02d] core[%03d]: ","register.c",0x1bd,
              "do_dump_core_hash_clock_counter",chain,(uint)asic,core);
    }
    fclose(pFVar2);
  }
  core_00 = (uint8_t)core;
  _Var1 = register_is_param_valid(chain,asic,core_00);
  if (_Var1) {
    memset(&core_regs,0,8);
    pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
    is_reading_core_reg = true;
    register_send_core_cmd_write_all(chain,asic,'\x05','\x01');
    register_send_cmd_read_one(chain,asic,core_00,'\x05');
    register_receive_core_response(chain,asic,&core_regs);
    register_send_cmd_read_one(chain,asic,core_00,'\x06');
    register_receive_core_response(chain,asic,&core_regs);
    register_dump_core_reg('\x06',&core_regs);
    register_send_core_cmd_write_all(chain,asic,'\x05','\0');
    is_reading_core_reg = false;
    pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
    if (4 < log_level) {
      print_crt_time_to_file(register_file_str,4);
      pFVar2 = fopen(register_file_str,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Dump core hash clock register done.\n","register.c",0x1de,
                "do_dump_core_hash_clock_counter");
      }
      fclose(pFVar2);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(register_file_str,3);
    pFVar2 = fopen(register_file_str,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: register is invalid.\n","register.c",0x1c1,
              "do_dump_core_hash_clock_counter");
    }
    fclose(pFVar2);
  }
  return;
}

