
int ECDSA_size(EC_KEY *eckey)

{
  EC_GROUP *group;
  BIGNUM *order;
  int iVar1;
  uchar local_24 [4];
  ASN1_INTEGER local_20;
  
  if (((eckey == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(eckey), group == (EC_GROUP *)0x0)) ||
     (order = BN_new(), order == (BIGNUM *)0x0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
    if (iVar1 != 0) {
      iVar1 = BN_num_bits(order);
      local_20.data = local_24;
      local_20.length = iVar1 + 7;
      if (iVar1 + 7 < 0) {
        local_20.length = iVar1 + 0xe;
      }
      local_20.length = local_20.length >> 3;
      local_20.type = 2;
      local_24[0] = 0xff;
      iVar1 = i2d_ASN1_INTEGER(&local_20,(uchar **)0x0);
      iVar1 = ASN1_object_size(1,iVar1 << 1,0x10);
    }
    BN_clear_free(order);
  }
  return iVar1;
}

