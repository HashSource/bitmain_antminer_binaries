
void set_register_stage_3(float *matrix)

{
  uint32_t uVar1;
  int iVar2;
  float fVar3;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t user_divider;
  uint32_t Timeout_1;
  uint32_t Timeout;
  
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
  iVar2 = (g_rt.config)->chain;
  fVar3 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
  inc_freq_with_fix((uint8_t)iVar2,'\0',0x32,(uint)(0.0 < fVar3) * (int)fVar3,6.25,g_bringup_temp);
  inc_freq_with_matrix(matrix,(g_rt.config)->asics);
  if ((g_rt.config)->is_super == false) {
    set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0x7f);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set TM as 0x%08x\n","set_register_stage_3",0x7f);
    snprintf(tmp1,0x100,"Set TM as 0x%08x",0x7f);
    log_to_file(tmp1,time_stamp);
    uart_flush_rx((g_rt.config)->chain);
    fVar3 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
    uVar1 = __aeabi_uidiv(0x1ffff,(uint)(0.0 < fVar3) * (int)fVar3);
    dhash_set_timeout(uVar1);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set timeout by real freq: %d\n\n","set_register_stage_3",uVar1);
    snprintf(tmp1,0x100,"Set timeout by real freq: %d\n",uVar1);
    log_to_file(tmp1,time_stamp);
  }
  else {
    set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0xffffffff);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set TM as 0x%08x\n","set_register_stage_3",0xffffffff);
    snprintf(tmp1,0x100,"Set TM as 0x%08x",0xffffffff);
    log_to_file(tmp1,time_stamp);
    fVar3 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
    uVar1 = __aeabi_uidiv(0x1ffff,(uint)(0.0 < fVar3) * (int)fVar3);
    uart_flush_rx((g_rt.config)->chain);
    dhash_set_timeout(uVar1);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set timeout by using config value: %d\n\n","set_register_stage_3",uVar1);
    snprintf(tmp1,0x100,"Set timeout by using config value: %d\n",uVar1);
    log_to_file(tmp1,time_stamp);
    set_chain_chip_nonce_offset((uint8_t)(g_rt.config)->chain,true,0);
  }
  return;
}

