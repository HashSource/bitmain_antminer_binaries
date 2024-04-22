
int BIO_free(BIO *a)

{
  int iVar1;
  BIO *pBVar2;
  _func_743 *p_Var3;
  
  pBVar2 = a;
  if (a != (BIO *)0x0) {
    iVar1 = CRYPTO_add_lock(&a->references,-1,0x15,DAT_000a8d24,0x72);
    if (iVar1 < 1) {
      if ((a->callback == (_func_745 *)0x0) ||
         (pBVar2 = (BIO *)(*a->callback)(a,1,(char *)0x0,0,0,1), 0 < (int)pBVar2)) {
        CRYPTO_free_ex_data(0,a,&a->ex_data);
        if ((a->method != (BIO_METHOD *)0x0) &&
           (p_Var3 = a->method->destroy, p_Var3 != (_func_743 *)0x0)) {
          (*p_Var3)(a);
        }
        CRYPTO_free(a);
        pBVar2 = (BIO *)0x1;
      }
    }
    else {
      pBVar2 = (BIO *)0x1;
    }
  }
  return (int)pBVar2;
}

