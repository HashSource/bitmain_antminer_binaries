
int test_r4_40_cipher(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  
  if (r4_40_cipher == 0) {
    iVar1 = EVP_CIPHER_meth_new(5,1,5,&r4_cipher,in_r3);
    if ((((iVar1 == 0) || (iVar2 = EVP_CIPHER_meth_set_iv_length(iVar1,0), iVar2 == 0)) ||
        (iVar2 = EVP_CIPHER_meth_set_flags(iVar1,8), iVar2 == 0)) ||
       (((iVar2 = EVP_CIPHER_meth_set_init(iVar1,0x1bc9e5), iVar2 == 0 ||
         (iVar2 = EVP_CIPHER_meth_set_do_cipher(iVar1,0x1bc9c9), iVar2 == 0)) ||
        (iVar2 = EVP_CIPHER_meth_set_impl_ctx_size(iVar1,0x418), iVar2 == 0)))) {
      EVP_CIPHER_meth_free(iVar1);
      iVar1 = 0;
    }
    r4_40_cipher = iVar1;
    return iVar1;
  }
  return r4_40_cipher;
}

