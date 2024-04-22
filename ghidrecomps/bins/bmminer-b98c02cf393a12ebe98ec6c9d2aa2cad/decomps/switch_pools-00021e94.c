
void switch_pools(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *__format;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  char acStack_820 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_wrlock(DAT_000221b4);
    piVar3 = currentpool;
    uVar11 = DAT_000221c0;
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      __format = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar8 = 0x142e;
      goto LAB_000220de;
    }
    iVar1 = *currentpool;
    if (param_1 == (int *)0x0) {
      switch(pool_strategy) {
      case 0:
      case 3:
      case 4:
        goto switchD_00021f1e_caseD_0;
      case 1:
      case 2:
LAB_00022016:
        piVar9 = pools;
        iVar2 = total_pools;
        if (total_pools < 2) goto switchD_00021f1e_caseD_5;
        iVar4 = 1;
        iVar5 = iVar1;
        do {
          iVar5 = iVar5 + 1;
          if (iVar5 < iVar2) {
            iVar6 = iVar5 * 4;
          }
          else {
            iVar6 = 0;
            iVar5 = iVar6;
          }
          piVar7 = *(int **)((int)piVar9 + iVar6);
          if ((*(char *)((int)piVar7 + 0x61) == '\0') && (piVar7[0x19] == 1)) {
            uVar10 = pool_unusable_part_4(piVar7);
            iVar5 = (int)((ulonglong)uVar10 >> 0x20);
            if ((int)uVar10 == 0) goto LAB_00021f66;
          }
          iVar4 = iVar4 + 1;
        } while (iVar2 != iVar4);
        piVar7 = (int *)piVar9[iVar1];
        break;
      default:
        piVar7 = (int *)pools[iVar1];
      }
    }
    else {
      iVar2 = param_1[1];
      if (iVar2 != 0) {
        if (0 < total_pools) {
          piVar9 = pools + total_pools;
          piVar7 = pools;
          while( true ) {
            iVar4 = *(int *)(*piVar7 + 4);
            iVar5 = iVar4;
            if (iVar4 < iVar2) {
              iVar5 = iVar4 + 1;
            }
            if (iVar4 < iVar2) {
              *(int *)(*piVar7 + 4) = iVar5;
            }
            if (piVar9 == piVar7 + 1) break;
            iVar2 = param_1[1];
            piVar7 = piVar7 + 1;
          }
        }
        param_1[1] = 0;
      }
      switch(pool_strategy) {
      case 0:
      case 3:
      case 4:
switchD_00021f1e_caseD_0:
        if (0 < total_pools) {
          iVar2 = 0;
          do {
            iVar5 = priority_pool(iVar2);
            if ((*(char *)(iVar5 + 0x61) == '\0') && (*(int *)(iVar5 + 100) == 1)) {
              uVar10 = pool_unusable_part_4(iVar5,iVar5);
              if ((int)uVar10 == 0) {
                piVar7 = (int *)pools[*(int *)((ulonglong)uVar10 >> 0x20)];
                goto LAB_00021f66;
              }
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < total_pools);
        }
      default:
switchD_00021f1e_caseD_5:
        piVar7 = (int *)pools[iVar1];
        break;
      case 1:
      case 2:
        if (*(char *)((int)param_1 + 0x61) != '\0') goto LAB_00022016;
        piVar7 = (int *)pools[*param_1];
      }
    }
LAB_00021f66:
    currentpool = piVar7;
    iVar1 = pthread_rwlock_unlock(DAT_000221b4);
    uVar11 = DAT_000221c0;
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
      uVar8 = 0x147f;
      goto LAB_000220de;
    }
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
    if (iVar1 == 0) {
      (*selective_yield)();
      if ((piVar3 != piVar7) && (1 < pool_strategy - 3U)) {
        if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
          snprintf(acStack_820,0x800,"Switching to pool %d %s",*piVar7,piVar7[0x29]);
          _applog(4,acStack_820,0);
        }
        clear_pool_work(piVar3);
      }
      iVar1 = pthread_mutex_lock(DAT_000221b8);
      if (iVar1 != 0) {
        piVar3 = __errno_location();
        iVar1 = *piVar3;
        uVar8 = 0x1487;
        goto LAB_000220ce;
      }
      pthread_cond_broadcast(DAT_000221bc);
      iVar1 = pthread_mutex_unlock(DAT_000221b8);
      if (iVar1 == 0) {
        (*selective_yield)();
        return;
      }
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      uVar8 = 0x1489;
    }
    else {
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      uVar8 = 0x147f;
    }
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar11 = DAT_000221c0;
  }
  else {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    uVar8 = 0x142e;
LAB_000220ce:
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar11 = DAT_000221c0;
  }
LAB_000220de:
  snprintf(acStack_820,0x800,__format,iVar1,"cgminer.c",uVar11,uVar8);
  _applog(3,acStack_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

