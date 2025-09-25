
int BIO_get_new_index(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = CRYPTO_THREAD_run_once(&bio_type_init,0x10aef1);
  iVar2 = bio_count_10333;
  if ((iVar3 != 0) && (do_bio_type_init_ossl_ret_ != 0)) {
    do {
      ExclusiveAccess(0x274238);
      bVar1 = (bool)hasExclusiveAccess(0x274238);
    } while (!bVar1);
    bio_count_10333 = bio_count_10333 + 1;
    return iVar2 + 1;
  }
  ERR_put_error(0x20,0x66,0x41,"crypto/bio/bio_meth.c",0x1c);
  return -1;
}

