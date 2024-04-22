
void pre_open_core_one_chain(uint8_t num,uint8_t chain)

{
  uchar core_id;
  uint uVar1;
  FILE *pFVar2;
  uint8_t chain_local;
  uint8_t num_local;
  uint buf_vil_tw [13];
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  uint32_t work_fifo_ready;
  uint32_t loop;
  
  memset(buf_vil_tw,0,0x34);
  if (dev->chain_exist[chain] == 1) {
    for (loop = 0; loop < num; loop = loop + 1) {
      core_id = (uchar)loop;
      enable_core_clock_BM1393(core_id,'\x01',chain);
      enable_core_clock_BM1393(core_id + '4','\x01',chain);
      enable_core_clock_BM1393(core_id + 'h','\x01',chain);
      enable_core_clock_BM1393(core_id + 0x9c,'\x01',chain);
      buf_vil_tw[0] = (uint)chain << 0x10 | 0x1000080;
      while( true ) {
        uVar1 = get_buffer_space();
        if ((uVar1 & 1 << chain) != 0) break;
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: chain%d work fifo not ready: 0x%x\n","driver-btm-soc.c",0xeb0,
                    "pre_open_core_one_chain",(uint)chain,uVar1);
          }
          fclose(pFVar2);
        }
        usleep(1000);
      }
      set_TW_write_command_vil(buf_vil_tw);
      usleep(20000);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: for chain %d\n","driver-btm-soc.c",0xeb8,"pre_open_core_one_chain"
                ,(uint)chain);
      }
      fclose(pFVar2);
    }
  }
  else if (1 < log_level) {
    print_crt_time_to_file(log_file,1);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: filed on chain %d,do not exist!!\n","driver-btm-soc.c",0xebc,
              "pre_open_core_one_chain",(uint)chain);
    }
    fclose(pFVar2);
  }
  return;
}

