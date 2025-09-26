
void * software_pattern_cpugen_midstate_send_function(void *arg)

{
  uchar uVar1;
  _Bool _Var2;
  uint uVar3;
  bool bVar4;
  double dVar5;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  int times;
  work_format work_buf;
  uint32_t *work_ptr;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t core_num;
  uint32_t asic_num;
  uint64_t cnt;
  uint32_t work_id;
  uint32_t i;
  
  work_id = 0;
  times = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","software_pattern_cpugen_midstate_send_function");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  memset(&work_buf,0,0x214);
  dVar5 = log2((double)((Local_Config_Information->Hash_Board).Big_Core_Num - 1));
  dVar5 = pow(2.0,(double)(0x20 - (uint)(0.0 < dVar5 + 1.0) * (int)(longlong)(dVar5 + 1.0)));
  dVar5 = ((double)((uint)(0.0 < dVar5) * (int)(longlong)dVar5) * gnonce_percent_lenth) / 100.0 +
          1.0;
  gmax_nonce_super = (uint)(0.0 < dVar5) * (int)(longlong)dVar5;
  cnt._0_4_ = 0xb40e880;
  cnt._4_4_ = -0x80000000;
  do {
    while( true ) {
      if (cnt._4_4_ == -1 && (uint)cnt == 0xffffffff) {
        gStart_receive = false;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Stop receive thread\n","software_pattern_cpugen_midstate_send_function");
        builtin_strncpy(tmp1,"Stop receive thread",0x14);
        log_to_file(tmp1,time_stamp);
        return (void *)0x0;
      }
      uVar1 = is_work_fifo_ready(gChain);
      if (uVar1 != '\0') break;
      usleep(100);
    }
    work_buf.work_type = '\x01';
    work_buf.chain_id = (byte)gChain | 0x80;
    work_buf.reserved1[0] = '\0';
    work_buf.reserved1[1] = '\0';
    uVar3 = work_id << 7;
    work_buf.work_count =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | work_id << 0x1f;
    gen_midstate_char(midstate_char,CONCAT44(cnt._4_4_,(uint)cnt));
    for (i = 0; i < 0x10; i = i + 1) {
      s2hex(work_buf.midstate[i],midstate_char,0x40);
    }
    bVar4 = 0xfffffffe < (uint)cnt;
    uVar3 = (uint)cnt + 1;
    s2hex(work_buf.data,data_char,0x18);
    memcpy(g_works_for_check + work_id,&work_buf,0x214);
    for (i = 0; i < 0x85; i = i + 1) {
      *(uint *)(work_buf.reserved1 + i * 4 + -2) =
           *(int *)(work_buf.reserved1 + i * 4 + -2) << 0x18 |
           *(uint *)(work_buf.reserved1 + i * 4 + -2) >> 0x18 |
           (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff0000) >> 8 |
           (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff00) << 8;
    }
    set_TW_write_command((uint32_t *)&work_buf,0x214);
    cnt._0_4_ = (uint)cnt + 2;
    cnt._4_4_ = cnt._4_4_ + (uint)bVar4 + (uint)(0xfffffffe < uVar3);
    usleep((Local_Config_Information->Test_Info).Test_Speed.Timeout + 100);
    pthread_mutex_lock((pthread_mutex_t *)&g_map_mutex);
    flush_nonce(g_noncemap + g_id);
    work_id = work_id + 1;
    if (0xff < work_id) {
      work_id = 0;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&g_map_mutex);
    times = 0;
  } while ((work_id != 0) || (_Var2 = check_asic_nonce_full(&times), !_Var2));
  printf("flush nonce as bin file");
  flush_binfile();
                    /* WARNING: Subroutine does not return */
  exit(0);
}

