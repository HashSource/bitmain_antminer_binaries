
int pkey_rsa_keygen(int param_1,EVP_PKEY *param_2)

{
  RSA *rsa;
  int iVar1;
  BIGNUM *a;
  BN_GENCB *cb;
  int *piVar2;
  BN_GENCB BStack_24;
  
  piVar2 = *(int **)(param_1 + 0x14);
  if (piVar2[1] == 0) {
    a = BN_new();
    piVar2[1] = (int)a;
    if (a == (BIGNUM *)0x0) {
      return 0;
    }
    iVar1 = BN_set_word(a,0x10001);
    if (iVar1 == 0) {
      return 0;
    }
  }
  rsa = RSA_new();
  if (rsa == (RSA *)0x0) {
    return 0;
  }
  cb = *(BN_GENCB **)(param_1 + 0x1c);
  if (cb != (BN_GENCB *)0x0) {
    evp_pkey_set_cb_translate(&BStack_24,param_1);
    cb = &BStack_24;
  }
  iVar1 = RSA_generate_key_ex(rsa,*piVar2,(BIGNUM *)piVar2[1],cb);
  if (iVar1 < 1) {
    RSA_free(rsa);
    return iVar1;
  }
  EVP_PKEY_assign(param_2,6,rsa);
  return iVar1;
}

