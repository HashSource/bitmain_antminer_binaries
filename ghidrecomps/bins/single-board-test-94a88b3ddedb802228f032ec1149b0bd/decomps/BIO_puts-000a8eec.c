
int BIO_puts(BIO *bp,char *buf)

{
  long lVar1;
  ulong extraout_r3;
  ulong uVar2;
  _func_745 *p_Var3;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->bputs == (_func_739 *)0x0)) {
    ERR_put_error(0x20,0x6e,0x79,"bio_lib.c",0x103);
    lVar1 = -2;
  }
  else {
    p_Var3 = bp->callback;
    if ((p_Var3 == (_func_745 *)0x0) || (lVar1 = (*p_Var3)(bp,4,buf,0,0,1), 0 < lVar1)) {
      if (bp->init == 0) {
        ERR_put_error(0x20,0x6e,0x78,"bio_lib.c",0x10d);
        lVar1 = -2;
      }
      else {
        lVar1 = (*bp->method->bputs)(bp,buf);
        uVar2 = extraout_r3;
        if (0 < lVar1) {
          uVar2 = bp->num_write + lVar1;
        }
        if (0 < lVar1) {
          bp->num_write = uVar2;
        }
        if (p_Var3 != (_func_745 *)0x0) {
          lVar1 = (*p_Var3)(bp,0x84,buf,0,0,lVar1);
        }
      }
    }
  }
  return lVar1;
}

