
uint CRYPTO_secure_actual_size(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  CRYPTO_THREAD_write_lock(sec_malloc_lock);
  uVar2 = DAT_00a27fd8;
  uVar7 = DAT_00a27fd0;
  uVar6 = DAT_00a27fcc;
  if ((param_1 < DAT_00a27fcc) || (DAT_00a27fcc + DAT_00a27fd0 <= param_1)) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: WITHIN_ARENA(ptr)","crypto/mem_sec.c",0x285);
  }
  uVar4 = __aeabi_uidiv((param_1 + DAT_00a27fd0) - DAT_00a27fcc,DAT_00a27fdc);
  iVar3 = DAT_00a27fe0;
  uVar1 = uVar2;
  while ((uVar1 = uVar1 - 1, uVar4 != 0 &&
         (-1 < (int)((uint)(*(byte *)(DAT_00a27fe0 + (uVar4 >> 3)) >> (uVar4 & 7)) << 0x1f)))) {
    if ((int)(uVar4 << 0x1f) < 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: (bit & 1) == 0","crypto/mem_sec.c",0x130);
    }
    uVar4 = uVar4 >> 1;
  }
  if ((int)uVar1 < (int)uVar2 && -1 < (int)uVar1) {
    uVar7 = uVar7 >> (uVar1 & 0xff);
    if ((uVar7 - 1 & param_1 - uVar6) != 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0",
                  "crypto/mem_sec.c",0x13c);
    }
    iVar5 = __aeabi_uidiv(param_1 - uVar6,uVar7);
    uVar6 = (1 << (uVar1 & 0xff)) + iVar5;
    if ((uVar6 != 0) && (uVar6 < DAT_00a27fe8)) {
      if (((uint)*(byte *)(iVar3 + (uVar6 >> 3)) & 1 << (uVar6 & 7)) == 0) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: sh_testbit(ptr, list, sh.bittable)","crypto/mem_sec.c",0x289)
        ;
      }
      CRYPTO_THREAD_unlock(sec_malloc_lock);
      return uVar7;
    }
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: bit > 0 && bit < sh.bittable_size","crypto/mem_sec.c",0x13e);
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: list >= 0 && list < sh.freelist_size","crypto/mem_sec.c",0x13b);
}

