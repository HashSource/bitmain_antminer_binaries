
long BIO_callback_ctrl(BIO *b,int cmd,fp *fp)

{
  BIO *pBVar1;
  long lVar2;
  _func_744 *p_Var3;
  _func_745 *p_Var4;
  fp *local_1c [2];
  
  pBVar1 = b;
  if (b != (BIO *)0x0) {
    local_1c[0] = fp;
    if ((b->method == (BIO_METHOD *)0x0) ||
       (p_Var3 = b->method->callback_ctrl, p_Var3 == (_func_744 *)0x0)) {
      ERR_put_error(0x20,0x83,0x79,DAT_000a9148,0x179);
      pBVar1 = (BIO *)0xfffffffe;
    }
    else {
      p_Var4 = b->callback;
      if (p_Var4 == (_func_745 *)0x0) {
        pBVar1 = (BIO *)(*p_Var3)(b,cmd,fp);
      }
      else {
        pBVar1 = (BIO *)(*p_Var4)(b,6,(char *)local_1c,cmd,0,1);
        if (0 < (int)pBVar1) {
          lVar2 = (*b->method->callback_ctrl)(b,cmd,local_1c[0]);
          pBVar1 = (BIO *)(*p_Var4)(b,0x86,(char *)local_1c,cmd,0,lVar2);
        }
      }
    }
  }
  return (long)pBVar1;
}

