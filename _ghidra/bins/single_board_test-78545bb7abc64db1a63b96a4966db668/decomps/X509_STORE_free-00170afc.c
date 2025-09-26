
void X509_STORE_free(X509_STORE *v)

{
  bool bVar1;
  X509_LOOKUP *ctx;
  int iVar2;
  int *piVar3;
  int iVar4;
  stack_st_X509_LOOKUP *psVar5;
  
  if (v == (X509_STORE *)0x0) {
    return;
  }
  piVar3 = &v->references;
  do {
    ExclusiveAccess(piVar3);
    iVar4 = *piVar3;
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = iVar4 + -1;
  if (iVar4 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar4 + -1) {
    return;
  }
  psVar5 = v->get_cert_methods;
  iVar4 = 0;
  while( true ) {
    iVar2 = OPENSSL_sk_num(psVar5);
    if (iVar2 <= iVar4) break;
    ctx = (X509_LOOKUP *)OPENSSL_sk_value(psVar5,iVar4);
    X509_LOOKUP_shutdown(ctx);
    X509_LOOKUP_free(ctx);
    iVar4 = iVar4 + 1;
  }
  OPENSSL_sk_free();
  OPENSSL_sk_pop_free(v->objs,0x170831);
  CRYPTO_free_ex_data(4,v,(CRYPTO_EX_DATA *)&(v->ex_data).dummy);
  X509_VERIFY_PARAM_free(v->param);
  CRYPTO_THREAD_lock_free(v[1].cache);
  CRYPTO_free(v);
  return;
}

