
/* WARNING: Unknown calling convention */

_Bool stale_work(work *work,_Bool share)

{
  _Bool _Var1;
  pool *ppVar2;
  int iVar3;
  int iVar4;
  char *func;
  uint line;
  int iVar5;
  undefined4 *puVar6;
  time_t work_expiry;
  int iVar7;
  pool *pool;
  pool *ppVar8;
  pthread_rwlock_t *__rwlock;
  timeval now;
  char tmp42 [2048];
  
  iVar5 = DAT_00028204;
  if ((*(char *)(DAT_00028204 + 0x74d) == '\0') && (*(int *)(DAT_00028204 + 0x448) == 0)) {
    if (work->work_block == *(uint *)(DAT_00028204 + 0x4f4)) {
      iVar7 = work->rolltime;
      ppVar8 = work->pool;
      func = *(char **)(DAT_0002821c + 0x81c);
      if (iVar7 <= (int)func) {
        iVar7 = *(int *)(DAT_0002821c + 0x820);
      }
      if ((share) || (ppVar8->has_stratum == false)) {
LAB_00028084:
        iVar7 = iVar7 - (int)(longlong)
                             ((ppVar8->cgminer_pool_stats).getwork_wait_rolling * 5.0 + 1.0);
        cgtime(&now);
        if (iVar7 < 5) {
          iVar7 = 5;
        }
        if (now.tv_sec - (work->tv_staged).tv_sec < iVar7) {
          if ((((*DAT_00028228 == '\0') || (share)) ||
              ((ppVar2 = current_pool(), ppVar8 == ppVar2 ||
               ((work->mandatory != false || (*(int *)(iVar5 + 0x41c) == 3)))))) ||
             (*(int *)(iVar5 + 0x41c) == 4)) goto LAB_00027fc2;
          if (*DAT_00028208 != '\0') {
            puVar6 = DAT_0002822c;
            if ((*DAT_0002820c != '\0') || (*DAT_00028210 != '\0')) goto LAB_00028146;
            iVar5 = *DAT_00028214;
            goto joined_r0x00028140;
          }
        }
        else if ((*DAT_00028208 != '\0') &&
                (((*DAT_0002820c != '\0' || (*DAT_00028210 != '\0')) || (6 < *DAT_00028214)))) {
          tmp42._0_4_ = *DAT_00028224;
          tmp42._4_4_ = DAT_00028224[1];
          tmp42._8_4_ = DAT_00028224[2];
          tmp42._12_4_ = DAT_00028224[3];
          tmp42._16_4_ = DAT_00028224[4];
          tmp42._20_4_ = DAT_00028224[5];
          tmp42[24] = (char)DAT_00028224[6];
          _applog(7,tmp42,false);
          return true;
        }
      }
      else if ((ppVar8->stratum_active == false) || (line = (uint)ppVar8->stratum_notify, line == 0)
              ) {
        if ((*DAT_00028208 != '\0') &&
           (((*DAT_0002820c != '\0' || (*DAT_00028210 != '\0')) || (6 < *DAT_00028214)))) {
          tmp42._0_4_ = *DAT_00028220;
          tmp42._4_4_ = DAT_00028220[1];
          tmp42._8_4_ = DAT_00028220[2];
          tmp42._12_4_ = DAT_00028220[3];
          tmp42._16_4_ = DAT_00028220[4];
          tmp42._20_4_ = DAT_00028220[5];
          tmp42._24_4_ = DAT_00028220[6];
          tmp42._28_4_ = DAT_00028220[7];
          tmp42._32_3_ = (undefined3)DAT_00028220[8];
          _applog(7,tmp42,false);
          return true;
        }
      }
      else {
        iVar3 = pthread_mutex_lock((pthread_mutex_t *)&ppVar8->data_lock);
        if (iVar3 != 0) {
          _mutex_lock((pthread_mutex_t *)DAT_00028238,(char *)0x137d,func,line);
        }
        __rwlock = &(ppVar8->data_lock).rwlock;
        iVar3 = pthread_rwlock_rdlock((pthread_rwlock_t *)__rwlock);
        if (iVar3 != 0) {
          _rd_lock(DAT_00028238,(char *)0x137d,func,line);
        }
        iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&ppVar8->data_lock);
        if (iVar3 != 0) {
          _mutex_unlock_noyield((pthread_mutex_t *)DAT_00028238,(char *)0x137d,func,line);
        }
        iVar3 = strcmp(work->job_id,(ppVar8->swork).job_id);
        iVar4 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
        if (iVar4 != 0) {
          _rw_unlock(DAT_00028238,(char *)0x1384,func,line);
        }
        (**DAT_00028230)();
        if (iVar3 == 0) goto LAB_00028084;
        if (*DAT_00028208 == '\0') goto LAB_00028012;
        puVar6 = DAT_00028234;
        if ((*DAT_0002820c != '\0') || (*DAT_00028210 != '\0')) goto LAB_00028146;
        iVar5 = *DAT_00028214;
joined_r0x00028140:
        if (6 < iVar5) {
LAB_00028146:
          tmp42._0_4_ = *puVar6;
          tmp42._4_4_ = puVar6[1];
          tmp42._8_4_ = puVar6[2];
          tmp42._12_4_ = puVar6[3];
          tmp42._16_4_ = puVar6[4];
          tmp42._20_4_ = puVar6[5];
          tmp42._24_4_ = puVar6[6];
          tmp42._28_4_ = puVar6[7];
          tmp42._32_4_ = puVar6[8];
          tmp42._36_4_ = puVar6[9];
          tmp42._40_2_ = (undefined2)puVar6[10];
          _applog(7,tmp42,false);
          return true;
        }
      }
    }
    else if ((*DAT_00028208 != '\0') &&
            (((*DAT_0002820c != '\0' || (*DAT_00028210 != '\0')) || (6 < *DAT_00028214)))) {
      tmp42._0_4_ = *DAT_00028218;
      tmp42._4_4_ = DAT_00028218[1];
      tmp42._8_4_ = DAT_00028218[2];
      tmp42._12_4_ = DAT_00028218[3];
      tmp42._16_4_ = DAT_00028218[4];
      tmp42._20_4_ = DAT_00028218[5];
      tmp42._24_4_ = DAT_00028218[6];
      tmp42._28_4_ = DAT_00028218[7];
      tmp42[32] = (char)DAT_00028218[8];
      _applog(7,tmp42,false);
      return true;
    }
LAB_00028012:
    _Var1 = true;
  }
  else {
LAB_00027fc2:
    _Var1 = false;
  }
  return _Var1;
}

