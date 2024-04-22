
undefined4 eckey_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  EC_KEY *pEVar2;
  EC_POINT *pEVar3;
  EC_GROUP *group;
  EC_POINT *src;
  BIGNUM *n;
  uchar *local_30;
  void *local_2c;
  int local_28;
  long local_24;
  EC_KEY *local_20;
  X509_ALGOR *local_1c [2];
  
  local_30 = (uchar *)0x0;
  local_20 = (EC_KEY *)0x0;
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&local_30,&local_24,local_1c,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_28,&local_2c,local_1c[0]);
  local_20 = (EC_KEY *)eckey_type2param(local_28,local_2c);
  if (local_20 != (EC_KEY *)0x0) {
    pEVar2 = d2i_ECPrivateKey(&local_20,&local_30,local_24);
    if (pEVar2 == (EC_KEY *)0x0) {
      ERR_put_error(0x10,0xd5,0x8e,DAT_000f8070,0xfb);
      goto LAB_000f7ff0;
    }
    pEVar3 = EC_KEY_get0_public_key(local_20);
    if (pEVar3 != (EC_POINT *)0x0) {
LAB_000f7faa:
      EVP_PKEY_assign(param_1,0x198,local_20);
      return 1;
    }
    group = EC_KEY_get0_group(local_20);
    pEVar3 = EC_POINT_new(group);
    iVar1 = 0x10b;
    if (pEVar3 != (EC_POINT *)0x0) {
      src = EC_GROUP_get0_generator(group);
      iVar1 = EC_POINT_copy(pEVar3,src);
      if (iVar1 == 0) {
        EC_POINT_free(pEVar3);
        iVar1 = 0x110;
      }
      else {
        n = EC_KEY_get0_private_key(local_20);
        iVar1 = EC_POINT_mul(group,pEVar3,n,(EC_POINT *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
        if (iVar1 == 0) {
          EC_POINT_free(pEVar3);
          iVar1 = 0x116;
        }
        else {
          iVar1 = EC_KEY_set_public_key(local_20,pEVar3);
          if (iVar1 != 0) {
            EC_POINT_free(pEVar3);
            goto LAB_000f7faa;
          }
          EC_POINT_free(pEVar3);
          iVar1 = 0x11b;
        }
      }
    }
    ERR_put_error(0x10,0xd5,0x10,DAT_000f8070,iVar1);
  }
  ERR_put_error(0x10,0xd5,0x10,DAT_000f8070,0x125);
LAB_000f7ff0:
  if (local_20 != (EC_KEY *)0x0) {
    EC_KEY_free(local_20);
  }
  return 0;
}

