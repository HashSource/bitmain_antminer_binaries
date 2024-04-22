
BIO * BIO_new_mem_buf(void *buf,int len)

{
  BIO *pBVar1;
  uint uVar2;
  size_t *psVar3;
  
  if (buf == (void *)0x0) {
    ERR_put_error(0x20,0x7e,0x73,DAT_000a9804,0x65);
    pBVar1 = (BIO *)0x0;
  }
  else {
    if (len < 0) {
      len = strlen((char *)buf);
    }
    pBVar1 = BIO_new(DAT_000a9800);
    if (pBVar1 != (BIO *)0x0) {
      uVar2 = pBVar1->flags;
      psVar3 = (size_t *)pBVar1->ptr;
      *psVar3 = len;
      psVar3[1] = (size_t)buf;
      psVar3[2] = len;
      pBVar1->flags = uVar2 | 0x200;
      pBVar1->num = 0;
    }
  }
  return pBVar1;
}

