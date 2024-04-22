
int erase_PIC16F1704_app_flash(uint which_i2c,uchar which_chain)

{
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uint pic_flash_length;
  uchar end_addr_l;
  uchar end_addr_h;
  uchar start_addr_l;
  uchar start_addr_h;
  uint erase_loop;
  uint i;
  
  set_PIC16F1704_flash_pointer(which_i2c,which_chain,'\x06','\0');
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: erase_loop = %d\n","erase_PIC16F1704_app_flash",0x4c);
    _applog(2,tmp42,false);
  }
  for (i = 0; i < 0x4c; i = i + 1) {
    erase_PIC16F1704_flash(which_i2c,which_chain);
  }
  return 1;
}

