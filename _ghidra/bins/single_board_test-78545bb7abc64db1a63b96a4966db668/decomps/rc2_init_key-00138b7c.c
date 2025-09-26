
undefined4 rc2_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int iVar1;
  int len;
  int *piVar2;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  len = EVP_CIPHER_CTX_key_length(param_1);
  piVar2 = (int *)EVP_CIPHER_CTX_get_cipher_data(param_1);
  RC2_set_key((RC2_KEY *)(iVar1 + 4),len,param_2,*piVar2);
  return 1;
}

