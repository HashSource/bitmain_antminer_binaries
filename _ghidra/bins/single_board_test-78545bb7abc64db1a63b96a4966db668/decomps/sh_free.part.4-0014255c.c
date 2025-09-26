
void sh_free_part_4(int *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int local_40;
  
  iVar4 = DAT_021b88ec;
  uVar10 = DAT_021b88e4;
  uVar8 = DAT_021b88e0;
  uVar3 = __aeabi_uidiv((int)param_1 + (DAT_021b88e4 - DAT_021b88e0),DAT_021b88f0);
  iVar6 = DAT_021b88f4;
  uVar16 = iVar4 - 1;
  while ((uVar3 != 0 &&
         (-1 < (int)((uint)(*(byte *)(DAT_021b88f4 + (uVar3 >> 3)) >> (uVar3 & 7)) << 0x1f)))) {
    if ((int)(uVar3 << 0x1f) < 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: (bit & 1) == 0","crypto/mem_sec.c",0x130);
    }
    uVar3 = uVar3 >> 1;
    uVar16 = uVar16 - 1;
  }
  if ((int)uVar16 < iVar4 && -1 < (int)uVar16) {
    if (((uVar10 >> (uVar16 & 0xff)) - 1 & (int)param_1 - uVar8) != 0) {
LAB_001428be:
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0",
                  "crypto/mem_sec.c",0x13c);
    }
    iVar4 = __aeabi_uidiv();
    uVar3 = (1 << (uVar16 & 0xff)) + iVar4;
    if ((uVar3 == 0) || (DAT_021b88fc <= uVar3)) {
LAB_001428ae:
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: bit > 0 && bit < sh.bittable_size","crypto/mem_sec.c",0x13e);
    }
    if (((uint)*(byte *)(iVar6 + (uVar3 >> 3)) & 1 << (uVar3 & 7)) == 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: sh_testbit(ptr, list, sh.bittable)","crypto/mem_sec.c",0x264);
    }
    local_40 = uVar16 * 4;
    sh_clearbit(param_1,uVar16,DAT_021b88f8);
    sh_add_to_list(DAT_021b88e8 + local_40,param_1);
    while( true ) {
      uVar3 = DAT_021b88e0;
      local_40 = local_40 + -4;
      iVar12 = 1 << (uVar16 & 0xff);
      uVar14 = DAT_021b88e4 >> (uVar16 & 0xff);
      uVar10 = (int)param_1 - DAT_021b88e0;
      iVar7 = __aeabi_uidiv(uVar10,uVar14);
      iVar6 = DAT_021b88f8;
      iVar4 = DAT_021b88f4;
      uVar11 = iVar7 + iVar12;
      uVar8 = (uVar11 ^ 1) & 7;
      if ((-1 < (int)((uint)(*(byte *)(DAT_021b88f4 + (uVar11 >> 3)) >> uVar8) << 0x1f)) ||
         (bVar1 = *(byte *)(DAT_021b88f8 + (uVar11 >> 3)) >> uVar8, (bVar1 & 1) != 0)) {
        return;
      }
      iVar7 = uVar14 * ((uVar11 ^ 1) & iVar12 - 1U);
      piVar13 = (int *)(uVar3 + iVar7);
      if (piVar13 == (int *)0x0) {
        return;
      }
      iVar5 = __aeabi_uidiv(iVar7,uVar14);
      uVar8 = iVar5 + iVar12 ^ 1;
      uVar15 = (uint)(iVar5 + iVar12) >> 3;
      uVar17 = uVar8 & 7;
      bVar2 = *(byte *)(iVar4 + uVar15) >> uVar17;
      piVar9 = (int *)(bVar2 & 1);
      if (((bVar2 & 1) != 0) &&
         (piVar9 = (int *)(bVar1 & 1), (*(byte *)(iVar6 + uVar15) >> uVar17 & 1) == 0)) {
        piVar9 = (int *)(uVar14 * (iVar12 - 1U & uVar8) + uVar3);
      }
      if (param_1 != piVar9) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: ptr == sh_find_my_buddy(buddy, list)","crypto/mem_sec.c",
                    0x26a);
      }
      if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: ptr != NULL","crypto/mem_sec.c",0x26b);
      }
      if (((int)uVar16 < 0) || (DAT_021b88ec <= (int)uVar16)) break;
      if ((uVar14 - 1 & uVar10) != 0) goto LAB_001428be;
      if ((uVar11 == 0) || (DAT_021b88fc <= uVar11)) goto LAB_001428ae;
      if (((uint)*(byte *)(iVar6 + (uVar11 >> 3)) & 1 << (uVar11 & 7)) != 0) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: !sh_testbit(ptr, list, sh.bitmalloc)","crypto/mem_sec.c",
                    0x26c);
      }
      sh_clearbit(param_1,uVar16,iVar4);
      iVar4 = *param_1;
      if (iVar4 != 0) {
        *(int *)(iVar4 + 4) = param_1[1];
      }
      *(int *)param_1[1] = iVar4;
      iVar4 = DAT_021b88f8;
      if (((*param_1 != 0) &&
          ((uVar8 = *(uint *)(*param_1 + 4), uVar8 < DAT_021b88e8 ||
           (DAT_021b88e8 + DAT_021b88ec * 4 <= uVar8)))) &&
         ((uVar8 < DAT_021b88e0 || (DAT_021b88e4 + DAT_021b88e0 <= uVar8)))) {
LAB_001428ce:
        sh_remove_from_list_part_1();
LAB_001428d2:
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: !sh_testbit(ptr, list, sh.bitmalloc)","crypto/mem_sec.c",
                    0x26f);
      }
      if (DAT_021b88ec <= (int)uVar16) break;
      if (((DAT_021b88e4 >> (uVar16 & 0xff)) - 1 & (int)param_1 - DAT_021b88e0) != 0)
      goto LAB_001428be;
      iVar6 = __aeabi_uidiv();
      uVar8 = iVar6 + iVar12;
      if ((uVar8 == 0) || (DAT_021b88fc <= uVar8)) goto LAB_001428ae;
      if (((uint)*(byte *)(iVar4 + (uVar8 >> 3)) & 1 << (uVar8 & 7)) != 0) goto LAB_001428d2;
      sh_clearbit(piVar13,uVar16,DAT_021b88f4);
      iVar4 = *(int *)(uVar3 + iVar7);
      if (iVar4 != 0) {
        *(int *)(iVar4 + 4) = piVar13[1];
      }
      *(int *)piVar13[1] = iVar4;
      if (((*(int *)(uVar3 + iVar7) != 0) &&
          ((uVar3 = *(uint *)(*(int *)(uVar3 + iVar7) + 4), uVar3 < DAT_021b88e8 ||
           (DAT_021b88e8 + DAT_021b88ec * 4 <= uVar3)))) &&
         ((uVar3 < DAT_021b88e0 || (DAT_021b88e4 + DAT_021b88e0 <= uVar3)))) goto LAB_001428ce;
      uVar16 = uVar16 - 1;
      piVar9 = param_1;
      if (param_1 < piVar13) {
        piVar9 = piVar13;
      }
      if (param_1 <= piVar13) {
        piVar13 = param_1;
      }
      *piVar9 = 0;
      piVar9[1] = 0;
      iVar4 = DAT_021b88f8;
      if ((uVar16 == 0xffffffff) || (DAT_021b88ec <= (int)uVar16)) break;
      if (((DAT_021b88e4 >> (uVar16 & 0xff)) - 1 & (int)piVar13 - DAT_021b88e0) != 0)
      goto LAB_001428be;
      iVar6 = __aeabi_uidiv();
      uVar3 = (1 << (uVar16 & 0xff)) + iVar6;
      if ((uVar3 == 0) || (DAT_021b88fc <= uVar3)) goto LAB_001428ae;
      if (((uint)*(byte *)(iVar4 + (uVar3 >> 3)) & 1 << (uVar3 & 7)) != 0) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: !sh_testbit(ptr, list, sh.bitmalloc)","crypto/mem_sec.c",
                    0x27a);
      }
      sh_setbit(piVar13,uVar16,DAT_021b88f4);
      sh_add_to_list(DAT_021b88e8 + local_40,piVar13);
      param_1 = *(int **)(DAT_021b88e8 + local_40);
      if (param_1 != piVar13) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: sh.freelist[list] == ptr","crypto/mem_sec.c",0x27d);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: list >= 0 && list < sh.freelist_size","crypto/mem_sec.c",0x13b);
}

