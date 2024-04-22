
BIO * BIO_dup_chain(BIO *in)

{
  BIO *pBVar1;
  BIO *a;
  int iVar2;
  long lVar3;
  _func_742 *p_Var4;
  char *pcVar5;
  _func_743 *p_Var6;
  int iVar7;
  bio_st *pbVar8;
  BIO *bp;
  BIO_METHOD *pBVar9;
  CRYPTO_EX_DATA *ad;
  bio_st *pbVar10;
  
  if (in != (BIO *)0x0) {
    bp = (BIO *)0x0;
    pbVar10 = (bio_st *)0x0;
    while( true ) {
      pBVar9 = in->method;
      a = (BIO *)CRYPTO_malloc(0x40,DAT_000a9428,0x46);
      if (a == (BIO *)0x0) {
        ERR_put_error(0x20,0x6c,0x41,DAT_000a9428,0x48);
        goto joined_r0x000a9388;
      }
      ad = &a->ex_data;
      a->method = pBVar9;
      a->callback = (_func_745 *)0x0;
      a->cb_arg = (char *)0x0;
      a->init = 0;
      a->shutdown = 1;
      a->flags = 0;
      a->retry_reason = 0;
      a->num = 0;
      a->ptr = (void *)0x0;
      a->prev_bio = (bio_st *)0x0;
      a->next_bio = (bio_st *)0x0;
      a->references = 1;
      a->num_read = 0;
      a->num_write = 0;
      CRYPTO_new_ex_data(0,a,ad);
      p_Var4 = pBVar9->create;
      if ((p_Var4 != (_func_742 *)0x0) && (iVar2 = (*p_Var4)(a), iVar2 == 0)) break;
      pcVar5 = in->cb_arg;
      a->callback = in->callback;
      iVar2 = in->init;
      a->cb_arg = pcVar5;
      a->init = iVar2;
      a->shutdown = in->shutdown;
      a->flags = in->flags;
      a->num = in->num;
      lVar3 = BIO_ctrl(in,0xc,0,a);
      if ((lVar3 == 0) || (iVar2 = CRYPTO_dup_ex_data(0,ad,&in->ex_data), iVar2 == 0)) {
        BIO_free(a);
        goto joined_r0x000a9388;
      }
      pbVar8 = a;
      if ((pbVar10 != (bio_st *)0x0) && (pBVar1 = bp, pbVar8 = pbVar10, bp != (BIO *)0x0)) {
        do {
          pbVar10 = pBVar1;
          pBVar1 = pbVar10->next_bio;
        } while (pbVar10->next_bio != (bio_st *)0x0);
        pbVar10->next_bio = a;
        a->prev_bio = pbVar10;
        BIO_ctrl(bp,6,0,pbVar10);
      }
      in = in->next_bio;
      bp = a;
      pbVar10 = pbVar8;
      if (in == (bio_st *)0x0) {
        return pbVar8;
      }
    }
    CRYPTO_free_ex_data(0,a,ad);
    CRYPTO_free(a);
joined_r0x000a9388:
    do {
      if (pbVar10 == (bio_st *)0x0) {
        return (BIO *)0x0;
      }
      iVar7 = pbVar10->references;
      pbVar8 = pbVar10->next_bio;
      iVar2 = CRYPTO_add_lock(&pbVar10->references,-1,0x15,DAT_000a9428,0x72);
      if ((iVar2 < 1) &&
         ((pbVar10->callback == (_func_745 *)0x0 ||
          (lVar3 = (*pbVar10->callback)(pbVar10,1,(char *)0x0,0,0,1), 0 < lVar3)))) {
        CRYPTO_free_ex_data(0,pbVar10,&pbVar10->ex_data);
        if ((pbVar10->method != (BIO_METHOD *)0x0) &&
           (p_Var6 = pbVar10->method->destroy, p_Var6 != (_func_743 *)0x0)) {
          (*p_Var6)(pbVar10);
        }
        CRYPTO_free(pbVar10);
      }
      pbVar10 = pbVar8;
    } while (iVar7 < 2);
  }
  return (BIO *)0x0;
}

