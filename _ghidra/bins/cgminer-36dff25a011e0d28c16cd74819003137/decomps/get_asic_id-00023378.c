
uint32_t get_asic_id(nonce_format_t nonce)

{
  uint32_t uVar1;
  uchar uVar2;
  nonce_format_t nonce_local;
  int addr_interval;
  
  if (dev->addrInterval == '\0') {
    uVar2 = '\x04';
  }
  else {
    uVar2 = dev->addrInterval;
  }
  uVar1 = __aeabi_idiv((nonce.v << 10) >> 0x18,uVar2);
  return uVar1;
}

