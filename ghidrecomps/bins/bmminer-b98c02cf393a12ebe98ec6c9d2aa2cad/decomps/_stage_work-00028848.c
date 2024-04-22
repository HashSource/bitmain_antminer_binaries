
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void _stage_work(int param_1)

{
  pthread_mutex_t *__mutex;
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void **ppvVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  char *__format;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  void *pvVar17;
  void *pvVar18;
  void *pvVar19;
  int iVar20;
  undefined4 uVar21;
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
  uVar11 = DAT_00028d70;
  if (iVar1 == 0) {
    if ((*(char *)(param_1 + 0x111) == '\0') && (*(int *)(param_1 + 0x114) != 0)) {
      staged_rollable = staged_rollable + 1;
    }
    if (*(char *)(getq + 8) == '\0') {
      *(int *)(param_1 + 0x16c) = param_1 + 0x154;
      *(undefined4 *)(param_1 + 0x170) = 4;
      iVar1 = staged_work;
      uVar15 = *(byte *)(param_1 + 0x154) + 0x112410d + (uint)*(byte *)(param_1 + 0x157) * 0x1000000
               + (uint)*(byte *)(param_1 + 0x156) * 0x10000 +
               (uint)*(byte *)(param_1 + 0x155) * 0x100 ^ 0x7f76d;
      uVar10 = 0x9f49bac6 - uVar15 ^ uVar15 << 8;
      uVar8 = (-0x112410d - uVar15) - uVar10 ^ uVar10 >> 0xd;
      uVar15 = (uVar15 - uVar10) - uVar8 ^ uVar8 >> 0xc;
      uVar10 = (uVar10 - uVar8) - uVar15 ^ uVar15 << 0x10;
      uVar8 = (uVar8 - uVar15) - uVar10 ^ uVar10 >> 5;
      uVar15 = (uVar15 - uVar10) - uVar8 ^ uVar8 >> 3;
      uVar10 = (uVar10 - uVar8) - uVar15 ^ uVar15 << 10;
      uVar8 = (uVar8 - uVar15) - uVar10 ^ uVar10 >> 0xf;
      *(uint *)(param_1 + 0x174) = uVar8;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x160) = 0;
        *(undefined4 *)(param_1 + 0x15c) = 0;
        staged_work = param_1;
        ppvVar6 = (void **)calloc(0x2c,1);
        *(void ***)(param_1 + 0x158) = ppvVar6;
        if (ppvVar6 == (void **)0x0) goto LAB_00028d0a;
        ppvVar6[1] = (void *)0x20;
        ppvVar6[4] = (void *)(param_1 + 0x158);
        ppvVar6[2] = (void *)0x5;
        ppvVar6[5] = (void *)0x158;
        pvVar17 = calloc(0x180,1);
        *ppvVar6 = pvVar17;
        if (pvVar17 == (void *)0x0) goto LAB_00028d0a;
        ppvVar6[10] = (void *)0xa0111fe1;
        uVar10 = 0x1f;
        iVar1 = param_1;
      }
      else {
        uVar11 = *(undefined4 *)(iVar1 + 0x158);
        *(undefined4 *)(param_1 + 0x160) = 0;
        *(undefined4 *)(param_1 + 0x158) = uVar11;
        ppvVar6 = *(void ***)(iVar1 + 0x158);
        pvVar18 = ppvVar6[4];
        uVar10 = (int)ppvVar6[1] - 1;
        pvVar17 = *ppvVar6;
        *(int *)(param_1 + 0x15c) = (int)pvVar18 - (int)ppvVar6[5];
        *(int *)((int)pvVar18 + 8) = param_1;
        ppvVar6[4] = (void *)(param_1 + 0x158);
      }
      iVar12 = (uVar10 & uVar8) * 0xc;
      ppvVar6[3] = (void *)((int)ppvVar6[3] + 1);
      piVar7 = (int *)((int)pvVar17 + iVar12);
      iVar13 = *(int *)((int)pvVar17 + iVar12);
      iVar12 = piVar7[1];
      piVar7[1] = iVar12 + 1U;
      *(int *)(param_1 + 0x168) = iVar13;
      *(undefined4 *)(param_1 + 0x164) = 0;
      if (iVar13 != 0) {
        *(int *)(iVar13 + 0xc) = param_1 + 0x158;
      }
      *piVar7 = param_1 + 0x158;
      if ((iVar12 + 1U < (uint)((piVar7[2] + 1) * 10)) ||
         (ppvVar6 = *(void ***)(param_1 + 0x158), ppvVar6[9] == (void *)0x1)) {
LAB_00028af4:
        iVar12 = *(int *)(iVar1 + 0x158);
        iVar1 = iVar1 + 0x158;
        local_840 = 1;
LAB_00028b04:
        iVar13 = 0;
        uVar8 = 0;
        iVar5 = iVar1;
        iVar1 = 0;
LAB_00028b0e:
        uVar8 = uVar8 + 1;
        iVar16 = local_840;
        if (local_840 == 0) {
          iVar9 = 0;
          iVar3 = iVar5;
        }
        else if (*(int *)(iVar5 + 8) == 0) {
          iVar9 = 1;
          iVar3 = 0;
        }
        else {
          iVar9 = 1;
          iVar3 = *(int *)(iVar5 + 8) + *(int *)(iVar12 + 0x14);
          if (iVar3 != 0) {
            while (iVar9 != local_840) {
              iVar3 = *(int *)(iVar3 + 8);
              iVar9 = iVar9 + 1;
              if ((iVar3 == 0) || (iVar3 = iVar3 + *(int *)(iVar12 + 0x14), iVar3 == 0)) break;
            }
          }
        }
        do {
          iVar4 = iVar13;
          iVar14 = iVar3;
          if (iVar9 != 0) goto LAB_00028b76;
LAB_00028b46:
          if (iVar16 == 0 || iVar3 == 0) {
            iVar5 = iVar3;
            if (iVar3 != 0) goto LAB_00028b0e;
            if (iVar13 != 0) {
              *(undefined4 *)(iVar13 + 8) = 0;
            }
            if ((1 < uVar8) && (local_840 = local_840 << 1, iVar13 = iVar1, iVar1 != 0))
            goto LAB_00028b04;
            *(int *)(iVar12 + 0x10) = iVar13;
            staged_work = iVar1 - *(int *)(iVar12 + 0x14);
            goto LAB_00028c46;
          }
          iVar4 = iVar13;
          iVar14 = iVar3;
          iVar3 = iVar9;
          if (*(int *)(iVar3 + 8) != 0) {
            iVar3 = *(int *)(iVar3 + 8) + *(int *)(iVar12 + 0x14);
          }
LAB_00028b5a:
          iVar16 = iVar16 + -1;
          iVar13 = iVar5;
          iVar20 = iVar3;
          if (iVar4 == 0) goto LAB_00028be8;
LAB_00028b60:
          *(int *)(iVar4 + 8) = iVar14 - *(int *)(iVar12 + 0x14);
          iVar5 = iVar13;
          iVar3 = iVar20;
          while (iVar13 = iVar14, iVar13 != 0) {
            iVar4 = iVar4 - *(int *)(iVar12 + 0x14);
LAB_00028b70:
            *(int *)(iVar13 + 4) = iVar4;
            iVar4 = iVar13;
            iVar14 = iVar3;
            if (iVar9 == 0) goto LAB_00028b46;
LAB_00028b76:
            iVar13 = iVar5;
            iVar5 = iVar13;
            iVar3 = iVar14;
            if (iVar14 == 0 || iVar16 == 0) {
              if ((iVar13 != 0) && (iVar5 = *(int *)(iVar13 + 8), iVar5 != 0)) {
                iVar5 = iVar5 + *(int *)(iVar12 + 0x14);
              }
LAB_00028b8a:
              if (iVar4 != 0) goto LAB_00028b90;
LAB_00028c0c:
              iVar9 = iVar9 + -1;
              iVar14 = iVar13;
LAB_00028be8:
              iVar13 = iVar14;
              iVar4 = 0;
              iVar1 = iVar13;
              if (iVar13 == 0) break;
              goto LAB_00028b70;
            }
            iVar20 = *(int *)(iVar12 + 0x14);
            if (0 < *(int *)(iVar13 + -iVar20 + 0x108) - *(int *)(-iVar20 + iVar14 + 0x108)) {
              iVar3 = *(int *)(iVar14 + 8) + iVar20;
              if (*(int *)(iVar14 + 8) != 0) goto LAB_00028b5a;
              iVar16 = iVar16 + -1;
              iVar20 = 0;
              iVar3 = 0;
              if (iVar4 != 0) goto LAB_00028b60;
              goto LAB_00028be8;
            }
            if ((iVar13 == 0) || (iVar5 = *(int *)(iVar13 + 8), iVar5 == 0)) goto LAB_00028b8a;
            iVar5 = iVar5 + iVar20;
            if (iVar4 == 0) goto LAB_00028c0c;
LAB_00028b90:
            iVar9 = iVar9 + -1;
            if (iVar13 == 0) {
              *(undefined4 *)(iVar4 + 8) = 0;
              break;
            }
            *(int *)(iVar4 + 8) = iVar13 - *(int *)(iVar12 + 0x14);
            iVar14 = iVar13;
          }
        } while( true );
      }
      pvVar17 = calloc((int)ppvVar6[1] * 0x18,1);
      if (pvVar17 == (void *)0x0) {
LAB_00028d0a:
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      pvVar18 = ppvVar6[1];
      ppvVar6[7] = (void *)0x0;
      pvVar19 = (void *)((uint)ppvVar6[3] >> ((int)ppvVar6[2] + 1U & 0xff));
      uVar8 = (int)pvVar18 * 2 - 1;
      if (((uint)ppvVar6[3] & uVar8) != 0) {
        pvVar19 = (void *)((int)pvVar19 + 1);
      }
      ppvVar6[6] = pvVar19;
      if (pvVar18 == (void *)0x0) {
        local_83c = *ppvVar6;
      }
      else {
        local_83c = *ppvVar6;
        local_840 = 0;
        do {
          iVar1 = *(int *)((int)local_83c + local_840);
          while (iVar1 != 0) {
            iVar12 = *(int *)(iVar1 + 0x10);
            uVar10 = uVar8 & *(uint *)(iVar1 + 0x1c);
            pvVar2 = (void *)(*(int *)((int)pvVar17 + uVar10 * 0xc + 4) + 1);
            *(void **)((int)pvVar17 + uVar10 * 0xc + 4) = pvVar2;
            if (pvVar19 < pvVar2) {
              ppvVar6[7] = (void *)((int)ppvVar6[7] + 1);
              uVar11 = __udivsi3(pvVar2,pvVar19);
              *(undefined4 *)((int)pvVar17 + uVar10 * 0xc + 8) = uVar11;
            }
            iVar13 = *(int *)((int)pvVar17 + uVar10 * 0xc);
            *(undefined4 *)(iVar1 + 0xc) = 0;
            *(int *)(iVar1 + 0x10) = iVar13;
            if (iVar13 != 0) {
              *(int *)(iVar13 + 0xc) = iVar1;
            }
            *(int *)((int)pvVar17 + uVar10 * 0xc) = iVar1;
            iVar1 = iVar12;
          }
          local_840 = local_840 + 0xc;
        } while (local_840 != (int)pvVar18 * 0xc);
      }
      free(local_83c);
      ppvVar6 = *(void ***)(param_1 + 0x158);
      *ppvVar6 = pvVar17;
      ppvVar6[2] = (void *)((int)ppvVar6[2] + 1);
      ppvVar6[1] = (void *)((int)ppvVar6[1] << 1);
      iVar1 = staged_work;
      if ((void *)((uint)ppvVar6[3] >> 1) < ppvVar6[7]) {
        pvVar18 = (void *)((int)ppvVar6[8] + 1);
        ppvVar6[8] = pvVar18;
        pvVar17 = pvVar18;
        if ((void *)0x1 < pvVar18) {
          pvVar17 = (void *)0x1;
        }
        if ((void *)0x1 < pvVar18) {
          ppvVar6[9] = pvVar17;
        }
      }
      else {
        ppvVar6[8] = (void *)0x0;
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
    piVar7 = __errno_location();
    iVar1 = *piVar7;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar21 = 0x1651;
    uVar11 = DAT_00028d70;
  }
  else {
    piVar7 = __errno_location();
    iVar1 = *piVar7;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar21 = 0x163f;
  }
  snprintf(acStack_828,0x800,__format,iVar1,"cgminer.c",uVar11,uVar21);
  _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

