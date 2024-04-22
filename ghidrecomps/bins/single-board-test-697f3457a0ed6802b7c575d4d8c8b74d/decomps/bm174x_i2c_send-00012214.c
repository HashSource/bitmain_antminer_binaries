
void bm174x_i2c_send(int fd,uint8_t chip_addr,uint8_t i2c_dev_addr,uint8_t i2c_reg_addr,
                    uint8_t *reg_data,int len)

{
  uint8_t i2c_reg_addr_local;
  uint8_t i2c_dev_addr_local;
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  bm174x_reg i2c_reg;
  int i;
  
  for (i = 0; i < len; i = i + 1) {
    i2c_reg.core_timeout.core_timeout._3_1_ = (undefined)(reg_value.general_i2c_command >> 0x18);
    i2c_reg.reg_bin =
         CONCAT31(CONCAT21(CONCAT11(i2c_reg.core_timeout.core_timeout._3_1_,i2c_dev_addr << 1),
                           i2c_reg_addr),reg_data[i]) | 0x1010000;
    item.all = '\0';
    item.addr = ' ';
    item.data = i2c_reg.reg_bin;
    item.chip_addr = chip_addr;
    bm174x_ioctl(fd,1,&item);
  }
  return;
}

