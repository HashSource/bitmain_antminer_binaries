
/* WARNING: Unknown calling convention */

int32_t mainboard_sensor_write(uint8_t reg_addr,uint8_t *buf,uint32_t len)

{
  int32_t iVar1;
  uint8_t *data;
  uint8_t *puVar2;
  uint8_t tmp_addr;
  char tmp42 [2048];
  
  if ((g_sensor_fd == 0) && (iVar1 = mainboard_sensor_open(), iVar1 != 0)) {
    len = 0xffffffff;
  }
  else {
    data = buf;
    if (len != 0) {
      do {
        puVar2 = data + 1;
        tmp_addr = reg_addr;
        iVar1 = iic_write_reg(g_sensor_fd,&tmp_addr,1,data,1,true);
        reg_addr = reg_addr + '\x01';
        if (iVar1 != 1) {
          snprintf(tmp42,0x800,"fail to write tsensor by iic, slave: %d, addr: %d",0x4c,
                   (uint)tmp_addr);
          _applog(0,tmp42,false);
          return -1;
        }
        data = puVar2;
      } while (puVar2 != buf + len);
    }
  }
  return len;
}

