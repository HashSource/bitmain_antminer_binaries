
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
  
  asic_regs[0] = '\0';
  asic_regs[1] = '\x04';
  asic_regs[2] = '\b';
  asic_regs[3] = '\f';
  asic_regs[4] = '\x10';
  asic_regs[5] = '\x14';
  asic_regs[6] = '\x18';
  asic_regs[7] = ' ';
  asic_regs[8] = '8';
  asic_regs[9] = 'D';
  asic_regs[10] = 'H';
  asic_regs[0xb] = 'L';
  asic_regs[0xc] = 'P';
  asic_regs[0xd] = 'T';
  asic_regs[0xe] = 'X';
  asic_regs[0xf] = '\\';
  asic_regs[0x10] = '`';
  asic_regs[0x11] = 'd';
  asic_regs[0x12] = 'h';
  asic_regs[0x13] = 'l';
  asic_regs[0x14] = 'p';
  asic_regs[0x15] = 't';
  asic_regs[0x16] = 'x';
  asic_regs[0x17] = '|';
  asic_regs[0x18] = 0x80;
  asic_regs[0x19] = 0x84;
  asic_regs[0x1a] = 0x90;
  asic_regs[0x1b] = 0x94;
  asic_regs[0x1c] = 0x98;
  asic_regs[0x1d] = 0x9c;
  asic_regs[0x1e] = 0xa0;
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

