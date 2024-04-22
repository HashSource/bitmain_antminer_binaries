
long BIO_ctrl(BIO *bp,int cmd,long larg,void *parg)

{
  BIO *pBVar1;
  long lVar2;
  _func_745 *p_Var3;
  _func_741 *p_Var4;
  
  pBVar1 = bp;
  if (bp != (BIO *)0x0) {
    if ((bp->method == (BIO_METHOD *)0x0) || (p_Var4 = bp->method->ctrl, p_Var4 == (_func_741 *)0x0)
       ) {
      ERR_put_error(0x20,0x67,0x79,DAT_000a90a8,0x15d);
      pBVar1 = (BIO *)0xfffffffe;
    }
    else {
      p_Var3 = bp->callback;
      if (p_Var3 == (_func_745 *)0x0) {
        pBVar1 = (BIO *)(*p_Var4)(bp,cmd,larg,parg);
      }
      else {
        pBVar1 = (BIO *)(*p_Var3)(bp,6,(char *)parg,cmd,larg,1);
        if (0 < (int)pBVar1) {
          lVar2 = (*bp->method->ctrl)(bp,cmd,larg,parg);
          pBVar1 = (BIO *)(*p_Var3)(bp,0x86,(char *)parg,cmd,larg,lVar2);
        }
      }
    }
  }
  return (long)pBVar1;
}

