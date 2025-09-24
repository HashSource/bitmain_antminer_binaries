
void sh_clearbit(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (((int)param_2 < 0) || (DAT_00a27fd8 <= (int)param_2)) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: list >= 0 && list < sh.freelist_size","crypto/mem_sec.c",0x146,
                param_2,param_4);
  }
  if (((DAT_00a27fd0 >> (param_2 & 0xff)) - 1 & param_1 - DAT_00a27fcc) != 0) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: ((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0",
                "crypto/mem_sec.c",0x147,param_2,param_4);
  }
  iVar1 = __aeabi_uidiv();
  uVar2 = (1 << (param_2 & 0xff)) + iVar1;
  if ((uVar2 != 0) && (uVar2 < DAT_00a27fe8)) {
    uVar3 = uVar2 >> 3;
    if ((int)((uint)(*(byte *)(param_3 + uVar3) >> (uVar2 & 7)) << 0x1f) < 0) {
      *(byte *)(param_3 + uVar3) = *(byte *)(param_3 + uVar3) & ~(byte)(1 << (uVar2 & 7));
      return;
    }
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: TESTBIT(table, bit)","crypto/mem_sec.c",0x14a,uVar3,param_4);
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: bit > 0 && bit < sh.bittable_size","crypto/mem_sec.c",0x149);
}

