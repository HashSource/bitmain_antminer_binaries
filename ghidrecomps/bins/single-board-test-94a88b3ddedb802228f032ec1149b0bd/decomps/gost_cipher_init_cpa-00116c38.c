
undefined4 gost_cipher_init_cpa(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  size_t sVar1;
  void *pvVar2;
  
  pvVar2 = param_1->cipher_data;
  gost_init((int)pvVar2 + 0xc,DAT_00116c94);
  *(undefined4 *)((int)pvVar2 + 8) = 1;
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  if (param_2 != 0) {
    gost_key((int)pvVar2 + 0xc,param_2);
  }
  if (param_3 != (void *)0x0) {
    sVar1 = EVP_CIPHER_CTX_iv_length(param_1);
    memcpy(param_1->oiv,param_3,sVar1);
  }
  sVar1 = EVP_CIPHER_CTX_iv_length(param_1);
  memcpy(param_1->iv,param_1->oiv,sVar1);
  return 1;
}

