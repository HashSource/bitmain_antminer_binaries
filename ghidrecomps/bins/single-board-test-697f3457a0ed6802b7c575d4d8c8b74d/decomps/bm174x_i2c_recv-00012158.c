
int bm174x_i2c_recv(int fd,uint8_t chip_addr,uint8_t i2c_dev_addr,uint8_t i2c_reg_addr,int len)

{
  uint8_t i2c_reg_addr_local;
  uint8_t i2c_dev_addr_local;
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  bm174x_reg i2c_reg;
  int i;
  
  i2c_reg.core_timeout.core_timeout._0_2_ =
       CONCAT11(i2c_reg_addr,(undefined)(char)reg_value.general_i2c_command);
  i2c_reg.reg_bin =
       CONCAT22(CONCAT11((char)(reg_value.general_i2c_command >> 0x18),i2c_dev_addr << 1),
                i2c_reg.core_timeout.core_timeout._0_2_) | 0x1000000;
  item.all = '\0';
  item.addr = ' ';
  item.data = i2c_reg.reg_bin;
  item.chip_addr = chip_addr;
  bm174x_ioctl(fd,1,&item);
  usleep(200000);
  for (i = 0; i < len; i = i + 1) {
    item.all = '\0';
    item.addr = ' ';
    item.data = 0;
    item.chip_addr = chip_addr;
    bm174x_ioctl(fd,0,&item);
    usleep(1000000);
  }
  return 0;
}

