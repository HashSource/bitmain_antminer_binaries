
int ECDSA_size(EC_KEY *eckey)

{
  EC_GROUP *pEVar1;
  int iVar2;
  uint uVar3;
  uchar local_24 [4];
  ASN1_INTEGER local_20;
  
  if (eckey == (EC_KEY *)0x0) {
    return 0;
  }
  pEVar1 = EC_KEY_get0_group(eckey);
  if ((pEVar1 != (EC_GROUP *)0x0) && (iVar2 = EC_GROUP_order_bits(), iVar2 != 0)) {
    local_20.length = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      local_20.length = iVar2 + 0xe;
    }
    local_20.data = local_24;
    local_20.length = local_20.length >> 3;
    local_20.type = 2;
    local_24[0] = 0xff;
    iVar2 = i2d_ASN1_INTEGER(&local_20,(uchar **)0x0);
    uVar3 = ASN1_object_size(1,iVar2 << 1,0x10);
    return uVar3 & ~((int)uVar3 >> 0x1f);
  }
  return 0;
}

