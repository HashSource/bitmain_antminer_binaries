
uint check_reg_temp(uchar device,uint reg,uchar data,uchar write,uchar chip_addr,int chain)

{
  uint reg_local;
  uchar write_local;
  uchar data_local;
  uchar device_local;
  uint ret;
  int fail_time;
  
  fail_time = 0;
  if (write == '\0') {
    do {
      wait_iic_ok((uint)chip_addr,chain,false);
      read_temp(device,reg,data,'\0',chip_addr,chain);
      cgsleep_ms(1);
      ret = wait_iic_ok((uint)chip_addr,chain,true);
      cgsleep_ms(1);
      fail_time = fail_time + 1;
      if ((((ret & 0xff00) >> 8 == reg) && ((ret & 0xff) != 0xff)) && ((ret & 0xff) != 0x7f)) break;
    } while (fail_time < 2);
  }
  else {
    do {
      wait_iic_ok((uint)chip_addr,chain,false);
      read_temp(device,reg,data,write,chip_addr,chain);
      wait_iic_ok((uint)chip_addr,chain,true);
      cgsleep_ms(1);
      wait_iic_ok((uint)chip_addr,chain,false);
      read_temp(device,reg,'\0','\0',chip_addr,chain);
      ret = wait_iic_ok((uint)chip_addr,chain,true);
      cgsleep_ms(1);
      fail_time = fail_time + 1;
      if (((ret & 0xff00) >> 8 == reg) || ((ret & 0xff) == (uint)data)) break;
    } while (fail_time < 2);
  }
  if (fail_time == 2) {
    ret = 0;
  }
  return ret;
}

