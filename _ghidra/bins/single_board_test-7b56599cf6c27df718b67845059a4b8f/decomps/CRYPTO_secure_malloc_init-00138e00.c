
size_t CRYPTO_secure_malloc_init(uint param_1,uint param_2)

{
  int iVar1;
  size_t __len;
  void *ptr;
  uint uVar2;
  size_t sVar3;
  
  if ((secure_mem_initialized != 0) ||
     (sec_malloc_lock = CRYPTO_THREAD_lock_new(), sec_malloc_lock == 0)) {
    return 0;
  }
  memset(&sh,0,0x28);
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: size > 0","crypto/mem_sec.c",0x188);
  }
  if ((param_1 - 1 & param_1) != 0) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: (size & (size - 1)) == 0","crypto/mem_sec.c",0x189);
  }
  if ((int)param_2 < 1) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: minsize > 0","crypto/mem_sec.c",0x18a);
  }
  if ((param_2 - 1 & param_2) != 0) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: (minsize & (minsize - 1)) == 0","crypto/mem_sec.c",0x18b);
  }
  if ((int)param_2 < 8) {
    do {
      param_2 = param_2 * 2;
    } while ((int)param_2 < 8);
  }
  DAT_00a27fd0 = param_1;
  DAT_00a27fdc = param_2;
  iVar1 = __aeabi_uidiv(param_1,param_2);
  DAT_00a27fe8 = iVar1 << 1;
  if (DAT_00a27fe8 >> 3 == 0) {
    ptr = (void *)0x0;
  }
  else {
    uVar2 = DAT_00a27fe8;
    iVar1 = 0;
    do {
      DAT_00a27fd8 = iVar1;
      uVar2 = uVar2 >> 1;
      iVar1 = DAT_00a27fd8 + 1;
    } while (uVar2 != 0);
    DAT_00a27fd4 = (void *)CRYPTO_zalloc(DAT_00a27fd8 << 2,"crypto/mem_sec.c",0x1a0);
    if (DAT_00a27fd4 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: sh.freelist != NULL","crypto/mem_sec.c",0x1a1);
    }
    DAT_00a27fe0 = (void *)CRYPTO_zalloc(DAT_00a27fe8 >> 3,"crypto/mem_sec.c",0x1a5);
    if (DAT_00a27fe0 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: sh.bittable != NULL","crypto/mem_sec.c",0x1a6);
    }
    DAT_00a27fe4 = (void *)CRYPTO_zalloc(DAT_00a27fe8 >> 3,"crypto/mem_sec.c",0x1aa);
    if (DAT_00a27fe4 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: sh.bitmalloc != NULL","crypto/mem_sec.c",0x1ab);
    }
    __len = sysconf(0x1e);
    if ((int)__len < 1) {
      iVar1 = 0x2000;
      __len = 0x1000;
    }
    else {
      iVar1 = __len << 1;
    }
    DAT_00a27fc8 = iVar1 + DAT_00a27fd0;
    sh = mmap((void *)0x0,DAT_00a27fc8,3,0x22,-1,0);
    if (sh != (void *)0xffffffff) {
      DAT_00a27fcc = (void *)((int)sh + __len);
      sh_setbit(DAT_00a27fcc,0,DAT_00a27fe0);
      sh_add_to_list(DAT_00a27fd4,DAT_00a27fcc);
      iVar1 = mprotect(sh,__len,0);
      sVar3 = DAT_00a27fd0;
      if (iVar1 < 0) {
        sVar3 = 2;
      }
      if (iVar1 >= 0) {
        sVar3 = 1;
      }
      iVar1 = mprotect((void *)(((DAT_00a27fd0 - 1) + __len * 2 & -__len) + (int)sh),__len,0);
      if (iVar1 < 0) {
        sVar3 = 2;
      }
      iVar1 = mlock(DAT_00a27fcc,DAT_00a27fd0);
      if (iVar1 < 0) {
        sVar3 = 2;
      }
      iVar1 = madvise(DAT_00a27fcc,DAT_00a27fd0,0x10);
      if (iVar1 < 0) {
        sVar3 = 2;
      }
      secure_mem_initialized = 1;
      return sVar3;
    }
    sh = (void *)0xffffffff;
    ptr = DAT_00a27fd4;
  }
  CRYPTO_free(ptr);
  CRYPTO_free(DAT_00a27fe0);
  CRYPTO_free(DAT_00a27fe4);
  if ((sh != (void *)0xffffffff) && (DAT_00a27fc8 != 0)) {
    munmap(sh,DAT_00a27fc8);
  }
  memset(&sh,0,0x28);
  CRYPTO_THREAD_lock_free(sec_malloc_lock);
  sec_malloc_lock = 0;
  return 0;
}

