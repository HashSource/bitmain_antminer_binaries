
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void dump_all_asic_reg(void)

{
  byte bVar1;
  uint uVar2;
  FILE *pFVar3;
  char *pcVar4;
  int iVar5;
  uchar asic_regs [26];
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_5;
  FILE *pFile_6;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile;
  uchar chain;
  uchar reg;
  
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
  asic_regs[0x13] = 'p';
  asic_regs[0x14] = 't';
  asic_regs[0x15] = 'x';
  asic_regs[0x16] = '|';
  asic_regs[0x17] = 0x80;
  asic_regs[0x18] = 0x84;
  asic_regs[0x19] = 0x8c;
  memset(g_asic_data,0,0x3fc0);
  memset(g_asic_data_status,0,0xff0);
  memset(g_asic_core_data,0,0x3c0);
  memset(g_asic_core_data_status,0,0xf0);
  pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
  is_dump_asic_reg_all = true;
  for (reg = '\0'; reg < 0x1a; reg = reg + '\x01') {
    check_single_asic_reg((uint)asic_regs[reg]);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: ASIC REGISTER:\n","driver-btm-soc.c",0x1a42,"dump_all_asic_reg");
    }
    fclose(pFVar3);
  }
  for (reg = '\0'; reg < 0x1a; reg = reg + '\x01') {
    for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
      if ((dev->chain_exist[chain] != 0) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          bVar1 = asic_regs[reg];
          iVar5 = g_asic_data[chain][asic_regs[reg]];
          if (g_asic_data_status[chain][asic_regs[reg]] == '\0') {
            uVar2 = 0xca9c;
          }
          else {
            uVar2 = 0xca94;
          }
          pcVar4 = get_asic_reg_string(asic_regs[reg]);
          fprintf(pFVar3,"%s:%d:%s: Chain[%d], REG[0x%2X] = 0x%08X, %s, %s\n","driver-btm-soc.c",
                  0x1a4e,"dump_all_asic_reg",(uint)chain,(uint)bVar1,iVar5,uVar2 | 0x90000,pcVar4);
        }
        fclose(pFVar3);
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: \n","driver-btm-soc.c",0x1a51,"dump_all_asic_reg");
      }
      fclose(pFVar3);
    }
  }
  read_clock_delay_control_single_core();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: \n","driver-btm-soc.c",0x1a58,"dump_all_asic_reg");
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: ASIC CORE REGISTER:\n","driver-btm-soc.c",0x1a59,"dump_all_asic_reg"
             );
    }
    fclose(pFVar3);
  }
  for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
    if ((dev->chain_exist[chain] != 0) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        iVar5 = g_asic_core_data[chain][0];
        if (g_asic_core_data_status[chain][0] == '\0') {
          uVar2 = 0xca9c;
        }
        else {
          uVar2 = 0xca94;
        }
        pcVar4 = get_asic_core_reg_string('\0');
        fprintf(pFVar3,"%s:%d:%s: Chain[%d], CORE_REG[0x%2X] = 0x%08X, %s, %s\n","driver-btm-soc.c",
                0x1a64,"dump_all_asic_reg",(uint)chain,0,iVar5,uVar2 | 0x90000,pcVar4);
      }
      fclose(pFVar3);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: \n","driver-btm-soc.c",0x1a67,"dump_all_asic_reg");
    }
    fclose(pFVar3);
  }
  is_dump_asic_reg_all = false;
  pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
  return;
}

