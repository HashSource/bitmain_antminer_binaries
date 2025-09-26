
/* WARNING: Unknown calling convention */

int32_t get_uuid(bitmain_uuid_t *uuid)

{
  int32_t iVar1;
  uint8_t *in_r1;
  
  if (uuid != (bitmain_uuid_t *)0x0) {
    uuid->uuid[0] = '\0';
    uuid->uuid[1] = '\0';
    uuid->uuid[2] = '\0';
    uuid->uuid[3] = '\0';
    uuid->uuid[4] = '\0';
    uuid->uuid[5] = '\0';
    uuid->uuid[6] = '\0';
    uuid->uuid[7] = '\0';
    uuid->uuid[8] = '\0';
    uuid->uuid[9] = '\0';
    uuid->uuid[10] = '\0';
    uuid->uuid[0xb] = '\0';
    uuid->uuid[0xc] = '\0';
    uuid->uuid[0xd] = '\0';
    uuid->uuid[0xe] = '\0';
    uuid->uuid[0xf] = '\0';
    iVar1 = get_eth_mac((int8_t *)uuid,in_r1);
    return iVar1;
  }
  return -1;
}

