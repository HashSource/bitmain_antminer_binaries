
void BIO_free_all(BIO *a)

{
  int iVar1;
  long lVar2;
  _func_743 *p_Var3;
  int iVar4;
  bio_st *pbVar5;
  
  if (a != (BIO *)0x0) {
    do {
      iVar4 = a->references;
      pbVar5 = a->next_bio;
      iVar1 = CRYPTO_add_lock(&a->references,-1,0x15,DAT_000a9294,0x72);
      if ((iVar1 < 1) &&
         ((a->callback == (_func_745 *)0x0 ||
          (lVar2 = (*a->callback)(a,1,(char *)0x0,0,0,1), 0 < lVar2)))) {
        CRYPTO_free_ex_data(0,a,&a->ex_data);
        if ((a->method != (BIO_METHOD *)0x0) &&
           (p_Var3 = a->method->destroy, p_Var3 != (_func_743 *)0x0)) {
          (*p_Var3)(a);
        }
        CRYPTO_free(a);
      }
    } while ((iVar4 < 2) && (a = pbVar5, pbVar5 != (bio_st *)0x0));
  }
  return;
}

