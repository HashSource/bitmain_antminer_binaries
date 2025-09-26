
undefined4 rc2_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int len;
  void *pvVar1;
  
  pvVar1 = param_1->cipher_data;
  len = EVP_CIPHER_CTX_key_length(param_1);
                    /* WARNING: Load size is inaccurate */
  RC2_set_key((RC2_KEY *)((int)pvVar1 + 4),len,param_2,*param_1->cipher_data);
  return 1;
}

