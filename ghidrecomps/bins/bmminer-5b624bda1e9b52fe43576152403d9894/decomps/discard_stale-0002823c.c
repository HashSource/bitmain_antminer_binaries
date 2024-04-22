
/* WARNING: Unknown calling convention */

void discard_stale(void)

{
  _Bool _Var1;
  int iVar2;
  void *pvVar3;
  UT_hash_handle *pUVar4;
  int iVar5;
  int *piVar6;
  pthread_mutex_t *in_r2;
  work *in_r3;
  void *pvVar7;
  UT_hash_handle *pUVar8;
  work *pwVar9;
  work *tmp;
  int iVar10;
  void *pvVar11;
  int iVar12;
  UT_hash_handle *_hd_hh_del;
  int iVar13;
  uint uVar14;
  bool bVar15;
  work *work;
  char tmp42 [2048];
  
  iVar5 = DAT_000283c8;
  iVar2 = pthread_mutex_lock(*(pthread_mutex_t **)(DAT_000283c8 + 0x454));
  if (iVar2 != 0) {
    _mutex_lock(DAT_000283d0,(char *)0x149e,in_r2->__size,(int)in_r3);
  }
  work = *(work **)(iVar5 + 0x458);
  pwVar9 = work;
  if (work != (work *)0x0) {
    pwVar9 = (work *)(work->hh).next;
  }
  iVar2 = 0;
  if (work != (work *)0x0) {
    while( true ) {
      in_r3 = pwVar9;
      _Var1 = stale_work(work,false);
      if (_Var1) {
        pvVar3 = (work->hh).prev;
        pvVar11 = (work->hh).next;
        if ((pvVar3 == (void *)0x0) && (pvVar11 == (void *)0x0)) {
          free(**(void ***)(*(int *)(iVar5 + 0x458) + 0x158));
          free(*(void **)(*(int *)(iVar5 + 0x458) + 0x158));
          *(undefined4 *)(iVar5 + 0x458) = 0;
        }
        else {
          pvVar7 = *(void **)(iVar5 + 0x458);
          iVar10 = *(int *)((int)pvVar7 + 0x158);
          iVar13 = *(int *)(iVar10 + 0x14);
          pwVar9 = (work *)(*(int *)(iVar10 + 0x10) - iVar13);
          bVar15 = work == pwVar9;
          if (bVar15) {
            pwVar9 = (work *)((int)pvVar3 + iVar13);
          }
          if (bVar15) {
            *(work **)(iVar10 + 0x10) = pwVar9;
          }
          if (pvVar3 == (void *)0x0) {
            *(void **)(iVar5 + 0x458) = pvVar11;
            pvVar7 = pvVar11;
          }
          else {
            *(void **)((int)pvVar3 + iVar13 + 8) = pvVar11;
            pvVar11 = pvVar7;
            pvVar7 = (work->hh).next;
          }
          piVar6 = *(int **)((int)pvVar11 + 0x158);
          if (pvVar7 != (void *)0x0) {
            *(void **)((int)pvVar7 + piVar6[5] + 4) = pvVar3;
          }
          iVar10 = *piVar6;
          uVar14 = piVar6[1] - 1U & (work->hh).hashv;
          iVar12 = iVar10 + uVar14 * 0xc;
          iVar13 = *(int *)(iVar12 + 4);
          pUVar4 = (work->hh).hh_next;
          if ((UT_hash_handle *)*(undefined **)(iVar10 + uVar14 * 0xc) == &work->hh) {
            *(UT_hash_handle **)(iVar10 + uVar14 * 0xc) = pUVar4;
          }
          pUVar8 = (work->hh).hh_prev;
          *(int *)(iVar12 + 4) = iVar13 + -1;
          if (pUVar8 != (UT_hash_handle *)0x0) {
            pUVar8->hh_next = pUVar4;
            pUVar4 = (work->hh).hh_next;
          }
          if (pUVar4 != (UT_hash_handle *)0x0) {
            pUVar4->hh_prev = pUVar8;
          }
          piVar6[3] = piVar6[3] + -1;
        }
        iVar2 = iVar2 + 1;
        in_r2 = DAT_000283d0;
        _discard_work(&work,DAT_000283cc,DAT_000283d0->__size,0x14a5);
      }
      work = in_r3;
      if (in_r3 == (work *)0x0) break;
      pwVar9 = (work *)(in_r3->hh).next;
    }
  }
  pthread_cond_signal(DAT_000283d4);
  iVar5 = pthread_mutex_unlock(*(pthread_mutex_t **)(iVar5 + 0x454));
  if (iVar5 != 0) {
    _mutex_unlock_noyield(DAT_000283d0,(char *)0x14ab,in_r2->__size,(int)in_r3);
  }
  (**DAT_000283d8)();
  if (((iVar2 != 0) && (*DAT_000283dc != '\0')) &&
     ((*DAT_000283e0 != '\0' || ((*DAT_000283e4 != '\0' || (6 < *DAT_000283ec)))))) {
    snprintf(tmp42,0x800,DAT_000283e8,iVar2);
    _applog(7,tmp42,false);
  }
  return;
}

