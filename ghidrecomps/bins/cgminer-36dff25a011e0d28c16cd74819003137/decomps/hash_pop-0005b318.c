
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

work * hash_pop(_Bool blocking)

{
  _Bool _Var1;
  int iVar2;
  UT_hash_bucket *pUVar3;
  uint uVar4;
  UT_hash_table *pUVar5;
  _Bool blocking_local;
  char tmp42 [2048];
  timeval now;
  timespec then;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  int hc;
  int rc;
  work *tmp;
  work *work;
  
  work = (work *)0x0;
  _mutex_lock(stgd_lock,"cgminer.c","hash_pop",0x1fce);
  if ((staged_work == (work *)0x0) || (((staged_work->hh).tbl)->num_items == 0)) {
    work_emptied = true;
    if (!blocking) goto out_unlock;
    do {
      cgtime(&now);
      then.tv_sec = now.tv_sec + 10;
      then.tv_nsec = now.tv_usec * 1000;
      pthread_cond_signal((pthread_cond_t *)&gws_cond);
      iVar2 = pthread_cond_timedwait
                        ((pthread_cond_t *)&getq->cond,(pthread_mutex_t *)stgd_lock,
                         (timespec *)&then);
      if (((iVar2 != 0) && (no_work != true)) &&
         ((no_work = true, use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))
          ))) {
        tmp42[0] = s_Waiting_for_work_to_be_available_000a4ab0[0];
        tmp42[1] = s_Waiting_for_work_to_be_available_000a4ab0[1];
        tmp42[2] = s_Waiting_for_work_to_be_available_000a4ab0[2];
        tmp42[3] = s_Waiting_for_work_to_be_available_000a4ab0[3];
        tmp42[4] = s_Waiting_for_work_to_be_available_000a4ab0[4];
        tmp42[5] = s_Waiting_for_work_to_be_available_000a4ab0[5];
        tmp42[6] = s_Waiting_for_work_to_be_available_000a4ab0[6];
        tmp42[7] = s_Waiting_for_work_to_be_available_000a4ab0[7];
        tmp42[8] = s_Waiting_for_work_to_be_available_000a4ab0[8];
        tmp42[9] = s_Waiting_for_work_to_be_available_000a4ab0[9];
        tmp42[10] = s_Waiting_for_work_to_be_available_000a4ab0[10];
        tmp42[11] = s_Waiting_for_work_to_be_available_000a4ab0[11];
        tmp42[12] = s_Waiting_for_work_to_be_available_000a4ab0[12];
        tmp42[13] = s_Waiting_for_work_to_be_available_000a4ab0[13];
        tmp42[14] = s_Waiting_for_work_to_be_available_000a4ab0[14];
        tmp42[15] = s_Waiting_for_work_to_be_available_000a4ab0[15];
        tmp42[16] = s_Waiting_for_work_to_be_available_000a4ab0[16];
        tmp42[17] = s_Waiting_for_work_to_be_available_000a4ab0[17];
        tmp42[18] = s_Waiting_for_work_to_be_available_000a4ab0[18];
        tmp42[19] = s_Waiting_for_work_to_be_available_000a4ab0[19];
        tmp42[20] = s_Waiting_for_work_to_be_available_000a4ab0[20];
        tmp42[21] = s_Waiting_for_work_to_be_available_000a4ab0[21];
        tmp42[22] = s_Waiting_for_work_to_be_available_000a4ab0[22];
        tmp42[23] = s_Waiting_for_work_to_be_available_000a4ab0[23];
        tmp42[24] = s_Waiting_for_work_to_be_available_000a4ab0[24];
        tmp42[25] = s_Waiting_for_work_to_be_available_000a4ab0[25];
        tmp42[26] = s_Waiting_for_work_to_be_available_000a4ab0[26];
        tmp42[27] = s_Waiting_for_work_to_be_available_000a4ab0[27];
        tmp42[28] = s_Waiting_for_work_to_be_available_000a4ab0[28];
        tmp42[29] = s_Waiting_for_work_to_be_available_000a4ab0[29];
        tmp42[30] = s_Waiting_for_work_to_be_available_000a4ab0[30];
        tmp42[31] = s_Waiting_for_work_to_be_available_000a4ab0[31];
        tmp42[32] = s_Waiting_for_work_to_be_available_000a4ab0[32];
        tmp42[33] = s_Waiting_for_work_to_be_available_000a4ab0[33];
        tmp42[34] = s_Waiting_for_work_to_be_available_000a4ab0[34];
        tmp42[35] = s_Waiting_for_work_to_be_available_000a4ab0[35];
        tmp42[36] = s_Waiting_for_work_to_be_available_000a4ab0[36];
        tmp42[37] = s_Waiting_for_work_to_be_available_000a4ab0[37];
        tmp42[38] = s_Waiting_for_work_to_be_available_000a4ab0[38];
        tmp42[39] = s_Waiting_for_work_to_be_available_000a4ab0[39];
        tmp42[40] = s_Waiting_for_work_to_be_available_000a4ab0[40];
        tmp42[41] = s_Waiting_for_work_to_be_available_000a4ab0[41];
        tmp42[42] = s_Waiting_for_work_to_be_available_000a4ab0[42];
        tmp42[43] = s_Waiting_for_work_to_be_available_000a4ab0[43];
        tmp42[44] = (char)ram0x000a4adc;
        _applog(4,tmp42,false);
      }
    } while ((staged_work == (work *)0x0) || (((staged_work->hh).tbl)->num_items == 0));
  }
  if (no_work != false) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      tmp42[0] = s_Work_available_from_pools__resum_000a4ae0[0];
      tmp42[1] = s_Work_available_from_pools__resum_000a4ae0[1];
      tmp42[2] = s_Work_available_from_pools__resum_000a4ae0[2];
      tmp42[3] = s_Work_available_from_pools__resum_000a4ae0[3];
      tmp42[4] = s_Work_available_from_pools__resum_000a4ae0[4];
      tmp42[5] = s_Work_available_from_pools__resum_000a4ae0[5];
      tmp42[6] = s_Work_available_from_pools__resum_000a4ae0[6];
      tmp42[7] = s_Work_available_from_pools__resum_000a4ae0[7];
      tmp42[8] = s_Work_available_from_pools__resum_000a4ae0[8];
      tmp42[9] = s_Work_available_from_pools__resum_000a4ae0[9];
      tmp42[10] = s_Work_available_from_pools__resum_000a4ae0[10];
      tmp42[11] = s_Work_available_from_pools__resum_000a4ae0[11];
      tmp42[12] = s_Work_available_from_pools__resum_000a4ae0[12];
      tmp42[13] = s_Work_available_from_pools__resum_000a4ae0[13];
      tmp42[14] = s_Work_available_from_pools__resum_000a4ae0[14];
      tmp42[15] = s_Work_available_from_pools__resum_000a4ae0[15];
      tmp42[16] = s_Work_available_from_pools__resum_000a4ae0[16];
      tmp42[17] = s_Work_available_from_pools__resum_000a4ae0[17];
      tmp42[18] = s_Work_available_from_pools__resum_000a4ae0[18];
      tmp42[19] = s_Work_available_from_pools__resum_000a4ae0[19];
      tmp42[20] = s_Work_available_from_pools__resum_000a4ae0[20];
      tmp42[21] = s_Work_available_from_pools__resum_000a4ae0[21];
      tmp42[22] = s_Work_available_from_pools__resum_000a4ae0[22];
      tmp42[23] = s_Work_available_from_pools__resum_000a4ae0[23];
      tmp42[24] = s_Work_available_from_pools__resum_000a4ae0[24];
      tmp42[25] = s_Work_available_from_pools__resum_000a4ae0[25];
      tmp42[26] = s_Work_available_from_pools__resum_000a4ae0[26];
      tmp42[27] = s_Work_available_from_pools__resum_000a4ae0[27];
      tmp42[28] = s_Work_available_from_pools__resum_000a4ae0[28];
      tmp42[29] = s_Work_available_from_pools__resum_000a4ae0[29];
      tmp42[30] = s_Work_available_from_pools__resum_000a4ae0[30];
      tmp42[31] = s_Work_available_from_pools__resum_000a4ae0[31];
      tmp42[32] = s_Work_available_from_pools__resum_000a4ae0[32];
      tmp42[33] = s_Work_available_from_pools__resum_000a4ae0[33];
      tmp42[34] = s_Work_available_from_pools__resum_000a4ae0[34];
      tmp42[35] = s_Work_available_from_pools__resum_000a4ae0[35];
      tmp42[36] = (char)ram0x000a4b04;
      _applog(4,tmp42,false);
    }
    no_work = false;
  }
  if (staged_work == (work *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = ((staged_work->hh).tbl)->num_items;
  }
  if (staged_rollable < (int)uVar4) {
    work = staged_work;
    if (staged_work == (work *)0x0) {
      tmp = (work *)0x0;
    }
    else {
      tmp = (work *)(staged_work->hh).next;
    }
    while ((work != (work *)0x0 && (_Var1 = work_rollable(work), _Var1))) {
      work = tmp;
      if (tmp == (work *)0x0) {
        tmp = (work *)0x0;
      }
      else {
        tmp = (work *)(tmp->hh).next;
      }
    }
  }
  else {
    work = staged_work;
  }
  if (((work->hh).prev == (void *)0x0) && ((work->hh).next == (void *)0x0)) {
    free(((staged_work->hh).tbl)->buckets);
    free((staged_work->hh).tbl);
    staged_work = (work *)0x0;
  }
  else {
    if (work == (work *)((int)((staged_work->hh).tbl)->tail - ((staged_work->hh).tbl)->hho)) {
      ((staged_work->hh).tbl)->tail =
           (UT_hash_handle *)((int)(work->hh).prev + ((staged_work->hh).tbl)->hho);
    }
    if ((work->hh).prev == (void *)0x0) {
      staged_work = (work *)(work->hh).next;
    }
    else {
      *(void **)((int)(work->hh).prev + ((staged_work->hh).tbl)->hho + 8) = (work->hh).next;
    }
    if ((work->hh).next != (void *)0x0) {
      *(void **)((int)(work->hh).next + ((staged_work->hh).tbl)->hho + 4) = (work->hh).prev;
    }
    uVar4 = ((staged_work->hh).tbl)->num_buckets - 1 & (work->hh).hashv;
    pUVar3 = ((staged_work->hh).tbl)->buckets;
    pUVar3[uVar4].count = pUVar3[uVar4].count - 1;
    if (&work->hh == ((staged_work->hh).tbl)->buckets[uVar4].hh_head) {
      ((staged_work->hh).tbl)->buckets[uVar4].hh_head = (work->hh).hh_next;
    }
    if ((work->hh).hh_prev != (UT_hash_handle *)0x0) {
      ((work->hh).hh_prev)->hh_next = (work->hh).hh_next;
    }
    if ((work->hh).hh_next != (UT_hash_handle *)0x0) {
      ((work->hh).hh_next)->hh_prev = (work->hh).hh_prev;
    }
    pUVar5 = (staged_work->hh).tbl;
    pUVar5->num_items = pUVar5->num_items - 1;
  }
  _Var1 = work_rollable(work);
  if (_Var1) {
    staged_rollable = staged_rollable + -1;
  }
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  pthread_cond_signal((pthread_cond_t *)&getq->cond);
  last_getwork = time((time_t *)0x0);
out_unlock:
  _mutex_unlock(stgd_lock,"cgminer.c","hash_pop",0x2016);
  return work;
}

