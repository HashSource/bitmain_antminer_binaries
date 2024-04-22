
int pkey_dsa_keygen(int param_1,EVP_PKEY *param_2)

{
  DSA *key;
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    ERR_put_error(10,0x79,0x6b,DAT_000ff71c,0x10c);
  }
  else {
    key = DSA_new();
    if (key != (DSA *)0x0) {
      EVP_PKEY_assign(param_2,0x74,key);
      iVar1 = EVP_PKEY_copy_parameters(param_2,*(EVP_PKEY **)(param_1 + 8));
      if (iVar1 != 0) {
        iVar1 = DSA_generate_key((DSA *)(param_2->pkey).rsa);
        return iVar1;
      }
    }
  }
  return 0;
}

