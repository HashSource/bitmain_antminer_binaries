
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
  undefined1 auStack_eb [3];
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
  buf_vil_tw[0xb] = 0;
  buf_vil_tw[0xc] = 0;
  data[4] = '\0';
  data[5] = '\0';
  data[6] = '\0';
  data[7] = '\0';
  data[8] = '\0';
  data[9] = '\0';
  data[10] = '\0';
  data[0xb] = '\0';
  data[0xc] = '\0';
  data[0xd] = '\0';
  data[0xe] = '\0';
  data[0xf] = '\0';
  data[0x10] = '\0';
  data[0x11] = '\0';
  data[0x12] = '\0';
  data[0x13] = '\0';
  data[0x14] = '\0';
  data[0x15] = '\0';
  data[0x16] = '\0';
  data[0x17] = '\0';
  data[0x18] = '\0';
  data[0x19] = '\0';
  data[0x1a] = '\0';
  data[0x1b] = '\0';
  data[0x1c] = '\0';
  data[0x1d] = '\0';
  data[0x1e] = '\0';
  data[0x1f] = '\0';
  data[0x20] = '\0';
  data[0x21] = '\0';
  data[0x22] = '\0';
  data[0x23] = '\0';
  data[0x24] = '\0';
  data[0x25] = '\0';
  data[0x26] = '\0';
  data[0x27] = '\0';
  data[0x28] = '\0';
  data[0x29] = '\0';
  data[0x2a] = '\0';
  data[0x2b] = '\0';
  data[0x2c] = '\0';
  data[0x2d] = '\0';
  data[0x2e] = '\0';
  data[0x2f] = '\0';
  data[0x30] = '\0';
  data[0x31] = '\0';
  data[0x32] = '\0';
  data[0x33] = '\0';
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

