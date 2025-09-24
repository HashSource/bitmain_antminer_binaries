
BIO * BIO_dup_chain(BIO *in)

{
  BIO *a;
  long lVar1;
  BIO *a_00;
  int iVar2;
  int iVar3;
  _func_745 *p_Var4;
  int iVar5;
  BIO *b;
  
  if (in != (BIO *)0x0) {
    a_00 = (BIO *)0x0;
    b = (BIO *)0x0;
    while (a = BIO_new(in->method), a != (BIO *)0x0) {
      iVar2 = in->shutdown;
      iVar5 = in->init;
      iVar3 = in->flags;
      a->cb_arg = in->cb_arg;
      a->flags = iVar3;
      a->retry_reason = in->retry_reason;
      a->ptr = in->ptr;
      p_Var4 = in->callback;
      a->init = iVar5;
      a->callback = p_Var4;
      a->shutdown = iVar2;
      lVar1 = BIO_ctrl(in,0xc,0,a);
      if ((lVar1 == 0) ||
         (iVar2 = CRYPTO_dup_ex_data(0xc,(CRYPTO_EX_DATA *)&a[1].cb_arg,
                                     (CRYPTO_EX_DATA *)&in[1].cb_arg), iVar2 == 0)) {
        BIO_free(a);
        break;
      }
      if (a_00 == (BIO *)0x0) {
        in = in->prev_bio;
        a_00 = a;
      }
      else {
        BIO_push(b,a);
        in = in->prev_bio;
      }
      b = a;
      if (in == (bio_st *)0x0) {
        return a_00;
      }
    }
    BIO_free_all(a_00);
  }
  return (BIO *)0x0;
}

