
EC_POINT * EC_POINT_bn2point(EC_GROUP *param_1,BIGNUM *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  uchar *to;
  EC_POINT *p;
  int iVar2;
  size_t len;
  
  iVar1 = BN_num_bits(param_2);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  len = iVar2 >> 3;
  if ((len == 0) || (to = (uchar *)CRYPTO_malloc(len,DAT_00124908,0x5f), to == (uchar *)0x0)) {
    return (EC_POINT *)0x0;
  }
  p = (EC_POINT *)BN_bn2bin(param_2,to);
  if (p != (EC_POINT *)0x0) {
    if (param_3 == (EC_POINT *)0x0) {
      p = EC_POINT_new(param_1);
      if ((p != (EC_POINT *)0x0) &&
         (iVar2 = EC_POINT_oct2point(param_1,p,to,len,param_4), iVar2 == 0)) {
        EC_POINT_clear_free(p);
        goto LAB_001248fe;
      }
    }
    else {
      iVar2 = EC_POINT_oct2point(param_1,param_3,to,len,param_4);
      p = param_3;
      if (iVar2 == 0) {
LAB_001248fe:
        CRYPTO_free(to);
        return (EC_POINT *)0x0;
      }
    }
  }
  CRYPTO_free(to);
  return p;
}

