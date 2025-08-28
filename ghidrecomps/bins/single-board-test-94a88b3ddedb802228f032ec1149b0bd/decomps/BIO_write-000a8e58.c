
int BIO_write(BIO *b,void *data,int len)

{
  BIO *pBVar1;
  ulong extraout_r3;
  ulong uVar2;
  _func_745 *p_Var3;
  
  pBVar1 = b;
  if (b != (BIO *)0x0) {
    p_Var3 = b->callback;
    if ((b->method == (BIO_METHOD *)0x0) || (b->method->bwrite == (_func_737 *)0x0)) {
      ERR_put_error(0x20,0x71,0x79,"bio_lib.c",0xe6);
      pBVar1 = (BIO *)0xfffffffe;
    }
    else if ((p_Var3 == (_func_745 *)0x0) ||
            (pBVar1 = (BIO *)(*p_Var3)(b,3,(char *)data,len,0,1), 0 < (int)pBVar1)) {
      if (b->init == 0) {
        ERR_put_error(0x20,0x71,0x78,"bio_lib.c",0xef);
        pBVar1 = (BIO *)0xfffffffe;
      }
      else {
        pBVar1 = (BIO *)(*b->method->bwrite)(b,(char *)data,len);
        uVar2 = extraout_r3;
        if (0 < (int)pBVar1) {
          uVar2 = (int)&pBVar1->method + b->num_write;
        }
        if (0 < (int)pBVar1) {
          b->num_write = uVar2;
        }
        if (p_Var3 != (_func_745 *)0x0) {
          pBVar1 = (BIO *)(*p_Var3)(b,0x83,(char *)data,len,0,(long)pBVar1);
        }
      }
    }
  }
  return (int)pBVar1;
}

