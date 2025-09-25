
/* WARNING: Unknown calling convention */

int32_t get_mac(bitmain_mac_t *mac)

{
  int32_t iVar1;
  uint8_t *in_r1;
  
  if (mac != (bitmain_mac_t *)0x0) {
    iVar1 = get_eth_mac((int8_t *)mac,in_r1);
    return iVar1;
  }
  return -1;
}

