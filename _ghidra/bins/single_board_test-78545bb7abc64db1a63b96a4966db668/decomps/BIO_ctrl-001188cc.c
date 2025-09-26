
long BIO_ctrl(BIO *bp,int cmd,long larg,void *parg)

{
  int iVar1;
  long lVar2;
  _func_743 *p_Var3;
  code *pcVar4;
  
  if (bp == (BIO *)0x0) {
    return 0;
  }
  if ((bp->method == (BIO_METHOD *)0x0) ||
     (p_Var3 = bp->method->destroy, p_Var3 == (_func_743 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"crypto/bio/bio_lib.c",0x206);
    return -2;
  }
  pcVar4 = (code *)bp->cb_arg;
  if (bp->callback == (_func_745 *)0x0) {
    if (pcVar4 == (code *)0x0) goto LAB_0011893c;
LAB_0011891c:
    iVar1 = (*pcVar4)(bp,6,parg,0,cmd,larg,1,0);
  }
  else {
    if (pcVar4 != (code *)0x0) goto LAB_0011891c;
    iVar1 = (*bp->callback)(bp,6,(char *)parg,cmd,larg,1);
  }
  if (iVar1 < 1) {
    return iVar1;
  }
  p_Var3 = bp->method->destroy;
LAB_0011893c:
  iVar1 = (*p_Var3)(bp);
  pcVar4 = (code *)bp->cb_arg;
  if (bp->callback == (_func_745 *)0x0) {
    if (pcVar4 == (code *)0x0) {
      return iVar1;
    }
  }
  else if (pcVar4 == (code *)0x0) {
    lVar2 = (*bp->callback)(bp,0x86,(char *)parg,cmd,larg,iVar1);
    return lVar2;
  }
  lVar2 = (*pcVar4)(bp,0x86,parg,0,cmd,larg,iVar1,0);
  return lVar2;
}

