
/* WARNING: Unknown calling convention */

int32_t get_uuid(bitmain_uuid_t *uuid)

{
  int32_t iVar1;
  uint8_t *mac;
  
  if (uuid != (bitmain_uuid_t *)0x0) {
    memset(uuid,0,0x10);
    iVar1 = get_eth_mac((int8_t *)uuid,mac);
    return iVar1;
  }
  return -1;
}

