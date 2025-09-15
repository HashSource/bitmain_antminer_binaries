
uint8_t zynq_set_iic(uchar dev_addr,uchar which_iic,_Bool read,_Bool reg_addr_valid,uchar reg_addr,
                    uchar data)

{
  uchar uVar1;
  _Bool reg_addr_valid_local;
  _Bool read_local;
  uchar which_iic_local;
  uchar dev_addr_local;
  uint32_t value;
  
  value = 0;
  if (read) {
    value = 0x2000000;
  }
  if (reg_addr_valid) {
    value = value | (uint)reg_addr << 8 | 0x1000000;
  }
  uVar1 = set_iic((uint)data |
                  (dev_addr & 7) << 0x10 |
                  (dev_addr >> 3 & 0xf) << 0x14 | (which_iic & 3) << 0x1a | value);
  return uVar1;
}

