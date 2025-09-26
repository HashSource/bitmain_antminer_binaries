
void ssl_cert_free(void *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  piVar2 = (int *)((int)param_1 + 0x108);
  do {
    ExclusiveAccess(piVar2);
    iVar3 = *piVar2;
    bVar1 = (bool)hasExclusiveAccess(piVar2);
  } while (!bVar1);
  *piVar2 = iVar3 + -1;
  if (iVar3 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar3 + -1) {
    return;
  }
  EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 4));
  ssl_cert_clear_certs(param_1);
  CRYPTO_free(*(void **)((int)param_1 + 0xd0));
  CRYPTO_free(*(void **)((int)param_1 + 0xd8));
  CRYPTO_free(*(void **)((int)param_1 + 200));
  X509_STORE_free(*(X509_STORE **)((int)param_1 + 0xec));
  X509_STORE_free(*(X509_STORE **)((int)param_1 + 0xe8));
  custom_exts_free((int)param_1 + 0xf0);
  CRYPTO_free(*(void **)((int)param_1 + 0x104));
  CRYPTO_THREAD_lock_free(*(undefined4 *)((int)param_1 + 0x10c));
  CRYPTO_free(param_1);
  return;
}

