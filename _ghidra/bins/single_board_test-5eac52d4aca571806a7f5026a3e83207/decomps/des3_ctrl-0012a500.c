
undefined4 des3_ctrl(EVP_CIPHER_CTX *param_1,int param_2,undefined4 param_3,DES_cblock *param_4)

{
  int iVar1;
  
  if (param_2 != 6) {
    return 0xffffffff;
  }
  iVar1 = EVP_CIPHER_CTX_key_length(param_1);
  iVar1 = RAND_priv_bytes(param_4,iVar1);
  if (0 < iVar1) {
    DES_set_odd_parity(param_4);
    iVar1 = EVP_CIPHER_CTX_key_length(param_1);
    if (iVar1 < 0x10) {
      iVar1 = EVP_CIPHER_CTX_key_length(param_1);
    }
    else {
      DES_set_odd_parity(param_4 + 1);
      iVar1 = EVP_CIPHER_CTX_key_length(param_1);
    }
    if (iVar1 < 0x18) {
      return 1;
    }
    DES_set_odd_parity(param_4 + 2);
    return 1;
  }
  return 0;
}

