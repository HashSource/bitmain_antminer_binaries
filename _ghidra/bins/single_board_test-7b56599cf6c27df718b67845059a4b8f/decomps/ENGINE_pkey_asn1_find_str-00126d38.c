
EVP_PKEY_ASN1_METHOD * ENGINE_pkey_asn1_find_str(ENGINE **pe,char *str,int len)

{
  int iVar1;
  int iVar2;
  ENGINE *pEVar3;
  bool bVar4;
  ENGINE *local_28;
  EVP_PKEY_ASN1_METHOD *local_24;
  char *local_20;
  int local_1c;
  
  local_28 = (ENGINE *)0x0;
  local_24 = (EVP_PKEY_ASN1_METHOD *)0x0;
  local_20 = str;
  local_1c = len;
  iVar1 = CRYPTO_THREAD_run_once(&engine_lock_init,0x125c79);
  if ((iVar1 == 0) || (do_engine_lock_init_ossl_ret_ == 0)) {
    ERR_put_error(0x26,0xc5,0x41,"crypto/engine/tb_asnmth.c",0xc4);
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  engine_table_doall(pkey_asn1_meth_table,0x126af5,&local_28);
  if (local_28 != (ENGINE *)0x0) {
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    iVar1 = *(int *)(local_28 + 0x50);
    do {
      DataMemoryBarrier(0x1b);
      pEVar3 = local_28 + 0x50;
      do {
        ExclusiveAccess(pEVar3);
        iVar2 = *(int *)pEVar3;
        bVar4 = iVar2 == iVar1;
        if (!bVar4) goto LAB_00126db0;
        bVar4 = (bool)hasExclusiveAccess(pEVar3);
      } while (!bVar4);
      *(int *)pEVar3 = iVar1 + 1;
LAB_00126db0:
      DataMemoryBarrier(0x1b);
      iVar1 = iVar2;
    } while (!bVar4);
  }
  *pe = local_28;
  CRYPTO_THREAD_unlock(global_engine_lock);
  return local_24;
}

