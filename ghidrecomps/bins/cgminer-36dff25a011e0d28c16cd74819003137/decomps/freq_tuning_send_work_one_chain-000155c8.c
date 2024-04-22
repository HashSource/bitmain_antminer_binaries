
void * freq_tuning_send_work_one_chain(void *args)

{
  FILE *pFVar1;
  uint uVar2;
  uint uVar3;
  freq_tuning_work *pfVar4;
  freq_tuning_work *__src;
  void *args_local;
  timeval diff;
  timeval end;
  timeval start;
  uint32_t buf_vil [13];
  vil_work_1387 work_vil_1387;
  FILE *pFile;
  freq_tuning_work *work_for_pattern;
  uint32_t work_fifo_ready;
  freq_tuning_work *works_for_asic;
  FILE *pFile_2;
  FILE *pFile_1;
  int chain;
  send_work_parameter *param;
  int sleep_count;
  int j;
  uint32_t work_id;
  int pattern;
  int core;
  int asic;
  
  memset(buf_vil,0,0x34);
  work_id = 0;
  sleep_count = 0;
  if (*(int *)((int)args + 4) == 0) {
    cgtime(&start);
                    /* WARNING: Load size is inaccurate */
    uVar3 = *args;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Frequency tuning: send work for chain %d\n","freq_tuning.c",0x38d,
                "freq_tuning_send_work_one_chain",uVar3);
      }
      fclose(pFVar1);
    }
    for (asic = 0; asic < 0x30; asic = asic + 1) {
      pfVar4 = g_works[asic];
      for (core = 0; core < 0x2a0; core = core + 1) {
        for (pattern = 0; pattern < 1; pattern = pattern + 1) {
          while (uVar2 = get_buffer_space(), (uVar2 & 1 << (uVar3 & 0xff)) == 0) {
            usleep(1000);
            sleep_count = sleep_count + 1;
          }
          memset(buf_vil,0,0x34);
          __src = pfVar4 + pattern + core;
          memset(&work_vil_1387,0,0x34);
          work_vil_1387.work_type = '\x01';
          work_vil_1387.chain_id = ~((byte)~(byte)((uint)((int)(char)uVar3 << 0x19) >> 0x18) >> 1);
          buf_vil[1] = work_id & 0x7f | pattern << 7;
          work_vil_1387.data._0_4_ = *(undefined4 *)__src->data;
          work_vil_1387.data._4_4_ = *(undefined4 *)(__src->data + 4);
          work_vil_1387.data._8_4_ = *(undefined4 *)(__src->data + 8);
          work_vil_1387.midstate._0_4_ = *(undefined4 *)__src->midstate;
          work_vil_1387.midstate._4_4_ = *(undefined4 *)(__src->midstate + 4);
          work_vil_1387.midstate._8_4_ = *(undefined4 *)(__src->midstate + 8);
          work_vil_1387.midstate._12_4_ = *(undefined4 *)(__src->midstate + 0xc);
          work_vil_1387.midstate._16_4_ = *(undefined4 *)(__src->midstate + 0x10);
          work_vil_1387.midstate._20_4_ = *(undefined4 *)(__src->midstate + 0x14);
          work_vil_1387.midstate._24_4_ = *(undefined4 *)(__src->midstate + 0x18);
          work_vil_1387.midstate._28_4_ = *(undefined4 *)(__src->midstate + 0x1c);
          buf_vil[0] = (uint)work_vil_1387.chain_id << 0x10 | 0x1000000 |
                       (uint)work_vil_1387.reserved1[0] << 8 | (uint)work_vil_1387.reserved1[1];
          for (j = 2; (uint)j < 5; j = j + 1) {
            buf_vil[j] = (uint)work_vil_1387.reserved1[j * 4 + -2] << 0x18 |
                         (uint)work_vil_1387.reserved1[j * 4 + -1] << 0x10 |
                         (uint)work_vil_1387.reserved1[j * 4] << 8 |
                         (uint)work_vil_1387.reserved1[j * 4 + 1];
          }
          for (j = 5; (uint)j < 0xd; j = j + 1) {
            buf_vil[j] = (uint)work_vil_1387.reserved1[j * 4 + -2] << 0x18 |
                         (uint)work_vil_1387.reserved1[j * 4 + -1] << 0x10 |
                         (uint)work_vil_1387.reserved1[j * 4] << 8 |
                         (uint)work_vil_1387.reserved1[j * 4 + 1];
          }
          work_vil_1387.work_count = buf_vil[1];
          set_TW_write_command_vil(buf_vil);
          send_work_num[uVar3] = send_work_num[uVar3] + 1;
          memcpy(g_work_for_hw_check[uVar3] + work_id,__src,0x34);
          work_id = work_id + 1;
          if (0x7f < work_id) {
            work_id = 0;
          }
        }
      }
    }
    *(undefined4 *)((int)args + 4) = 1;
    cgtime(&end);
    diff.tv_sec = end.tv_sec - start.tv_sec;
    if (end.tv_usec - start.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: Frequency tuning: send work for chain %d done, time cost %lds, sleep_count = %d\n"
                ,"freq_tuning.c",0x3d6,"freq_tuning_send_work_one_chain",uVar3,diff.tv_sec,
                sleep_count);
      }
      fclose(pFVar1);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
                    /* WARNING: Load size is inaccurate */
      fprintf(pFVar1,"%s:%d:%s: Send work for chain %d already done.\n","freq_tuning.c",0x385,
              "freq_tuning_send_work_one_chain",*args);
    }
    fclose(pFVar1);
  }
  return (void *)0x0;
}

