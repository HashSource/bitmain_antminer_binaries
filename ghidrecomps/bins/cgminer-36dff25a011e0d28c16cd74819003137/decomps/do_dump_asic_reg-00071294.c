
void do_dump_asic_reg(int chain,uint8_t asic)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint8_t asic_local;
  int chain_local;
  reg_status_t status;
  uint8_t asic_regs [31];
  FILE *pFile_1;
  FILE *pFile;
  uint32_t i;
  
  asic_regs._0_4_ = DAT_000aa2b4;
  asic_regs._4_4_ = DAT_000aa2b8;
  asic_regs._8_4_ = DAT_000aa2bc;
  asic_regs._12_4_ = DAT_000aa2c0;
  asic_regs._16_4_ = DAT_000aa2c4;
  asic_regs._20_4_ = DAT_000aa2c8;
  asic_regs._24_4_ = DAT_000aa2cc;
  asic_regs._28_2_ = (undefined2)DAT_000aa2d0;
  asic_regs[30] = (uint8_t)((uint)DAT_000aa2d0 >> 0x10);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Dump asic register start. chain = %d, asic = %d\n","register.c",
              0x513,"do_dump_asic_reg",chain,(uint)asic);
    }
    fclose(pFVar2);
  }
  pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
  _Var1 = register_is_param_valid(chain,asic,'\0');
  if (_Var1) {
    for (i = 0; i < 0x1f; i = i + 1) {
      memset(&status,0,8);
      register_send_asic_cmd_read_one(chain,asic,asic_regs[i]);
      register_receive_asic_response(chain,asic,asic_regs[i],&status);
      register_dump_asic_reg(asic_regs[i],&status);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Dump asic register done.\n","register.c",0x526,"do_dump_asic_reg");
    }
    fclose(pFVar2);
  }
  return;
}

