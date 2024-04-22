
/* WARNING: Unknown calling convention */

void switch_pools(pool *selected)

{
  pthread_rwlock_t *__rwlock;
  code **ppcVar1;
  int **ppiVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  pool *ppVar6;
  pool *pool;
  char *in_r2;
  int iVar7;
  int in_r3;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  code *line;
  int iVar11;
  pool *pool_00;
  pool *last_pool;
  int *piVar12;
  int pool_no;
  int next_pool;
  int *piVar13;
  char tmp42 [2048];
  
  iVar4 = pthread_mutex_lock(DAT_00021c18);
  if (iVar4 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00021c44,(char *)0x1417,in_r2,in_r3);
  }
  iVar4 = pthread_rwlock_wrlock(DAT_00021c1c);
  if (iVar4 != 0) {
    _wr_lock(DAT_00021c44,(char *)0x1417,in_r2,in_r3);
  }
  ppiVar2 = DAT_00021c48;
  iVar4 = DAT_00021c20;
  pool_00 = *(pool **)(DAT_00021c20 + 0x498);
  piVar12 = (int *)pool_00->pool_no;
  if ((selected == (pool *)0x0) || (iVar11 = selected->prio, iVar11 == 0)) {
    uVar9 = *(uint *)(DAT_00021c20 + 0x41c);
    piVar10 = DAT_00021c24;
  }
  else {
    iVar5 = *DAT_00021c24;
    if (0 < iVar5) {
      piVar8 = *DAT_00021c48;
      piVar10 = piVar8;
      while( true ) {
        iVar7 = *(int *)(*piVar10 + 4);
        in_r2 = (char *)(iVar7 + 1);
        if (iVar7 < iVar11) {
          *(char **)(*piVar10 + 4) = in_r2;
        }
        if (piVar10 + 1 == piVar8 + iVar5) break;
        iVar11 = selected->prio;
        piVar10 = piVar10 + 1;
      }
    }
    selected->prio = 0;
    uVar9 = *(uint *)(iVar4 + 0x41c);
    piVar10 = DAT_00021c24;
  }
  DAT_00021c24 = piVar10;
  if (uVar9 < 5) {
    in_r2 = (char *)0x1;
    uVar9 = 1 << (uVar9 & 0xff);
    if ((uVar9 & 0x19) == 0) {
      if ((uVar9 & 6) != 0) {
        if ((selected != (pool *)0x0) && (selected->idle == false)) {
          in_r2 = (char *)selected->pool_no;
          piVar10 = *ppiVar2;
          ppVar6 = (pool *)piVar10[(int)in_r2];
          goto LAB_00021ada;
        }
        iVar11 = *piVar10;
        if (1 < iVar11) {
          piVar13 = *ppiVar2;
          iVar5 = 1;
          piVar8 = piVar12;
          do {
            piVar8 = (int *)((int)piVar8 + 1);
            iVar5 = iVar5 + 1;
            piVar10 = (int *)((int)piVar8 * 4);
            if (iVar11 <= (int)piVar8) {
              piVar10 = (int *)0x0;
              piVar8 = piVar10;
            }
            ppVar6 = *(pool **)((int)piVar13 + (int)piVar10);
            _Var3 = pool_unusable(ppVar6);
            if (!_Var3) goto LAB_00021ada;
          } while (iVar5 != iVar11);
          ppVar6 = (pool *)piVar13[(int)piVar12];
          goto LAB_00021ada;
        }
      }
    }
    else if (0 < *piVar10) {
      iVar11 = 0;
      do {
        iVar5 = iVar11 + 1;
        ppVar6 = priority_pool(iVar11);
        _Var3 = pool_unusable(ppVar6);
        if (!_Var3) {
          in_r2 = (char *)ppVar6->pool_no;
          piVar10 = *ppiVar2;
          ppVar6 = (pool *)piVar10[(int)in_r2];
          goto LAB_00021ada;
        }
        iVar11 = iVar5;
      } while (iVar5 < *piVar10);
    }
  }
  piVar10 = *ppiVar2;
  ppVar6 = (pool *)piVar10[(int)piVar12];
LAB_00021ada:
  __rwlock = DAT_00021c1c;
  *(pool **)(iVar4 + 0x498) = ppVar6;
  iVar11 = pthread_rwlock_unlock(__rwlock);
  if (iVar11 != 0) {
    _rw_unlock(DAT_00021c44,(char *)0x1468,in_r2,(int)piVar10);
  }
  iVar11 = pthread_mutex_unlock(DAT_00021c18);
  if (iVar11 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00021c44,(char *)0x1468,in_r2,(int)piVar10);
  }
  ppcVar1 = DAT_00021c28;
  line = *DAT_00021c28;
  (*line)();
  if (((pool_00 != ppVar6) && (line = *(code **)(iVar4 + 0x41c), line != (code *)0x3)) &&
     (line != (code *)0x4)) {
    if (((*DAT_00021c2c != '\0') || (*DAT_00021c30 != '\0')) ||
       (line = *DAT_00021c34, 3 < (int)line)) {
      line = (code *)ppVar6->pool_no;
      snprintf(tmp42,0x800,DAT_00021c38,line,ppVar6->rpc_url);
      in_r2 = (char *)0x0;
      _applog(4,tmp42,false);
    }
    clear_pool_work(pool_00);
  }
  iVar4 = pthread_mutex_lock(DAT_00021c3c);
  if (iVar4 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00021c44,(char *)0x1470,in_r2,(int)line);
  }
  pthread_cond_broadcast(DAT_00021c40);
  iVar4 = pthread_mutex_unlock(DAT_00021c3c);
  if (iVar4 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00021c44,(char *)0x1472,in_r2,(int)line);
  }
  (**ppcVar1)();
  return;
}

