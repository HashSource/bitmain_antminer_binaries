
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int * CRYPTO_secure_malloc(uint param_1,char *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  uint local_38;
  
  if (secure_mem_initialized == 0) {
    piVar9 = (int *)CRYPTO_malloc(param_1,param_2,param_3);
    return piVar9;
  }
  CRYPTO_THREAD_write_lock(sec_malloc_lock);
  local_38 = DAT_00b25644;
  uVar13 = DAT_00b25650;
  uVar2 = DAT_00b2564c;
  if (param_1 <= DAT_00b25644) {
    for (; uVar2 = uVar2 - 1, uVar13 < param_1; uVar13 = uVar13 * 2) {
    }
    if (-1 < (int)uVar2) {
      piVar9 = DAT_00b25648 + uVar2;
      uVar13 = uVar2;
      do {
        piVar12 = (int *)*piVar9;
        if (piVar12 != (int *)0x0) {
          piVar7 = DAT_00b25648;
          if (uVar2 == uVar13) goto LAB_00135194;
          if ((int)DAT_00b2564c <= (int)uVar13) goto LAB_00135262;
          uVar14 = DAT_00b25644 >> (uVar13 & 0xff);
          uVar10 = (int)piVar12 - (int)DAT_00b25640;
          if ((uVar14 - 1 & uVar10) != 0) goto LAB_00135272;
          iVar3 = (int)piVar9 - (int)DAT_00b25648;
          iVar6 = (uVar13 + 1) * 4;
          goto LAB_00135136;
        }
        bVar17 = uVar13 != 0;
        uVar13 = uVar13 - 1;
        piVar12 = (int *)0x0;
        piVar7 = piVar12;
        piVar9 = piVar9 + -1;
      } while (bVar17);
      goto LAB_00134f1e;
    }
  }
  piVar12 = (int *)0x0;
  piVar7 = (int *)0x0;
LAB_00134f1e:
  secure_mem_used = (int)piVar7 + secure_mem_used;
  CRYPTO_THREAD_unlock(sec_malloc_lock);
  return piVar12;
LAB_00135194:
  iVar3 = DAT_00b25654;
  piVar12 = (int *)piVar7[uVar2];
  if ((int)DAT_00b2564c <= (int)uVar2) {
LAB_00135262:
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: list >= 0 && list < sh.freelist_size","crypto/mem_sec.c",0x13b);
  }
  if (((local_38 >> (uVar2 & 0xff)) - 1 & (int)piVar12 - (int)DAT_00b25640) == 0) {
    iVar6 = __aeabi_uidiv();
    uVar13 = (1 << (uVar2 & 0xff)) + iVar6;
    if ((uVar13 == 0) || (DAT_00b2565c <= uVar13)) {
LAB_00135252:
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: bit > 0 && bit < sh.bittable_size","crypto/mem_sec.c",0x13e);
    }
    if (((uint)*(byte *)(iVar3 + (uVar13 >> 3)) & 1 << (uVar13 & 7)) != 0) {
      sh_setbit(piVar12,uVar2,DAT_00b25658);
      iVar3 = *piVar12;
      if (iVar3 != 0) {
        *(int *)(iVar3 + 4) = piVar12[1];
      }
      *(int *)piVar12[1] = iVar3;
      if (((*piVar12 == 0) ||
          ((piVar9 = *(int **)(*piVar12 + 4), DAT_00b25648 <= piVar9 &&
           (piVar9 < DAT_00b25648 + DAT_00b2564c)))) ||
         ((DAT_00b25640 <= piVar9 && (piVar9 < (int *)(DAT_00b25644 + (int)DAT_00b25640))))) {
        if ((piVar12 < DAT_00b25640) || ((int *)((int)DAT_00b25640 + DAT_00b25644) <= piVar12)) {
                    /* WARNING: Subroutine does not return */
          OPENSSL_die("assertion failed: WITHIN_ARENA(chunk)","crypto/mem_sec.c",0x250);
        }
        *piVar12 = 0;
        piVar12[1] = 0;
        piVar7 = piVar12;
        if (piVar12 != (int *)0x0) {
          piVar7 = (int *)sh_actual_size(piVar12);
        }
        goto LAB_00134f1e;
      }
      sh_remove_from_list_part_1();
    }
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: sh_testbit(chunk, list, sh.bittable)","crypto/mem_sec.c",0x24c);
  }
  goto LAB_00135272;
  while( true ) {
    iVar5 = 1 << (uVar13 & 0xff);
    iVar3 = __aeabi_uidiv();
    uVar10 = iVar3 + iVar5;
    if ((uVar10 == 0) || (DAT_00b2565c <= uVar10)) goto LAB_00135252;
    if (((uint)*(byte *)(iVar11 + (uVar10 >> 3)) & 1 << (uVar10 & 7)) != 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: !sh_testbit(temp, slist, sh.bitmalloc)","crypto/mem_sec.c",
                  0x23b);
    }
    sh_setbit(piVar12,uVar13,DAT_00b25654);
    sh_add_to_list((int)DAT_00b25648 + iVar6,piVar12);
    iVar3 = DAT_00b25658;
    if (*(int **)((int)DAT_00b25648 + iVar6) != piVar12) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: sh.freelist[slist] == temp","crypto/mem_sec.c",0x23e);
    }
    uVar10 = DAT_00b25644 >> (uVar13 & 0xff);
    piVar12 = (int *)((int)piVar12 + uVar10);
    if ((int)DAT_00b2564c <= (int)uVar13) goto LAB_00135262;
    if ((uVar10 - 1 & (int)piVar12 - (int)DAT_00b25640) != 0) break;
    iVar11 = __aeabi_uidiv();
    uVar10 = iVar11 + iVar5;
    if ((uVar10 == 0) || (DAT_00b2565c <= uVar10)) goto LAB_00135252;
    if (((uint)*(byte *)(iVar3 + (uVar10 >> 3)) & 1 << (uVar10 & 7)) != 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: !sh_testbit(temp, slist, sh.bitmalloc)","crypto/mem_sec.c",
                  0x242);
    }
    sh_setbit(piVar12,uVar13,DAT_00b25654);
    sh_add_to_list((int)DAT_00b25648 + iVar6,piVar12);
    piVar7 = DAT_00b25648;
    piVar9 = DAT_00b25640;
    if (piVar12 != *(int **)((int)DAT_00b25648 + iVar6)) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: sh.freelist[slist] == temp","crypto/mem_sec.c",0x245);
    }
    local_38 = DAT_00b25644;
    uVar14 = DAT_00b25644 >> (uVar13 & 0xff);
    uVar10 = (int)piVar12 - (int)DAT_00b25640;
    iVar3 = __aeabi_uidiv(uVar10,uVar14);
    uVar4 = iVar3 + iVar5 ^ 1;
    uVar15 = (uint)(iVar3 + iVar5) >> 3;
    uVar16 = uVar4 & 7;
    bVar1 = *(byte *)(DAT_00b25654 + uVar15) >> uVar16;
    piVar8 = (int *)(bVar1 & 1);
    if ((bVar1 & 1) != 0) {
      if ((*(byte *)(DAT_00b25658 + uVar15) >> uVar16 & 1) == 0) {
        piVar8 = (int *)(uVar14 * (iVar5 - 1U & uVar4) + (int)piVar9);
      }
      else {
        piVar8 = (int *)0x0;
      }
    }
    if ((int *)((int)piVar12 - uVar14) != piVar8) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: temp-(sh.arena_size >> slist) == sh_find_my_buddy(temp, slist)"
                  ,"crypto/mem_sec.c",0x247);
    }
    if (uVar13 == uVar2) goto LAB_00135194;
    if ((int)DAT_00b2564c <= (int)uVar13) goto LAB_00135262;
    iVar3 = iVar6;
    iVar6 = iVar6 + 4;
    if ((uVar14 - 1 & uVar10) != 0) break;
LAB_00135136:
    iVar11 = DAT_00b25658;
    iVar5 = __aeabi_uidiv(uVar10,uVar14);
    uVar10 = (1 << (uVar13 & 0xff)) + iVar5;
    if ((uVar10 == 0) || (DAT_00b2565c <= uVar10)) goto LAB_00135252;
    if (((uint)*(byte *)(iVar11 + (uVar10 >> 3)) & 1 << (uVar10 & 7)) != 0) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: !sh_testbit(temp, slist, sh.bitmalloc)","crypto/mem_sec.c",
                  0x232);
    }
    sh_clearbit(piVar12,uVar13,DAT_00b25654);
    iVar11 = *piVar12;
    if (iVar11 != 0) {
      *(int *)(iVar11 + 4) = piVar12[1];
    }
    *(int *)piVar12[1] = iVar11;
    iVar11 = DAT_00b25658;
    if (((*piVar12 != 0) &&
        ((piVar9 = *(int **)(*piVar12 + 4), piVar9 < DAT_00b25648 ||
         (DAT_00b25648 + DAT_00b2564c <= piVar9)))) &&
       ((piVar9 < DAT_00b25640 || ((int *)(DAT_00b25644 + (int)DAT_00b25640) <= piVar9)))) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: WITHIN_FREELIST(temp2->p_next) || WITHIN_ARENA(temp2->p_next)",
                  "crypto/mem_sec.c",0x17a);
    }
    if (*(int **)((int)DAT_00b25648 + iVar3) == piVar12) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: temp != sh.freelist[slist]","crypto/mem_sec.c",0x235);
    }
    uVar13 = uVar13 + 1;
    if (((int)uVar13 < 0) || ((int)DAT_00b2564c <= (int)uVar13)) goto LAB_00135262;
    if (((DAT_00b25644 >> (uVar13 & 0xff)) - 1 & (int)piVar12 - (int)DAT_00b25640) != 0) break;
  }
LAB_00135272:
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: ((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0",
              "crypto/mem_sec.c",0x13c);
}

