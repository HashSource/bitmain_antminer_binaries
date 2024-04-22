
void open_core_bm1391(_Bool set,uint8_t chain_mode)

{
  FILE *pFVar1;
  uint uVar2;
  uint8_t chain_mode_local;
  _Bool set_local;
  uint buf_vil_tw [13];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint core_index;
  uint work_fifo_ready;
  int slot;
  int core_id;
  uint i;
  
  memset(buf_vil_tw,0,0x34);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Start Open Core!!\n","driver-btm-soc.c",0x10e3,"open_core_bm1391");
    }
    fclose(pFVar1);
  }
  if (opt_multi_version != 0) {
    if (set) {
      uVar2 = get_dhash_acc_control();
      set_dhash_acc_control(uVar2 & 0xffff7fdf | 0x8000 | (opt_multi_version & 0xfU) << 8);
      set_hash_counting_number(0);
    }
    for (core_id = 0; core_id < 0x54; core_id = core_id + 1) {
      for (i = 0; i < 0x10; i = i + 1) {
        if ((((chain_mode == All_Chain) || (i == chain_mode)) && (dev->chain_exist[i] == 1)) &&
           (dev->chain_asic_num[i] == '0')) {
          buf_vil_tw[0] = i << 0x10 | 0x1000080;
          for (slot = 0; slot < 4; slot = slot + 1) {
            enable_core_clock_BM1391(slot * 0x54 + core_id,'\x01',(uchar)i);
          }
          cgsleep_ms(5);
          while( true ) {
            uVar2 = get_buffer_space();
            if ((uVar2 & 1 << (i & 0xff)) != 0) break;
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d:%s: chain%d work fifo not ready: 0x%x\n","driver-btm-soc.c",
                        0x1113,"open_core_bm1391",i,uVar2);
              }
              fclose(pFVar1);
            }
            usleep(1000);
          }
          set_TW_write_command_vil(buf_vil_tw);
          cgsleep_ms(10);
        }
      }
    }
    if (set) {
      uVar2 = get_dhash_acc_control();
      set_dhash_acc_control(uVar2 | 0x8000 | (opt_multi_version & 0xfU) << 8);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: End Open Core!!\n","driver-btm-soc.c",0x1129,"open_core_bm1391");
    }
    fclose(pFVar1);
  }
  return;
}

