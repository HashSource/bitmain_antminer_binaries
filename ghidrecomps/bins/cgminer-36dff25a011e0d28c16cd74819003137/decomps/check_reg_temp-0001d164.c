
uint8_t check_reg_temp(uint8_t reg,uint8_t data,uint8_t write,uint8_t chip_addr,int chain)

{
  uint8_t uVar1;
  uint8_t chip_addr_local;
  uint8_t write_local;
  uint8_t data_local;
  uint8_t reg_local;
  uint32_t ret;
  int fail_time;
  
  fail_time = 0;
  if (write == '\0') {
    do {
      wait_iic_ok((uint)chip_addr,chain,false);
      read_temp(0x98,(uint)reg,data,'\0',chip_addr,chain);
      cgsleep_ms(1);
      ret = wait_iic_ok((uint)chip_addr,chain,true);
      cgsleep_ms(1);
      fail_time = fail_time + 1;
      if ((ret >> 8 & 0xff) == (uint)reg) break;
    } while (fail_time < 2);
  }
  else {
    do {
      wait_iic_ok((uint)chip_addr,chain,false);
      read_temp(0x98,(uint)reg,data,write,chip_addr,chain);
      wait_iic_ok((uint)chip_addr,chain,true);
      cgsleep_ms(1);
      wait_iic_ok((uint)chip_addr,chain,false);
      read_temp(0x98,(uint)reg,'\0','\0',chip_addr,chain);
      ret = wait_iic_ok((uint)chip_addr,chain,true);
      cgsleep_ms(1);
      fail_time = fail_time + 1;
      if (((ret >> 8 & 0xff) == (uint)reg) || ((ret & 0xff) == (uint)data)) break;
    } while (fail_time < 2);
  }
  if (fail_time == 2) {
    uVar1 = '\0';
  }
  else {
    uVar1 = (uint8_t)ret;
  }
  return uVar1;
}

