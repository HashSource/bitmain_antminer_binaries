
undefined4 desx_cbc_init_key(undefined4 param_1,const_DES_cblock *param_2)

{
  DES_key_schedule *schedule;
  int iVar1;
  undefined4 uVar2;
  
  schedule = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data();
  DES_set_key_unchecked(param_2,schedule);
  iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  uVar2 = *(undefined4 *)(param_2[1] + 4);
  *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)param_2[1];
  *(undefined4 *)(iVar1 + 0x84) = uVar2;
  iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  uVar2 = *(undefined4 *)(param_2[2] + 4);
  *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)param_2[2];
  *(undefined4 *)(iVar1 + 0x8c) = uVar2;
  return 1;
}

