
void open_core_BM1393_pre_open(uchar num,uchar set)

{
  uchar core_id_00;
  uint uVar1;
  uchar chain;
  uchar set_local;
  uchar num_local;
  char tmp42 [2048];
  vil_work_1387 work_vil_1387;
  vil_work work_vil;
  uchar buf_vil [9];
  undefined auStack_eb [3];
  uchar data [52];
  uint buf_vil_tw [13];
  uint buf [13];
  uint cmd_buf [3];
  uchar gateblk [4];
  uint reg_data;
  uint core_index;
  uint core_id;
  uint slot;
  uint which_chain;
  uint work_fifo_ready;
  uint value;
  uint ret;
  uint work_id;
  uint j;
  uint loop;
  uint m;
  uint i;
  
  buf_vil_tw[0] = 0;
  buf_vil_tw[1] = 0;
  buf_vil_tw[2] = 0;
  buf_vil_tw[3] = 0;
  buf_vil_tw[4] = 0;
  buf_vil_tw[5] = 0;
  buf_vil_tw[6] = 0;
  buf_vil_tw[7] = 0;
  buf_vil_tw[8] = 0;
  buf_vil_tw[9] = 0;
  buf_vil_tw[10] = 0;
  buf_vil_tw[11] = 0;
  buf_vil_tw[12] = 0;
  data[4] = '\0';
  data[5] = '\0';
  data[6] = '\0';
  data[7] = '\0';
  data[8] = '\0';
  data[9] = '\0';
  data[10] = '\0';
  data[11] = '\0';
  data[12] = '\0';
  data[13] = '\0';
  data[14] = '\0';
  data[15] = '\0';
  data[16] = '\0';
  data[17] = '\0';
  data[18] = '\0';
  data[19] = '\0';
  data[20] = '\0';
  data[21] = '\0';
  data[22] = '\0';
  data[23] = '\0';
  data[24] = '\0';
  data[25] = '\0';
  data[26] = '\0';
  data[27] = '\0';
  data[28] = '\0';
  data[29] = '\0';
  data[30] = '\0';
  data[31] = '\0';
  data[32] = '\0';
  data[33] = '\0';
  data[34] = '\0';
  data[35] = '\0';
  data[36] = '\0';
  data[37] = '\0';
  data[38] = '\0';
  data[39] = '\0';
  data[40] = '\0';
  data[41] = '\0';
  data[42] = '\0';
  data[43] = '\0';
  data[44] = '\0';
  data[45] = '\0';
  data[46] = '\0';
  data[47] = '\0';
  data[48] = '\0';
  data[49] = '\0';
  data[50] = '\0';
  data[51] = '\0';
  data[0] = 0xff;
  data[1] = '\0';
  data[2] = '\0';
  data[3] = '\0';
  printf("\n--- %s\n","open_core_BM1393_pre_open",0,auStack_eb);
  if (set != '\0') {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar1 & 0xffff7fdf | 0x8000);
    set_hash_counting_number(0);
  }
  printf("%s: pre open core = %d\n","open_core_BM1393_pre_open",(uint)num);
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] == 'l')) {
      for (m = 0; m < 5; m = m + 1) {
        for (loop = 0; loop < num; loop = loop + 1) {
          core_id_00 = (uchar)loop;
          chain = (uchar)i;
          enable_core_clock_BM1393(core_id_00,'\x01',chain);
          usleep(1000);
          enable_core_clock_BM1393(core_id_00 + '4','\x01',chain);
          usleep(1000);
          enable_core_clock_BM1393(core_id_00 + 'h','\x01',chain);
          usleep(1000);
          enable_core_clock_BM1393(core_id_00 + 0x9c,'\x01',chain);
          usleep(1000);
        }
        buf_vil_tw[0] = i << 0x10 | 0x1000080;
        while( true ) {
          uVar1 = get_buffer_space();
          if ((uVar1 & 1 << (i & 0xff)) != 0) break;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: chain%d work fifo not ready: 0x%x\n",
                     "open_core_BM1393_pre_open",i,uVar1);
            _applog(7,tmp42,false);
          }
          usleep(1000);
        }
        set_TW_write_command_vil(buf_vil_tw);
        usleep(100000);
      }
    }
  }
  if (set != '\0') {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar1 | 0x8000);
  }
  printf("--- %s end\n","open_core_BM1393_pre_open");
  return;
}

