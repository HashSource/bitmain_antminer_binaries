
/* WARNING: Unknown calling convention */

void scanfreq_read_temp(void)

{
  uint uVar1;
  int16_t iVar2;
  char tmp42 [2048];
  uint ret;
  int16_t temp2;
  int16_t temp1;
  int chain;
  
  temp1 = 0;
  temp2 = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      set_misc_control((uchar)chain,'\0','N',1);
      check_reg_temp(0x98,9,'\x04','\x01','N',chain);
      uVar1 = check_reg_temp(0x98,0,'\0','\0','N',chain);
      if (uVar1 == 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"chain %d read temp1 error\n",chain);
          _applog(5,tmp42,false);
        }
      }
      else {
        temp1 = get_local((ushort)uVar1 & 0xff);
      }
      set_misc_control((uchar)chain,'\0','<',1);
      check_reg_temp(0x98,9,'\x04','\x01','<',chain);
      uVar1 = check_reg_temp(0x98,0,'\0','\0','<',chain);
      if (uVar1 == 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"chain %d read temp2 error\n",chain);
          _applog(5,tmp42,false);
        }
      }
      else {
        temp2 = get_local((ushort)uVar1 & 0xff);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"chain %d temp1 = %d, temp2 = %d\n",chain,(int)temp1,(int)temp2);
        _applog(5,tmp42,false);
      }
      iVar2 = temp1;
      if (temp1 <= temp2) {
        iVar2 = temp2;
      }
      scanfreq_info.chain_max_pcb_temp[chain] = iVar2;
    }
  }
  return;
}

