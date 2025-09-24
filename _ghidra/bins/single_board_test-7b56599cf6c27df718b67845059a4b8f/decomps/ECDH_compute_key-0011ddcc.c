
int ECDH_compute_key(void *out,size_t outlen,EC_POINT *pub_key,EC_KEY *ecdh,KDF *KDF)

{
  uint uVar1;
  void *pvVar2;
  uint local_1c;
  void *local_18;
  uint local_14;
  
  local_18 = (void *)0x0;
  local_1c = outlen;
  if (*(code **)(*(int *)ecdh + 0x24) == (code *)0x0) {
    ERR_put_error(0x10,0xf6,0x98,"crypto/ec/ec_kmeth.c",0x87);
    uVar1 = 0;
  }
  else {
    if ((int)outlen < 0) {
      ERR_put_error(0x10,0xf6,0xa1,"crypto/ec/ec_kmeth.c",0x8b);
      return 0;
    }
    uVar1 = (**(code **)(*(int *)ecdh + 0x24))(&local_18,&local_14);
    pvVar2 = local_18;
    if (uVar1 != 0) {
      if (KDF == (KDF *)0x0) {
        if (local_14 < local_1c) {
          local_1c = local_14;
        }
        memcpy(out,local_18,local_1c);
      }
      else {
        (*KDF)(local_18,local_14,out,&local_1c);
        pvVar2 = local_18;
      }
      CRYPTO_clear_free(pvVar2,local_14,"crypto/ec/ec_kmeth.c",0x97);
      uVar1 = local_1c;
    }
  }
  return uVar1;
}

