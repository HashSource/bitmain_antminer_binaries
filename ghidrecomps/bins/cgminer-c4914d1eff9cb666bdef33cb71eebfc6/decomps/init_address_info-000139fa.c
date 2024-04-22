
/* WARNING: Unknown calling convention */

void init_address_info(void)

{
  uchar check_bit;
  
  dev->check_bit = '\0';
  dev->corenum = 0xd0;
  dev->addrInterval = '\x04';
  check_bit = dev->addrInterval + 0xff;
  while (check_bit != '\0') {
    check_bit = check_bit >> 1;
    dev->check_bit = dev->check_bit + '\x01';
  }
  return;
}

