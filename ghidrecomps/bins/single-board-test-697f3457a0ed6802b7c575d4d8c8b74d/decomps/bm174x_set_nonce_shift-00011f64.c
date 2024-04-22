
void bm174x_set_nonce_shift(int fd,uint32_t nonce_shift,uint32_t *outer_shift)

{
  uint32_t *outer_shift_local;
  uint32_t nonce_shift_local;
  int fd_local;
  base_type_t item;
  bm174x_reg nonce_shift_reg;
  
  nonce_shift_reg.core_timeout.core_timeout._0_1_ = (undefined)reg_value.nonce_shift;
  nonce_shift_reg.core_timeout.core_timeout._1_3_ = (undefined3)(reg_value.nonce_shift >> 8);
  nonce_shift_reg.core_timeout.core_timeout._0_1_ =
       nonce_shift_reg.core_timeout.core_timeout._0_1_ & 0xe0 | (byte)nonce_shift & 0x1f;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = 'P';
  item.data = nonce_shift_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  *outer_shift = nonce_shift;
  return;
}

