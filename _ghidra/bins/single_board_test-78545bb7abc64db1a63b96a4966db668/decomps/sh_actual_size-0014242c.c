
uint sh_actual_size(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = DAT_021b88ec;
  uVar6 = DAT_021b88e4;
  uVar4 = DAT_021b88e0;
  if ((param_1 < DAT_021b88e0) || (DAT_021b88e0 + DAT_021b88e4 <= param_1)) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: WITHIN_ARENA(ptr)","crypto/mem_sec.c",0x285);
  }
  uVar2 = __aeabi_uidiv((param_1 + DAT_021b88e4) - DAT_021b88e0,DAT_021b88f0);
  iVar1 = DAT_021b88f4;
  uVar5 = iVar3 - 1;
  while ((uVar2 != 0 &&
         (-1 < (int)((uint)(*(byte *)(DAT_021b88f4 + (uVar2 >> 3)) >> (uVar2 & 7)) << 0x1f)))) {
    if ((int)(uVar2 << 0x1f) < 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: (bit & 1) == 0","crypto/mem_sec.c",0x130);
    }
    uVar2 = uVar2 >> 1;
    uVar5 = uVar5 - 1;
  }
  if ((int)uVar5 < iVar3 && -1 < (int)uVar5) {
    uVar6 = uVar6 >> (uVar5 & 0xff);
    if ((uVar6 - 1 & param_1 - uVar4) != 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0",
                  "crypto/mem_sec.c",0x13c);
    }
    iVar3 = __aeabi_uidiv(param_1 - uVar4,uVar6);
    uVar4 = (1 << (uVar5 & 0xff)) + iVar3;
    if ((uVar4 != 0) && (uVar4 < DAT_021b88fc)) {
      if (((uint)*(byte *)(iVar1 + (uVar4 >> 3)) & 1 << (uVar4 & 7)) == 0) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: sh_testbit(ptr, list, sh.bittable)","crypto/mem_sec.c",0x289)
        ;
      }
      return uVar6;
    }
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: bit > 0 && bit < sh.bittable_size","crypto/mem_sec.c",0x13e);
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: list >= 0 && list < sh.freelist_size","crypto/mem_sec.c",0x13b);
}

