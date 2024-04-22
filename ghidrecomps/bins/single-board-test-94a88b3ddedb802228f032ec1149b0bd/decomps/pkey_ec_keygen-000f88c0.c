
int pkey_ec_keygen(int param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  int iVar1;
  EC_GROUP **ppEVar2;
  
  ppEVar2 = *(EC_GROUP ***)(param_1 + 0x14);
  if ((*(int *)(param_1 + 8) == 0) && (*ppEVar2 == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,199,0x8b,DAT_000f8928,0x1dc);
  }
  else {
    key = EC_KEY_new();
    if (key != (EC_KEY *)0x0) {
      EVP_PKEY_assign(param_2,0x198,key);
      if (*(EVP_PKEY **)(param_1 + 8) == (EVP_PKEY *)0x0) {
        iVar1 = EC_KEY_set_group(key,*ppEVar2);
      }
      else {
        iVar1 = EVP_PKEY_copy_parameters(param_2,*(EVP_PKEY **)(param_1 + 8));
      }
      if (iVar1 != 0) {
        iVar1 = EC_KEY_generate_key((EC_KEY *)(param_2->pkey).rsa);
        return iVar1;
      }
    }
  }
  return 0;
}

