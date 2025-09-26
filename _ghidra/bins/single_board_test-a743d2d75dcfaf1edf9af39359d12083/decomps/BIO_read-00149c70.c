
int BIO_read(BIO *b,void *data,int len)

{
  long lVar1;
  ulong extraout_r3;
  ulong uVar2;
  _func_745 *p_Var3;
  
  if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
     (b->method->bread == (_func_738 *)0x0)) {
    ERR_put_error(0x20,0x6f,0x79,"bio_lib.c",0xc4);
    lVar1 = -2;
  }
  else {
    p_Var3 = b->callback;
    if ((p_Var3 == (_func_745 *)0x0) || (lVar1 = (*p_Var3)(b,2,(char *)data,len,0,1), 0 < lVar1)) {
      if (b->init == 0) {
        ERR_put_error(0x20,0x6f,0x78,"bio_lib.c",0xce);
        lVar1 = -2;
      }
      else {
        lVar1 = (*b->method->bread)(b,(char *)data,len);
        uVar2 = extraout_r3;
        if (0 < lVar1) {
          uVar2 = b->num_read + lVar1;
        }
        if (0 < lVar1) {
          b->num_read = uVar2;
        }
        if (p_Var3 != (_func_745 *)0x0) {
          lVar1 = (*p_Var3)(b,0x82,(char *)data,len,0,lVar1);
        }
      }
    }
  }
  return lVar1;
}

