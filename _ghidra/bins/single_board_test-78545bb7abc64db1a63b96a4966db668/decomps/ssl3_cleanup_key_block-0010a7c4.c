
void ssl3_cleanup_key_block(int param_1)

{
  int iVar1;
  
  CRYPTO_clear_free(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x22c),
                    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x228),"ssl/s3_enc.c",0x13b);
  iVar1 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar1 + 0x22c) = 0;
  *(undefined4 *)(iVar1 + 0x228) = 0;
  return;
}

