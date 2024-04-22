
undefined4 pkey_gost_init(EVP_PKEY_CTX *param_1)

{
  EVP_PKEY *pkey;
  int *__s;
  void *pvVar1;
  int iVar2;
  EC_KEY *key;
  EC_GROUP *group;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  __s = (int *)CRYPTO_malloc(0x10,DAT_000df5e8,0x1a);
  if (__s == (int *)0x0) {
    return 0;
  }
  memset(__s,0,0x10);
  if ((pkey != (EVP_PKEY *)0x0) && (pvVar1 = EVP_PKEY_get0(pkey), pvVar1 != (void *)0x0)) {
    iVar2 = EVP_PKEY_base_id(pkey);
    if (iVar2 == 0x32b) {
      key = (EC_KEY *)EVP_PKEY_get0(pkey);
      group = EC_KEY_get0_group(key);
      iVar2 = EC_GROUP_get_curve_name(group);
      *__s = iVar2;
    }
    else {
      if (iVar2 != 0x32c) {
        return 0;
      }
      EVP_PKEY_get0(pkey);
      iVar2 = gost94_nid_by_params();
      *__s = iVar2;
    }
  }
  EVP_PKEY_CTX_set_data(param_1,__s);
  return 1;
}

