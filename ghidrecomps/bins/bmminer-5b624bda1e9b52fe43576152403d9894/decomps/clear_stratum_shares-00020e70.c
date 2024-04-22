
/* WARNING: Unknown calling convention */

void clear_stratum_shares(pool *pool)

{
  double *pdVar1;
  uint *puVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  pthread_mutex_t *in_r2;
  pool *in_r3;
  int **ppiVar6;
  uint uVar7;
  void *__ptr;
  stratum_share *sshare;
  UT_hash_handle *_hd_hh_del;
  void *pvVar8;
  stratum_share *tmpshare;
  uint uVar9;
  int **ppiVar10;
  void **ppvVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  bool bVar16;
  double dVar17;
  double dVar18;
  char tmp42 [2048];
  
  iVar3 = pthread_mutex_lock(DAT_00021058);
  if (iVar3 != 0) {
    _mutex_lock(DAT_00021060,(char *)0x1c55,in_r2->__size,(int)in_r3);
  }
  iVar3 = DAT_00021080;
  __ptr = *(void **)(DAT_00021080 + 0x480);
  dVar18 = DAT_00021050;
  if (__ptr == (void *)0x0) {
    uVar9 = 0;
  }
  else {
    in_r2 = *(pthread_mutex_t **)((int)__ptr + 0x24);
    uVar9 = 0;
    pvVar8 = *(void **)((int)__ptr + 8);
    in_r3 = *(pool **)((int)in_r2 + 0x104);
    if (in_r3 == pool) goto LAB_00020ebc;
    while (__ptr = pvVar8, pvVar8 != (void *)0x0) {
      while( true ) {
        pvVar8 = *(void **)((int)__ptr + 8);
        in_r2 = *(pthread_mutex_t **)((int)__ptr + 0x24);
        in_r3 = *(pool **)((int)in_r2 + 0x104);
        if (in_r3 != pool) break;
LAB_00020ebc:
        iVar5 = *(int *)((int)__ptr + 4);
        ppiVar10 = *(int ***)((int)__ptr + 8);
        if ((iVar5 == 0) && (ppiVar10 == (int **)0x0)) {
          ppvVar11 = *(void ***)(iVar3 + 0x480);
                    /* WARNING: Load size is inaccurate */
          free(**ppvVar11);
          free(*ppvVar11);
          *(undefined4 *)(iVar3 + 0x480) = 0;
          in_r2 = *(pthread_mutex_t **)((int)__ptr + 0x24);
        }
        else {
          ppiVar6 = *(int ***)(iVar3 + 0x480);
          piVar14 = *ppiVar6;
          iVar12 = piVar14[5];
          pvVar4 = (void *)(piVar14[4] - iVar12);
          bVar16 = __ptr == pvVar4;
          if (bVar16) {
            pvVar4 = (void *)(iVar5 + iVar12);
          }
          if (bVar16) {
            piVar14[4] = (int)pvVar4;
          }
          if (iVar5 == 0) {
            *(int ***)(iVar3 + 0x480) = ppiVar10;
            ppiVar6 = ppiVar10;
          }
          else {
            *(int ***)(iVar12 + iVar5 + 8) = ppiVar10;
            ppiVar10 = ppiVar6;
            ppiVar6 = *(int ***)((int)__ptr + 8);
          }
          piVar14 = *ppiVar10;
          if (ppiVar6 != (int **)0x0) {
            *(int *)((int)ppiVar6 + piVar14[5] + 4) = iVar5;
          }
          iVar15 = *piVar14;
          uVar13 = piVar14[1] - 1U & *(uint *)((int)__ptr + 0x1c);
          iVar5 = iVar15 + uVar13 * 0xc;
          pvVar4 = *(void **)(iVar15 + uVar13 * 0xc);
          iVar12 = *(int *)((int)__ptr + 0x10);
          *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + -1;
          iVar5 = *(int *)((int)__ptr + 0xc);
          if (pvVar4 == __ptr) {
            *(int *)(iVar15 + uVar13 * 0xc) = iVar12;
          }
          if (iVar5 != 0) {
            *(int *)(iVar5 + 0x10) = iVar12;
            iVar12 = *(int *)((int)__ptr + 0x10);
          }
          if (iVar12 != 0) {
            *(int *)(iVar12 + 0xc) = iVar5;
          }
          piVar14[3] = piVar14[3] + -1;
        }
        uVar9 = uVar9 + 1;
        dVar18 = dVar18 + *(double *)((int)in_r2 + 0x178);
        in_r2 = DAT_00021060;
        _free_work((work **)((int)__ptr + 0x24),DAT_0002105c,DAT_00021060->__size,0x1c5d);
        in_r3 = (pool *)(pool->sshares + -1);
        pool->sshares = (int)in_r3;
        free(__ptr);
        __ptr = pvVar8;
        if (pvVar8 == (void *)0x0) goto LAB_00020f7a;
      }
    }
  }
LAB_00020f7a:
  iVar3 = pthread_mutex_unlock(DAT_00021058);
  if (iVar3 != 0) {
    _mutex_unlock_noyield(DAT_00021060,(char *)0x1c63,in_r2->__size,(int)in_r3);
  }
  (**DAT_00021064)();
  if (uVar9 != 0) {
    if (((*DAT_00021068 != '\0') || (*DAT_0002106c != '\0')) || (3 < *DAT_00021070)) {
      snprintf(tmp42,0x800,DAT_00021074,uVar9,pool->pool_no);
      _applog(4,tmp42,false);
    }
    puVar2 = DAT_0002107c;
    pdVar1 = DAT_00021078;
    dVar17 = *DAT_00021078;
    uVar13 = *DAT_0002107c;
    uVar7 = DAT_0002107c[1];
    pool->stale_shares = pool->stale_shares + uVar9;
    pool->diff_stale = pool->diff_stale + dVar18;
    *puVar2 = uVar13 + uVar9;
    puVar2[1] = uVar7 + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar13,uVar9);
    *pdVar1 = dVar17 + dVar18;
  }
  return;
}

