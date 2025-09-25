
void EC_KEY_free(EC_KEY *key)

{
  bool bVar1;
  EC_KEY *pEVar2;
  int iVar3;
  code *pcVar4;
  
  if (key == (EC_KEY *)0x0) {
    return;
  }
  pEVar2 = key + 0x20;
  do {
    ExclusiveAccess(pEVar2);
    iVar3 = *(int *)pEVar2;
    bVar1 = (bool)hasExclusiveAccess(pEVar2);
  } while (!bVar1);
  *(int *)pEVar2 = iVar3 + -1;
  if (iVar3 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar3 + -1) {
    return;
  }
  if ((*(int *)key != 0) && (pcVar4 = *(code **)(*(int *)key + 0xc), pcVar4 != (code *)0x0)) {
    (*pcVar4)();
  }
  ENGINE_finish(*(ENGINE **)(key + 4));
  if ((*(int **)(key + 0xc) != (int *)0x0) &&
     (pcVar4 = *(code **)(**(int **)(key + 0xc) + 0xc0), pcVar4 != (code *)0x0)) {
    (*pcVar4)(key);
  }
  CRYPTO_free_ex_data(8,key,(CRYPTO_EX_DATA *)(key + 0x28));
  CRYPTO_THREAD_lock_free(*(undefined4 *)(key + 0x2c));
  EC_GROUP_free(*(EC_GROUP **)(key + 0xc));
  EC_POINT_free(*(EC_POINT **)(key + 0x10));
  BN_clear_free(*(BIGNUM **)(key + 0x14));
  CRYPTO_clear_free(key,0x30,"crypto/ec/ec_key.c",0x47);
  return;
}

