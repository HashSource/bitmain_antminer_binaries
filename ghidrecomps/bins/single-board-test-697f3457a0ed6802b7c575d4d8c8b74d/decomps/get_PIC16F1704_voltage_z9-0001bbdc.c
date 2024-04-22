
void get_PIC16F1704_voltage_z9(uint32_t i2c,uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  uint32_t i2c_local;
  char tmp42 [1024];
  uint8_t read_vol [12];
  int ret;
  size_t i;
  
  for (i = 0; i < 4; i = i + 1) {
    read_vol[0] = '\0';
    read_vol[1] = '\0';
    read_vol[2] = '\0';
    read_vol[3] = '\0';
    read_vol[4] = '\0';
    read_vol[5] = '\0';
    read_vol[6] = '\0';
    read_vol[7] = '\0';
    read_vol[8] = '\0';
    read_vol[9] = '\0';
    read_vol[10] = '\0';
    read_vol[11] = '\0';
    iVar1 = PIC16F1704_i2c_forward_send(i2c,chain,"PQTU"[i],1,'!',2,read_vol);
    if (iVar1 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"read %02x vol success, 0x%02x%02x\n",(uint)"PQTU"[i],
                 read_vol._0_4_ & 0xff,(uint)read_vol[1]);
        _applog(2,tmp42,false);
      }
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"read %02x vol failed, 0x%02x%02x\n",(uint)"PQTU"[i],
               read_vol._0_4_ & 0xff,(uint)read_vol[1]);
      _applog(2,tmp42,false);
    }
  }
  return;
}

