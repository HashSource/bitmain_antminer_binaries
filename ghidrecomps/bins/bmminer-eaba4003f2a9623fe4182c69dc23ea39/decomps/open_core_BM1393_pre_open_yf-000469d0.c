
void open_core_BM1393_pre_open_yf(uchar num,int chain)

{
  uchar core_id_00;
  uint uVar1;
  uchar chain_00;
  int chain_local;
  uchar num_local;
  char tmp42 [2048];
  vil_work_1387 work_vil_1387;
  vil_work work_vil;
  uchar buf_vil [9];
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
  uint i;
  uint loop;
  uint m;
  
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
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffdf);
  set_hash_counting_number(0);
  printf("%s: pre open core = %d\n","open_core_BM1393_pre_open_yf",(uint)num);
  for (m = 0; m < 5; m = m + 1) {
    for (loop = 0; loop < num; loop = loop + 1) {
      core_id_00 = (uchar)loop;
      chain_00 = (uchar)chain;
      enable_core_clock_BM1390(core_id_00,'\x01',chain_00);
      usleep(1000);
      enable_core_clock_BM1390(core_id_00 + '4','\x01',chain_00);
      usleep(1000);
      enable_core_clock_BM1390(core_id_00 + 'h','\x01',chain_00);
      usleep(1000);
      enable_core_clock_BM1390(core_id_00 + 0x9c,'\x01',chain_00);
      usleep(1000);
    }
    buf_vil_tw[0] = (chain & 0xffU) << 0x10 | 0x1000080;
    while( true ) {
      uVar1 = get_buffer_space();
      if ((uVar1 & 1 << (chain & 0xffU)) != 0) break;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: chain%d work fifo not ready: 0x%x\n",
                 "open_core_BM1393_pre_open_yf",chain,uVar1);
        _applog(7,tmp42,false);
      }
      usleep(1000);
    }
    set_TW_write_command_vil(buf_vil_tw);
    usleep(100000);
  }
  printf("--- %s end\n","open_core_BM1393_pre_open_yf");
  return;
}

