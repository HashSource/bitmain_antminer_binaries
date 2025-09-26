
bool ssleay_rand_status(void)

{
  bool bVar1;
  int iVar2;
  CRYPTO_THREADID CStack_18;
  
  CRYPTO_THREADID_current(&CStack_18);
  if (crypto_lock_rand != 0) {
    CRYPTO_lock(5,0x13,"md_rand.c",0x22f);
    iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,&CStack_18);
    CRYPTO_lock(6,0x13,"md_rand.c",0x231);
    if (iVar2 == 0) {
      iVar2 = 1;
      goto LAB_0019f7a2;
    }
  }
  CRYPTO_lock(9,0x12,"md_rand.c",0x236);
  CRYPTO_lock(9,0x13,"md_rand.c",0x23b);
  CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&locking_threadid,&CStack_18);
  iVar2 = 0;
  CRYPTO_lock(10,0x13,"md_rand.c",0x23d);
  crypto_lock_rand = 1;
LAB_0019f7a2:
  if (initialized == 0) {
    RAND_poll();
    initialized = 1;
  }
  bVar1 = 32.0 <= entropy;
  if (iVar2 == 0) {
    crypto_lock_rand = iVar2;
    CRYPTO_lock(10,0x12,"md_rand.c",0x24c);
  }
  return bVar1;
}

