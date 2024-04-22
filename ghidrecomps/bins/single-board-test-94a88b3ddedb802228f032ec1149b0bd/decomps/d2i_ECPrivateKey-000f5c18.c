
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  undefined4 *val;
  int iVar1;
  BIGNUM *pBVar2;
  EC_POINT *r;
  byte *buf;
  int line;
  int *piVar3;
  size_t len_00;
  undefined4 *key_00;
  undefined4 *puVar4;
  size_t *psVar5;
  
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,DAT_000f5d80);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x10,DAT_000f5d84,0x3fd);
    return (EC_KEY *)0x0;
  }
  if (((key == (EC_KEY **)0x0) ||
      (key_00 = (undefined4 *)*key, (undefined4 *)*key == (undefined4 *)0x0)) &&
     (puVar4 = (undefined4 *)EC_KEY_new(), key_00 = puVar4, puVar4 == (undefined4 *)0x0)) {
    ERR_put_error(0x10,0x92,0x41,DAT_000f5d84,0x403);
    goto LAB_000f5cb8;
  }
  iVar1 = val[2];
  if (iVar1 == 0) {
    iVar1 = key_00[1];
  }
  else {
    if ((EC_GROUP *)key_00[1] != (EC_GROUP *)0x0) {
      EC_GROUP_clear_free((EC_GROUP *)key_00[1]);
      iVar1 = val[2];
    }
    iVar1 = ec_asn1_pkparameters2group(iVar1);
    key_00[1] = iVar1;
  }
  line = 0x410;
  if (iVar1 == 0) {
LAB_000f5cca:
    ERR_put_error(0x10,0x92,0x10,DAT_000f5d84,line);
  }
  else {
    piVar3 = (int *)val[1];
    *key_00 = *val;
    if (piVar3 == (int *)0x0) {
      ERR_put_error(0x10,0x92,0x7d,DAT_000f5d84,0x41f);
    }
    else {
      pBVar2 = BN_bin2bn((uchar *)piVar3[2],*piVar3,(BIGNUM *)key_00[3]);
      key_00[3] = pBVar2;
      if (pBVar2 != (BIGNUM *)0x0) {
        if ((EC_POINT *)key_00[2] != (EC_POINT *)0x0) {
          EC_POINT_clear_free((EC_POINT *)key_00[2]);
        }
        r = EC_POINT_new((EC_GROUP *)key_00[1]);
        line = 0x427;
        key_00[2] = r;
        if (r != (EC_POINT *)0x0) {
          psVar5 = (size_t *)val[3];
          if (psVar5 == (size_t *)0x0) {
            iVar1 = EC_POINT_mul((EC_GROUP *)key_00[1],r,(BIGNUM *)key_00[3],(EC_POINT *)0x0,
                                 (BIGNUM *)0x0,(BN_CTX *)0x0);
            if (iVar1 != 0) {
              key_00[4] = key_00[4] | 2;
LAB_000f5cb4:
              puVar4 = key_00;
              if (key != (EC_KEY **)0x0) {
                *key = (EC_KEY *)key_00;
              }
              goto LAB_000f5cb8;
            }
            line = 0x442;
          }
          else {
            len_00 = *psVar5;
            buf = (byte *)psVar5[2];
            if ((int)len_00 < 1) {
              ERR_put_error(0x10,0x92,100,DAT_000f5d84,0x435);
              goto LAB_000f5cd8;
            }
            key_00[5] = *buf & 0xfffffffe;
            iVar1 = EC_POINT_oct2point((EC_GROUP *)key_00[1],r,buf,len_00,(BN_CTX *)0x0);
            line = 0x43c;
            if (iVar1 != 0) goto LAB_000f5cb4;
          }
        }
        goto LAB_000f5cca;
      }
      ERR_put_error(0x10,0x92,3,DAT_000f5d84,0x41b);
    }
  }
LAB_000f5cd8:
  if ((key == (EC_KEY **)0x0) || (key_00 != (undefined4 *)*key)) {
    puVar4 = (undefined4 *)0x0;
    EC_KEY_free((EC_KEY *)key_00);
  }
  else {
    puVar4 = (undefined4 *)0x0;
  }
LAB_000f5cb8:
  ASN1_item_free((ASN1_VALUE *)val,DAT_000f5d80);
  return (EC_KEY *)puVar4;
}

