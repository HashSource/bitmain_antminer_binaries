
void ssl_free_wbio_buffer(int param_1)

{
  BIO *pBVar1;
  BIO *b;
  
  b = *(BIO **)(param_1 + 0x14);
  if (b != (BIO *)0x0) {
    if (b == *(BIO **)(param_1 + 0x10)) {
      pBVar1 = BIO_pop(b);
      b = *(BIO **)(param_1 + 0x14);
      *(BIO **)(param_1 + 0x10) = pBVar1;
    }
    BIO_free(b);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

