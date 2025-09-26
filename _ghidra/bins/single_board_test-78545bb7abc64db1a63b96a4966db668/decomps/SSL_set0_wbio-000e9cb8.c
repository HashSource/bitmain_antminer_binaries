
void SSL_set0_wbio(int param_1,BIO *param_2)

{
  BIO *pBVar1;
  
  pBVar1 = *(BIO **)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x10) != 0) {
    pBVar1 = BIO_pop(pBVar1);
    *(BIO **)(param_1 + 0xc) = pBVar1;
  }
  BIO_free_all(pBVar1);
  *(BIO **)(param_1 + 0xc) = param_2;
  if (*(BIO **)(param_1 + 0x10) != (BIO *)0x0) {
    pBVar1 = BIO_push(*(BIO **)(param_1 + 0x10),param_2);
    *(BIO **)(param_1 + 0xc) = pBVar1;
  }
  return;
}

