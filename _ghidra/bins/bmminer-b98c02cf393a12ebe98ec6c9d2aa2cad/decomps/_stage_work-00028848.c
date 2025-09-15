
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void _stage_work(int param_1)

{
  pthread_mutex_t *__mutex;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  char *__format;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  void *pvVar16;
  int iVar17;
  int iVar18;
  int local_840;
  void *local_83c;
  char acStack_828 [2052];
  
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_828,0x800,"Pushing work from pool %d to hash queue",
             **(undefined4 **)(param_1 + 0x104));
    _applog(7,acStack_828,0);
  }
  *(undefined4 *)(param_1 + 0x150) = work_block;
  test_work_current(param_1);
  __mutex = stgd_lock;
  *(int *)(*(int *)(param_1 + 0x104) + 0x44) = *(int *)(*(int *)(param_1 + 0x104) + 0x44) + 1;
  iVar1 = pthread_mutex_lock(__mutex);
  if (iVar1 == 0) {
    if ((*(char *)(param_1 + 0x111) == '\0') && (*(int *)(param_1 + 0x114) != 0)) {
      staged_rollable = staged_rollable + 1;
    }
    if (*(char *)(getq + 8) == '\0') {
      *(int *)(param_1 + 0x16c) = param_1 + 0x154;
      *(undefined4 *)(param_1 + 0x170) = 4;
      iVar1 = staged_work;
      uVar13 = *(byte *)(param_1 + 0x154) + 0x112410d + (uint)*(byte *)(param_1 + 0x157) * 0x1000000
               + (uint)*(byte *)(param_1 + 0x156) * 0x10000 +
               (uint)*(byte *)(param_1 + 0x155) * 0x100 ^ 0x7f76d;
      uVar8 = 0x9f49bac6 - uVar13 ^ uVar13 << 8;
      uVar6 = (-0x112410d - uVar13) - uVar8 ^ uVar8 >> 0xd;
      uVar13 = (uVar13 - uVar8) - uVar6 ^ uVar6 >> 0xc;
      uVar8 = (uVar8 - uVar6) - uVar13 ^ uVar13 << 0x10;
      uVar6 = (uVar6 - uVar13) - uVar8 ^ uVar8 >> 5;
      uVar13 = (uVar13 - uVar8) - uVar6 ^ uVar6 >> 3;
      uVar8 = (uVar8 - uVar6) - uVar13 ^ uVar13 << 10;
      uVar6 = (uVar6 - uVar13) - uVar8 ^ uVar8 >> 0xf;
      *(uint *)(param_1 + 0x174) = uVar6;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x160) = 0;
        *(undefined4 *)(param_1 + 0x15c) = 0;
        staged_work = param_1;
        puVar4 = (undefined4 *)calloc(0x2c,1);
        *(undefined4 **)(param_1 + 0x158) = puVar4;
        if (puVar4 == (undefined4 *)0x0) goto LAB_00028d0a;
        puVar4[1] = 0x20;
        puVar4[4] = param_1 + 0x158;
        puVar4[2] = 5;
        puVar4[5] = 0x158;
        pvVar16 = calloc(0x180,1);
        *puVar4 = pvVar16;
        if (pvVar16 == (void *)0x0) goto LAB_00028d0a;
        puVar4[10] = 0xa0111fe1;
        uVar8 = 0x1f;
        iVar1 = param_1;
      }
      else {
        uVar9 = *(undefined4 *)(iVar1 + 0x158);
        *(undefined4 *)(param_1 + 0x160) = 0;
        *(undefined4 *)(param_1 + 0x158) = uVar9;
        puVar4 = *(undefined4 **)(iVar1 + 0x158);
        iVar17 = puVar4[4];
        uVar8 = puVar4[1] - 1;
        pvVar16 = (void *)*puVar4;
        *(int *)(param_1 + 0x15c) = iVar17 - puVar4[5];
        *(int *)(iVar17 + 8) = param_1;
        puVar4[4] = param_1 + 0x158;
      }
      iVar17 = (uVar8 & uVar6) * 0xc;
      puVar4[3] = puVar4[3] + 1;
      piVar5 = (int *)((int)pvVar16 + iVar17);
      iVar10 = *(int *)((int)pvVar16 + iVar17);
      iVar17 = piVar5[1];
      piVar5[1] = iVar17 + 1U;
      *(int *)(param_1 + 0x168) = iVar10;
      *(undefined4 *)(param_1 + 0x164) = 0;
      if (iVar10 != 0) {
        *(int *)(iVar10 + 0xc) = param_1 + 0x158;
      }
      *piVar5 = param_1 + 0x158;
      if ((iVar17 + 1U < (uint)((piVar5[2] + 1) * 10)) ||
         (piVar5 = *(int **)(param_1 + 0x158), piVar5[9] == 1)) {
LAB_00028af4:
        iVar17 = *(int *)(iVar1 + 0x158);
        iVar1 = iVar1 + 0x158;
        local_840 = 1;
LAB_00028b04:
        iVar10 = 0;
        uVar6 = 0;
        iVar11 = iVar1;
        iVar1 = 0;
LAB_00028b0e:
        uVar6 = uVar6 + 1;
        iVar15 = local_840;
        if (local_840 == 0) {
          iVar7 = 0;
          iVar2 = iVar11;
        }
        else if (*(int *)(iVar11 + 8) == 0) {
          iVar7 = 1;
          iVar2 = 0;
        }
        else {
          iVar7 = 1;
          iVar2 = *(int *)(iVar11 + 8) + *(int *)(iVar17 + 0x14);
          if (iVar2 != 0) {
            while (iVar7 != local_840) {
              iVar2 = *(int *)(iVar2 + 8);
              iVar7 = iVar7 + 1;
              if ((iVar2 == 0) || (iVar2 = iVar2 + *(int *)(iVar17 + 0x14), iVar2 == 0)) break;
            }
          }
        }
        do {
          iVar3 = iVar10;
          iVar12 = iVar2;
          if (iVar7 != 0) goto LAB_00028b76;
LAB_00028b46:
          if (iVar15 == 0 || iVar2 == 0) {
            iVar11 = iVar2;
            if (iVar2 != 0) goto LAB_00028b0e;
            if (iVar10 != 0) {
              *(undefined4 *)(iVar10 + 8) = 0;
            }
            if ((1 < uVar6) && (local_840 = local_840 << 1, iVar10 = iVar1, iVar1 != 0))
            goto LAB_00028b04;
            *(int *)(iVar17 + 0x10) = iVar10;
            staged_work = iVar1 - *(int *)(iVar17 + 0x14);
            goto LAB_00028c46;
          }
          iVar3 = iVar10;
          iVar12 = iVar2;
          iVar18 = iVar7;
          if (*(int *)(iVar2 + 8) != 0) {
            iVar18 = *(int *)(iVar2 + 8) + *(int *)(iVar17 + 0x14);
          }
LAB_00028b5a:
          iVar2 = iVar18;
          iVar15 = iVar15 + -1;
          iVar10 = iVar11;
          iVar18 = iVar2;
          if (iVar3 == 0) goto LAB_00028be8;
LAB_00028b60:
          *(int *)(iVar3 + 8) = iVar12 - *(int *)(iVar17 + 0x14);
          iVar11 = iVar10;
          iVar2 = iVar18;
          while (iVar10 = iVar12, iVar10 != 0) {
            iVar3 = iVar3 - *(int *)(iVar17 + 0x14);
LAB_00028b70:
            *(int *)(iVar10 + 4) = iVar3;
            iVar3 = iVar10;
            iVar12 = iVar2;
            if (iVar7 == 0) goto LAB_00028b46;
LAB_00028b76:
            iVar10 = iVar11;
            iVar11 = iVar10;
            iVar2 = iVar12;
            if (iVar12 == 0 || iVar15 == 0) {
              if ((iVar10 != 0) && (iVar11 = *(int *)(iVar10 + 8), iVar11 != 0)) {
                iVar11 = iVar11 + *(int *)(iVar17 + 0x14);
              }
LAB_00028b8a:
              if (iVar3 != 0) goto LAB_00028b90;
LAB_00028c0c:
              iVar7 = iVar7 + -1;
              iVar12 = iVar10;
LAB_00028be8:
              iVar10 = iVar12;
              iVar3 = 0;
              iVar1 = iVar10;
              if (iVar10 == 0) break;
              goto LAB_00028b70;
            }
            iVar18 = *(int *)(iVar17 + 0x14);
            if (0 < *(int *)(iVar10 + -iVar18 + 0x108) - *(int *)(-iVar18 + iVar12 + 0x108)) {
              iVar18 = *(int *)(iVar12 + 8) + iVar18;
              if (*(int *)(iVar12 + 8) != 0) goto LAB_00028b5a;
              iVar15 = iVar15 + -1;
              iVar18 = 0;
              iVar2 = 0;
              if (iVar3 != 0) goto LAB_00028b60;
              goto LAB_00028be8;
            }
            if ((iVar10 == 0) || (iVar11 = *(int *)(iVar10 + 8), iVar11 == 0)) goto LAB_00028b8a;
            iVar11 = iVar11 + iVar18;
            if (iVar3 == 0) goto LAB_00028c0c;
LAB_00028b90:
            iVar7 = iVar7 + -1;
            if (iVar10 == 0) {
              *(undefined4 *)(iVar3 + 8) = 0;
              break;
            }
            *(int *)(iVar3 + 8) = iVar10 - *(int *)(iVar17 + 0x14);
            iVar12 = iVar10;
          }
        } while( true );
      }
      pvVar16 = calloc(piVar5[1] * 0x18,1);
      if (pvVar16 == (void *)0x0) {
LAB_00028d0a:
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      iVar1 = piVar5[1];
      piVar5[7] = 0;
      uVar8 = (uint)piVar5[3] >> (piVar5[2] + 1U & 0xff);
      uVar6 = iVar1 * 2 - 1;
      if ((piVar5[3] & uVar6) != 0) {
        uVar8 = uVar8 + 1;
      }
      piVar5[6] = uVar8;
      if (iVar1 == 0) {
        local_83c = (void *)*piVar5;
      }
      else {
        local_83c = (void *)*piVar5;
        local_840 = 0;
        do {
          iVar17 = *(int *)((int)local_83c + local_840);
          while (iVar17 != 0) {
            iVar10 = *(int *)(iVar17 + 0x10);
            uVar14 = uVar6 & *(uint *)(iVar17 + 0x1c);
            uVar13 = *(int *)((int)pvVar16 + uVar14 * 0xc + 4) + 1;
            *(uint *)((int)pvVar16 + uVar14 * 0xc + 4) = uVar13;
            if (uVar8 < uVar13) {
              piVar5[7] = piVar5[7] + 1;
              uVar9 = __udivsi3(uVar13,uVar8);
              *(undefined4 *)((int)pvVar16 + uVar14 * 0xc + 8) = uVar9;
            }
            iVar11 = *(int *)((int)pvVar16 + uVar14 * 0xc);
            *(undefined4 *)(iVar17 + 0xc) = 0;
            *(int *)(iVar17 + 0x10) = iVar11;
            if (iVar11 != 0) {
              *(int *)(iVar11 + 0xc) = iVar17;
            }
            *(int *)((int)pvVar16 + uVar14 * 0xc) = iVar17;
            iVar17 = iVar10;
          }
          local_840 = local_840 + 0xc;
        } while (local_840 != iVar1 * 0xc);
      }
      free(local_83c);
      puVar4 = *(undefined4 **)(param_1 + 0x158);
      *puVar4 = pvVar16;
      puVar4[2] = puVar4[2] + 1;
      puVar4[1] = puVar4[1] << 1;
      iVar1 = staged_work;
      if ((uint)puVar4[3] >> 1 < (uint)puVar4[7]) {
        uVar8 = puVar4[8] + 1;
        puVar4[8] = uVar8;
        uVar6 = uVar8;
        if (1 < uVar8) {
          uVar6 = 1;
        }
        if (1 < uVar8) {
          puVar4[9] = uVar6;
        }
      }
      else {
        puVar4[8] = 0;
      }
      if (iVar1 != 0) goto LAB_00028af4;
    }
LAB_00028c46:
    pthread_cond_broadcast((pthread_cond_t *)(getq + 0x28));
    iVar1 = pthread_mutex_unlock(stgd_lock);
    if (iVar1 == 0) {
      (*selective_yield)();
      return;
    }
    piVar5 = __errno_location();
    iVar1 = *piVar5;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar9 = 0x1651;
  }
  else {
    piVar5 = __errno_location();
    iVar1 = *piVar5;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar9 = 0x163f;
  }
  snprintf(acStack_828,0x800,__format,iVar1,"cgminer.c","hash_push",uVar9);
  _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

