
BIO * BIO_new_mem_buf(void *buf,int len)

{
  BIO_METHOD *pBVar1;
  BIO *pBVar2;
  char *pcVar3;
  uint uVar4;
  _func_737 *p_Var5;
  _func_738 *p_Var6;
  _func_745 *p_Var7;
  
  if (buf == (void *)0x0) {
    ERR_put_error(0x20,0x7e,0x73,"crypto/bio/bss_mem.c",0x5e);
    pBVar2 = (BIO *)0x0;
  }
  else {
    if (len < 0) {
      len = strlen((char *)buf);
    }
    pBVar1 = BIO_s_mem();
    pBVar2 = BIO_new(pBVar1);
    if (pBVar2 != (BIO *)0x0) {
      uVar4 = pBVar2->retry_reason;
      pBVar1 = pBVar2->next_bio->method;
      p_Var7 = pBVar2->next_bio->callback;
      pBVar1->type = len;
      pBVar1->name = (char *)buf;
      pBVar1->bwrite = (_func_737 *)len;
      pcVar3 = pBVar1->name;
      p_Var5 = pBVar1->bwrite;
      p_Var6 = pBVar1->bread;
      *(int *)p_Var7 = pBVar1->type;
      *(char **)(p_Var7 + 4) = pcVar3;
      *(_func_737 **)(p_Var7 + 8) = p_Var5;
      *(_func_738 **)(p_Var7 + 0xc) = p_Var6;
      pBVar2->retry_reason = uVar4 | 0x200;
      pBVar2->ptr = (void *)0x0;
    }
  }
  return pBVar2;
}

