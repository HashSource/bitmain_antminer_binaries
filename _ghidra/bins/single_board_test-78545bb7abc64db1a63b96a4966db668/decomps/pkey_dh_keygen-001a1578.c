
int pkey_dh_keygen(undefined4 *param_1,EVP_PKEY *param_2)

{
  DH *key;
  int iVar1;
  
  if (param_1[2] == 0) {
    if (*(int *)(param_1[5] + 0x1c) == 0) {
      ERR_put_error(5,0x71,0x6b,"crypto/dh/dh_pmeth.c",0x194);
      return 0;
    }
  }
  else if (*(int *)(param_1[5] + 0x1c) == 0) {
    key = DH_new();
    goto joined_r0x001a15bc;
  }
  key = (DH *)DH_new_by_nid();
joined_r0x001a15bc:
  if (key != (DH *)0x0) {
    EVP_PKEY_assign(param_2,*(int *)*param_1,key);
    if (((EVP_PKEY *)param_1[2] == (EVP_PKEY *)0x0) ||
       (iVar1 = EVP_PKEY_copy_parameters(param_2,(EVP_PKEY *)param_1[2]), iVar1 != 0)) {
      iVar1 = DH_generate_key((DH *)param_2->save_parameters);
      return iVar1;
    }
  }
  return 0;
}

