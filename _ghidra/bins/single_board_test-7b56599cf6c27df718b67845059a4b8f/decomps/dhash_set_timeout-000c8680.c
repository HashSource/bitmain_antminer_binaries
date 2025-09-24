
void dhash_set_timeout(uint32_t timeout)

{
  uint uVar1;
  uint32_t tmp;
  
  uVar1 = 0x1ffff;
  if (timeout < 0x20000) {
    uVar1 = timeout;
  }
  fpga_write(0x14,uVar1 | 0x80000000);
  fpga_read(0x14,&tmp);
  return;
}

