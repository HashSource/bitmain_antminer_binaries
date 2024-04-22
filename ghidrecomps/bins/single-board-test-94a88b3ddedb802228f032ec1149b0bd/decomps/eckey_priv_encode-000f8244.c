
int eckey_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  int iVar1;
  uint flags;
  uchar *penc;
  int iVar2;
  ASN1_OBJECT *aobj;
  EC_KEY *key;
  uchar *local_2c;
  int local_28;
  void *local_24 [2];
  
  key = *(EC_KEY **)(param_2 + 0x14);
  iVar1 = eckey_param2type(&local_28,local_24,key);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xd6,0x8e,DAT_000f8344,0x137);
    iVar1 = 0;
  }
  else {
    flags = EC_KEY_get_enc_flags(key);
    EC_KEY_set_enc_flags(key,flags | 1);
    iVar1 = i2d_ECPrivateKey(key,(uchar **)0x0);
    if (iVar1 == 0) {
      EC_KEY_set_enc_flags(key,flags);
      ERR_put_error(0x10,0xd6,0x10,DAT_000f8344,0x147);
      iVar1 = 0;
    }
    else {
      penc = (uchar *)CRYPTO_malloc(iVar1,DAT_000f8344,0x14a);
      if (penc == (uchar *)0x0) {
        EC_KEY_set_enc_flags(key,flags);
        ERR_put_error(0x10,0xd6,0x41,DAT_000f8344,0x14d);
        iVar1 = 0;
      }
      else {
        local_2c = penc;
        iVar2 = i2d_ECPrivateKey(key,&local_2c);
        if (iVar2 == 0) {
          EC_KEY_set_enc_flags(key,flags);
          CRYPTO_free(penc);
          ERR_put_error(0x10,0xd6,0x10,DAT_000f8344,0x154);
          iVar1 = 0;
        }
        else {
          EC_KEY_set_enc_flags(key,flags);
          aobj = OBJ_nid2obj(0x198);
          iVar1 = PKCS8_pkey_set0(param_1,aobj,0,local_28,local_24[0],penc,iVar1);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
        }
      }
    }
  }
  return iVar1;
}

