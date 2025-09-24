
undefined4 ssl_free_wbio_buffer(int param_1)

{
  BIO *pBVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    pBVar1 = BIO_pop(*(BIO **)(param_1 + 0xc));
    *(BIO **)(param_1 + 0xc) = pBVar1;
    BIO_free(*(BIO **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 1;
  }
  return 1;
}

