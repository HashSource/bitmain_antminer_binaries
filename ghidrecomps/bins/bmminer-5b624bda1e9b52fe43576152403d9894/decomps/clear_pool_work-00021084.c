
/* WARNING: Unknown calling convention */

void clear_pool_work(pool *pool)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  UT_hash_handle *pUVar4;
  void *pvVar5;
  int *piVar6;
  char *in_r2;
  work *func;
  int in_r3;
  undefined *puVar7;
  UT_hash_handle *pUVar8;
  work *pwVar9;
  work *tmp;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  UT_hash_handle *_hd_hh_del;
  bool bVar14;
  work *work;
  char tmp42 [2048];
  
  iVar2 = DAT_0002121c;
  iVar1 = pthread_mutex_lock(*(pthread_mutex_t **)(DAT_0002121c + 0x454));
  if (iVar1 != 0) {
    _mutex_lock(DAT_00021238,(char *)0x1c74,in_r2,in_r3);
  }
  func = *(work **)(iVar2 + 0x458);
  pwVar9 = func;
  if (func != (work *)0x0) {
    pwVar9 = (work *)(func->hh).next;
  }
  iVar1 = 0;
  work = func;
  if (func != (work *)0x0) {
    while( true ) {
      func = pwVar9;
      if (work->pool == pool) {
        pvVar3 = (work->hh).prev;
        pvVar10 = (work->hh).next;
        if ((pvVar3 == (void *)0x0) && (pvVar10 == (void *)0x0)) {
          free(**(void ***)(*(int *)(iVar2 + 0x458) + 0x158));
          free(*(void **)(*(int *)(iVar2 + 0x458) + 0x158));
          *(undefined4 *)(iVar2 + 0x458) = 0;
        }
        else {
          pvVar5 = *(void **)(iVar2 + 0x458);
          iVar12 = *(int *)((int)pvVar5 + 0x158);
          pwVar9 = (work *)(*(int *)(iVar12 + 0x10) - *(int *)(iVar12 + 0x14));
          bVar14 = work == pwVar9;
          if (bVar14) {
            pwVar9 = (work *)((int)pvVar3 + *(int *)(iVar12 + 0x14));
          }
          if (bVar14) {
            *(work **)(iVar12 + 0x10) = pwVar9;
          }
          if (pvVar3 == (void *)0x0) {
            *(void **)(iVar2 + 0x458) = pvVar10;
            pvVar5 = pvVar10;
          }
          else {
            *(void **)((int)pvVar3 + *(int *)(*(int *)(*(int *)(iVar2 + 0x458) + 0x158) + 0x14) + 8)
                 = pvVar10;
            pvVar10 = pvVar5;
            pvVar5 = (work->hh).next;
          }
          piVar6 = *(int **)((int)pvVar10 + 0x158);
          if (pvVar5 != (void *)0x0) {
            *(void **)((int)pvVar5 + piVar6[5] + 4) = pvVar3;
          }
          iVar13 = *piVar6;
          uVar11 = piVar6[1] - 1U & (work->hh).hashv;
          iVar12 = iVar13 + uVar11 * 0xc;
          puVar7 = *(undefined **)(iVar13 + uVar11 * 0xc);
          pUVar8 = (work->hh).hh_next;
          *(int *)(iVar12 + 4) = *(int *)(iVar12 + 4) + -1;
          pUVar4 = (work->hh).hh_prev;
          if ((UT_hash_handle *)puVar7 == &work->hh) {
            *(UT_hash_handle **)(iVar13 + uVar11 * 0xc) = pUVar8;
          }
          if (pUVar4 != (UT_hash_handle *)0x0) {
            pUVar4->hh_next = pUVar8;
            pUVar8 = (work->hh).hh_next;
          }
          if (pUVar8 != (UT_hash_handle *)0x0) {
            pUVar8->hh_prev = pUVar4;
          }
          piVar6[3] = piVar6[3] + -1;
        }
        in_r3 = 0x1c7a;
        iVar1 = iVar1 + 1;
        _free_work(&work,DAT_00021234,DAT_00021238->__size,0x1c7a);
      }
      if (func == (work *)0x0) break;
      work = func;
      pwVar9 = (work *)(func->hh).next;
    }
  }
  work = func;
  iVar2 = pthread_mutex_unlock(*(pthread_mutex_t **)(iVar2 + 0x454));
  if (iVar2 != 0) {
    _mutex_unlock_noyield(DAT_00021238,(char *)0x1c7e,(char *)func,in_r3);
  }
  (**DAT_00021220)();
  if ((iVar1 != 0) && (((*DAT_00021224 != '\0' || (*DAT_00021228 != '\0')) || (5 < *DAT_0002122c))))
  {
    snprintf(tmp42,0x800,DAT_00021230,iVar1,pool->pool_no);
    _applog(6,tmp42,false);
  }
  return;
}

