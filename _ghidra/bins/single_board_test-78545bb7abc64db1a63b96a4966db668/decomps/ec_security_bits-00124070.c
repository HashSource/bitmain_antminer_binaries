
int ec_security_bits(int param_1)

{
  int iVar1;
  
  EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x18));
  iVar1 = EC_GROUP_order_bits();
  if (0x1ff < iVar1) {
    return 0x100;
  }
  if (0x17f < iVar1) {
    return 0xc0;
  }
  if (0xff < iVar1) {
    return 0x80;
  }
  if (0xdf < iVar1) {
    return 0x70;
  }
  if (0x9f < iVar1) {
    return 0x50;
  }
  return iVar1 / 2;
}

