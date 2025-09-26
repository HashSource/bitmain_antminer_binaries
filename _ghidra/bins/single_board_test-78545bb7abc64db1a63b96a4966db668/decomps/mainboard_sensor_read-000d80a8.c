
/* WARNING: Unknown calling convention */

int32_t mainboard_sensor_read(uint8_t reg_addr,uint8_t *buf,uint32_t len)

{
  int32_t iVar1;
  uint32_t uVar2;
  byte local_819;
  char tmp42 [2048];
  
  local_819 = reg_addr;
  if ((g_sensor_fd == 0) && (iVar1 = mainboard_sensor_open(), iVar1 != 0)) {
    len = 0xffffffff;
  }
  else {
    uVar2 = iic_read_reg(g_sensor_fd,&local_819,2,buf,len,true);
    if (uVar2 != len) {
      snprintf(tmp42,0x800,"fail to read tsensor by iic, slave: %d, reg: %d\n",0x4c,(uint)local_819)
      ;
      _applog(0,tmp42,false);
      len = 0xffffffff;
    }
  }
  return len;
}

