
int pkey_ec_paramgen(int param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  int iVar1;
  EC_GROUP **ppEVar2;
  
  ppEVar2 = *(EC_GROUP ***)(param_1 + 0x14);
  if (*ppEVar2 == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0xdb,0x8b,DAT_000f88bc,0x1c9);
    iVar1 = 0;
  }
  else {
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = EC_KEY_set_group(key,*ppEVar2);
      if (iVar1 == 0) {
        EC_KEY_free(key);
      }
      else {
        EVP_PKEY_assign(param_2,0x198,key);
      }
    }
  }
  return iVar1;
}

