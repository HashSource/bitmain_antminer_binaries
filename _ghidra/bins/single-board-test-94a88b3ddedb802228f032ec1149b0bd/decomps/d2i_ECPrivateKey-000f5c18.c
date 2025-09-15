
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  ASN1_VALUE *val;
  int iVar1;
  BIGNUM *pBVar2;
  EC_POINT *r;
  byte *buf;
  int line;
  int *piVar3;
  size_t len_00;
  EC_KEY *key_00;
  EC_KEY *pEVar4;
  size_t *psVar5;
  
  val = ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x3fd);
    return (EC_KEY *)0x0;
  }
  if (((key == (EC_KEY **)0x0) || (key_00 = *key, *key == (EC_KEY *)0x0)) &&
     (pEVar4 = EC_KEY_new(), key_00 = pEVar4, pEVar4 == (EC_KEY *)0x0)) {
    ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x403);
    goto LAB_000f5cb8;
  }
  iVar1 = *(int *)(val + 8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(key_00 + 4);
  }
  else {
    if (*(EC_GROUP **)(key_00 + 4) != (EC_GROUP *)0x0) {
      EC_GROUP_clear_free(*(EC_GROUP **)(key_00 + 4));
      iVar1 = *(int *)(val + 8);
    }
    iVar1 = ec_asn1_pkparameters2group(iVar1);
    *(int *)(key_00 + 4) = iVar1;
  }
  line = 0x410;
  if (iVar1 == 0) {
LAB_000f5cca:
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",line);
  }
  else {
    piVar3 = *(int **)(val + 4);
    *(undefined4 *)key_00 = *(undefined4 *)val;
    if (piVar3 == (int *)0x0) {
      ERR_put_error(0x10,0x92,0x7d,"ec_asn1.c",0x41f);
    }
    else {
      pBVar2 = BN_bin2bn((uchar *)piVar3[2],*piVar3,*(BIGNUM **)(key_00 + 0xc));
      *(BIGNUM **)(key_00 + 0xc) = pBVar2;
      if (pBVar2 != (BIGNUM *)0x0) {
        if (*(EC_POINT **)(key_00 + 8) != (EC_POINT *)0x0) {
          EC_POINT_clear_free(*(EC_POINT **)(key_00 + 8));
        }
        r = EC_POINT_new(*(EC_GROUP **)(key_00 + 4));
        line = 0x427;
        *(EC_POINT **)(key_00 + 8) = r;
        if (r != (EC_POINT *)0x0) {
          psVar5 = *(size_t **)(val + 0xc);
          if (psVar5 == (size_t *)0x0) {
            iVar1 = EC_POINT_mul(*(EC_GROUP **)(key_00 + 4),r,*(BIGNUM **)(key_00 + 0xc),
                                 (EC_POINT *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
            if (iVar1 != 0) {
              *(uint *)(key_00 + 0x10) = *(uint *)(key_00 + 0x10) | 2;
LAB_000f5cb4:
              pEVar4 = key_00;
              if (key != (EC_KEY **)0x0) {
                *key = key_00;
              }
              goto LAB_000f5cb8;
            }
            line = 0x442;
          }
          else {
            len_00 = *psVar5;
            buf = (byte *)psVar5[2];
            if ((int)len_00 < 1) {
              ERR_put_error(0x10,0x92,100,"ec_asn1.c",0x435);
              goto LAB_000f5cd8;
            }
            *(uint *)(key_00 + 0x14) = *buf & 0xfffffffe;
            iVar1 = EC_POINT_oct2point(*(EC_GROUP **)(key_00 + 4),r,buf,len_00,(BN_CTX *)0x0);
            line = 0x43c;
            if (iVar1 != 0) goto LAB_000f5cb4;
          }
        }
        goto LAB_000f5cca;
      }
      ERR_put_error(0x10,0x92,3,"ec_asn1.c",0x41b);
    }
  }
LAB_000f5cd8:
  if ((key == (EC_KEY **)0x0) || (key_00 != *key)) {
    pEVar4 = (EC_KEY *)0x0;
    EC_KEY_free(key_00);
  }
  else {
    pEVar4 = (EC_KEY *)0x0;
  }
LAB_000f5cb8:
  ASN1_item_free(val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  return pEVar4;
}

