
void ssl3_free_digest_list(int param_1)

{
  int iVar1;
  
  BIO_free(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4));
  iVar1 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  EVP_MD_CTX_free(*(undefined4 *)(iVar1 + 0xd8));
  *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xd8) = 0;
  return;
}

