
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void open_core_bm1393(_Bool nullwork_enable)

{
  uint uVar1;
  _Bool nullwork_enable_local;
  char tmp42 [2048];
  char logstr [1024];
  vil_work_1387 work_vil_1387;
  vil_work work_vil;
  uchar buf_vil [9];
  uchar data [52];
  uint buf_vil_tw [13];
  uint buf [13];
  uint cmd_buf [3];
  uchar gateblk [4];
  int core_index;
  int wati_count;
  uint loop;
  uint work_fifo_ready;
  uint value;
  uint ret;
  uint work_id;
  uint j;
  int slot;
  int core_id;
  uint i;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42._0_4_ = open_core_bm1393::__FUNCTION__._0_4_;
    tmp42._4_4_ = open_core_bm1393::__FUNCTION__._4_4_;
    tmp42._8_4_ = open_core_bm1393::__FUNCTION__._8_4_;
    tmp42._12_4_ = open_core_bm1393::__FUNCTION__._12_4_;
    tmp42[16] = (char)ram0x000798cc;
    _applog(5,tmp42,false);
  }
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
  if (opt_multi_version != 0) {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar1 & 0xffff7fdf | 0x8000);
    set_hash_counting_number(0);
    for (core_id = 0; core_id < 0x34; core_id = core_id + 1) {
      for (i = 0; i < 0x10; i = i + 1) {
        if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] == 'l')) {
          buf_vil_tw[0] = i << 0x10 | 0x1000080;
          for (slot = 0; slot < 4; slot = slot + 1) {
            enable_core_clock_BM1393((char)slot * '4' + (char)core_id,'\x01',(uchar)i);
          }
          cgsleep_ms(5);
          while( true ) {
            uVar1 = get_buffer_space();
            if ((uVar1 & 1 << (i & 0xff)) != 0) break;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: chain%d work fifo not ready: 0x%x\n","open_core_bm1393",i,
                       uVar1);
              _applog(7,tmp42,false);
            }
            usleep(1000);
          }
          set_TW_write_command_vil(buf_vil_tw);
          cgsleep_ms(100);
        }
      }
    }
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar1 | 0x8000);
  }
  return;
}

