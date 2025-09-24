
void set_register_stage_3(float *matrix)

{
  int iVar1;
  float fVar2;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t user_divider;
  
  memset(&user_divider,0,4);
  set_chain_pllparameter_userdivider((uint8_t)(g_rt.config)->chain,'\0',user_divider);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x\n"
         ,"set_register_stage_3",(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
         (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  snprintf(tmp1,0x100,
           "Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x"
           ,(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
           (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  iVar1 = (g_rt.config)->chain;
  fVar2 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
  inc_freq_with_fix((uint8_t)iVar1,'\0',0x32,(uint)(0.0 < fVar2) * (int)fVar2,6.25,g_bringup_temp);
  inc_freq_with_matrix(matrix,(g_rt.config)->asics);
  set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0x7f);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set TM as 0x%08x\n","set_register_stage_3",0x7f);
  snprintf(tmp1,0x100,"Set TM as 0x%08x",0x7f);
  log_to_file(tmp1,time_stamp);
  uart_flush_rx((g_rt.config)->chain);
  dhash_set_timeout(((g_rt.config)->speed).timeout);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set timeout by using config value: %d\n","set_register_stage_3",
         ((g_rt.config)->speed).timeout);
  snprintf(tmp1,0x100,"Set timeout by using config value: %d",((g_rt.config)->speed).timeout);
  log_to_file(tmp1,time_stamp);
  return;
}

