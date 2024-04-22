
void open_core_BM1393_S11_single_board(uchar chain)

{
  uint uVar1;
  uchar chain_local;
  char tmp42 [2048];
  vil_work_1387 work_vil_1387;
  vil_work work_vil;
  uchar buf_vil [9];
  uchar data [52];
  uint buf_vil_tw [13];
  uint buf [13];
  uint cmd_buf [3];
  uchar gateblk [4];
  uchar core_data;
  uint reg_data;
  uint core_index;
  uint which_chain;
  uint loop;
  uint work_fifo_ready;
  uint value;
  uint ret;
  uint work_id;
  uint j;
  uint i;
  uint core_id;
  uint slot;
  
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
  buf_vil_tw[0] = (uint)chain << 0x10 | 0x1000080;
  for (core_id = 0; core_id < 0x34; core_id = core_id + 1) {
    for (slot = 0; slot < 4; slot = slot + 1) {
      usleep(1000);
      enable_core_clock_BM1390((char)slot * '4' + (char)core_id,'\x01',chain);
    }
    usleep(5000);
    while( true ) {
      uVar1 = get_buffer_space();
      if ((uVar1 & 1 << chain) != 0) break;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: chain%d work fifo not ready: 0x%x\n",
                 "open_core_BM1393_S11_single_board",(uint)chain,uVar1);
        _applog(7,tmp42,false);
      }
      usleep(1000);
    }
    set_TW_write_command_vil(buf_vil_tw);
    usleep(100000);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s Done\n","open_core_BM1393_S11_single_board");
    _applog(5,tmp42,false);
  }
  return;
}

