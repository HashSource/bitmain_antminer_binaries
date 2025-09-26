
void set_register_stage_3(float *matrix)

{
  float fVar1;
  uint32_t uVar2;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [2048];
  int freq [14];
  int temp [14];
  pll_userdivider_t user_divider;
  uint32_t Timeout_1;
  uint32_t Timeout;
  int temp_freq;
  int n;
  int i;
  
  set_chain_baud((uint8_t)(g_rt.config)->chain,((g_rt.config)->speed).baudrate);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set chain baud as %d\n","set_register_stage_3",((g_rt.config)->speed).baudrate);
  snprintf(tmp1,0x800,"Set chain baud as %d",((g_rt.config)->speed).baudrate);
  log_to_file(tmp1,time_stamp);
  usleep(5000);
  do_core_reset((uint8_t *)0x0);
  usleep(1000000);
  memset(&user_divider,0,4);
  set_chain_pllparameter_userdivider((uint8_t)(g_rt.config)->chain,'\0',user_divider);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x\n"
         ,"set_register_stage_3",(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
         (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  snprintf(tmp1,0x800,
           "Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x"
           ,(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
           (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  temp[0] = 0x27;
  temp[1] = 0x2a;
  temp[2] = 0x2d;
  temp[3] = 0x30;
  temp[4] = 0x31;
  temp[5] = 0x32;
  temp[6] = 0x33;
  temp[7] = 0x34;
  temp[8] = 0x35;
  temp[9] = 0x36;
  temp[10] = 0x37;
  temp[0xb] = 0x38;
  temp[0xc] = 0x39;
  temp[0xd] = 0x3a;
  freq[0] = 0x32;
  freq[1] = 0x96;
  freq[2] = 200;
  freq[3] = 0xfa;
  freq[4] = 0x10e;
  freq[5] = 0x122;
  freq[6] = 0x136;
  freq[7] = 0x14a;
  freq[8] = 0x15e;
  freq[9] = 0x172;
  freq[10] = 0x186;
  freq[0xb] = 0x19a;
  freq[0xc] = 0x1ae;
  freq[0xd] = 0x1c2;
  fVar1 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
  uVar2 = (uint)(0.0 < fVar1) * (int)fVar1;
  snprintf(tmp1,0x100,"temp_freq: %d",uVar2);
  puts(tmp1);
  n = 0;
  i = 0;
  do {
    if (0xd < (uint)i) {
LAB_0008faee:
      for (i = 0; i < n; i = i + 1) {
        pt_inc_freq_delay(freq[i],freq[i + 1],temp[i]);
      }
      if (freq[n] != uVar2) {
        inc_freq_with_fix((uint8_t)(g_rt.config)->chain,(uint8_t)((g_rt.config)->reg).clk_sel,
                          freq[n],uVar2,6.25);
        sleep(5);
      }
      g_rt.read_asic_temp = 0;
      if ((g_rt.config)->is_super == false) {
        set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0x7f);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Set TM as 0x%08x\n","set_register_stage_3",0x7f);
        snprintf(tmp1,0x800,"Set TM as 0x%08x",0x7f);
        log_to_file(tmp1,time_stamp);
        uart_flush_rx((g_rt.config)->chain);
        fVar1 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
        uVar2 = __aeabi_uidiv(0x1ffff,(uint)(0.0 < fVar1) * (int)fVar1);
        dhash_set_timeout(uVar2);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Set timeout by real freq: %d\n\n","set_register_stage_3",uVar2);
        snprintf(tmp1,0x800,"Set timeout by real freq: %d\n",uVar2);
        log_to_file(tmp1,time_stamp);
      }
      else {
        set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0xffffffff);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Set TM as 0x%08x\n","set_register_stage_3",0xffffffff);
        snprintf(tmp1,0x800,"Set TM as 0x%08x",0xffffffff);
        log_to_file(tmp1,time_stamp);
        fVar1 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
        uVar2 = __aeabi_uidiv(0x1ffff,(uint)(0.0 < fVar1) * (int)fVar1);
        uart_flush_rx((g_rt.config)->chain);
        dhash_set_timeout(uVar2);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Set timeout by using config value: %d\n\n","set_register_stage_3",uVar2);
        snprintf(tmp1,0x800,"Set timeout by using config value: %d\n",uVar2);
        log_to_file(tmp1,time_stamp);
      }
      set_chain_core_nonce_overflow_control((uint8_t)(g_rt.config)->chain,false);
      return;
    }
    if ((int)uVar2 < freq[i]) {
      n = i + -1;
      goto LAB_0008faee;
    }
    i = i + 1;
  } while( true );
}

