
/* WARNING: Unknown calling convention */

work * hash_pop(_Bool blocking)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  work *pwVar7;
  int iVar8;
  int iVar9;
  int rc;
  UT_hash_bucket *pUVar10;
  time_t tVar11;
  int iVar12;
  work *tmp;
  void *pvVar13;
  uint uVar14;
  UT_hash_handle *pUVar15;
  work *in_r2;
  UT_hash_handle *pUVar16;
  int in_r3;
  time_t *line;
  work *pwVar17;
  UT_hash_table *pUVar18;
  work *pwVar19;
  UT_hash_handle *_hd_hh_del;
  bool bVar20;
  timespec then;
  timeval now;
  char tmp42 [2048];
  
  iVar12 = DAT_0002070c;
  pwVar7 = (work *)(uint)blocking;
  iVar8 = pthread_mutex_lock(*(pthread_mutex_t **)(DAT_0002070c + 0x454));
  if (iVar8 != 0) {
    _mutex_lock(DAT_00020734,(char *)0x1f78,(char *)in_r2,in_r3);
  }
  if ((*(int *)(iVar12 + 0x458) == 0) ||
     (*(int *)(*(int *)(*(int *)(iVar12 + 0x458) + 0x158) + 0xc) == 0)) {
    line = (time_t *)0x1;
    *(undefined *)(iVar12 + 0x45d) = 1;
    piVar6 = DAT_00020730;
    pcVar5 = DAT_00020720;
    pcVar4 = DAT_0002071c;
    piVar2 = DAT_00020710;
    iVar8 = DAT_0002070c;
    if (pwVar7 == (work *)0x0) goto out_unlock;
    do {
      cgtime(&now);
      then.tv_nsec = now.tv_usec * 1000;
      then.tv_sec = now.tv_sec + 10;
      pthread_cond_signal(DAT_00020714);
      iVar9 = pthread_cond_timedwait
                        ((pthread_cond_t *)(*piVar2 + 0x28),*(pthread_mutex_t **)(iVar12 + 0x454),
                         (timespec *)&then);
      puVar3 = DAT_00020718;
      if (((iVar9 != 0) && (*(char *)(iVar8 + 0x45c) == '\0')) &&
         ((cVar1 = *pcVar4, *(undefined *)(iVar8 + 0x45c) = 1, cVar1 != '\0' ||
          ((*pcVar5 != '\0' || (3 < *piVar6)))))) {
        tmp42._0_4_ = *puVar3;
        tmp42._4_4_ = puVar3[1];
        tmp42._8_4_ = puVar3[2];
        tmp42._12_4_ = puVar3[3];
        tmp42._16_4_ = puVar3[4];
        tmp42._20_4_ = puVar3[5];
        tmp42._24_4_ = puVar3[6];
        tmp42._28_4_ = puVar3[7];
        tmp42._32_4_ = puVar3[8];
        tmp42._36_4_ = puVar3[9];
        tmp42._40_4_ = puVar3[10];
        tmp42[44] = (char)puVar3[0xb];
        _applog(4,tmp42,false);
      }
    } while ((*(int *)(iVar12 + 0x458) == 0) ||
            (*(int *)(*(int *)(*(int *)(iVar12 + 0x458) + 0x158) + 0xc) == 0));
    cVar1 = *(char *)(iVar12 + 0x45c);
  }
  else {
    cVar1 = *(char *)(iVar12 + 0x45c);
    piVar2 = DAT_00020710;
  }
  if (cVar1 != '\0') {
    if (((*DAT_0002071c != '\0') || (*DAT_00020720 != '\0')) || (3 < *DAT_00020730)) {
      tmp42._0_4_ = *DAT_00020724;
      tmp42._4_4_ = DAT_00020724[1];
      tmp42._8_4_ = DAT_00020724[2];
      tmp42._12_4_ = DAT_00020724[3];
      tmp42._16_4_ = DAT_00020724[4];
      tmp42._20_4_ = DAT_00020724[5];
      tmp42._24_4_ = DAT_00020724[6];
      tmp42._28_4_ = DAT_00020724[7];
      tmp42._32_4_ = DAT_00020724[8];
      tmp42[36] = (char)DAT_00020724[9];
      _applog(4,tmp42,false);
    }
    *(undefined *)(iVar12 + 0x45c) = 0;
  }
  in_r2 = *(work **)(iVar12 + 0x458);
  pUVar18 = pURam00000158;
  if (((in_r2 == (work *)0x0) ||
      (pUVar18 = (in_r2->hh).tbl, (int)pUVar18->num_items <= *(int *)(DAT_0002070c + 0x460))) ||
     ((in_r2->clone != false || (pwVar19 = (work *)(in_r2->hh).next, in_r2->rolltime == 0)))) {
    pvVar13 = (in_r2->hh).prev;
    pwVar19 = (work *)(in_r2->hh).next;
    pwVar7 = in_r2;
    if (pvVar13 == (void *)0x0) goto LAB_000206b4;
LAB_00020586:
    iVar8 = pUVar18->hho;
    pwVar17 = (work *)((int)pUVar18->tail - iVar8);
    bVar20 = pwVar7 == pwVar17;
    if (bVar20) {
      pwVar17 = (work *)((int)pvVar13 + iVar8);
    }
    if (bVar20) {
      pUVar18->tail = (UT_hash_handle *)pwVar17;
    }
    if (pvVar13 == (void *)0x0) {
      *(work **)(iVar12 + 0x458) = pwVar19;
      in_r2 = pwVar19;
    }
    else {
      *(work **)((int)pvVar13 + iVar8 + 8) = pwVar19;
      pwVar19 = (work *)(pwVar7->hh).next;
    }
    pUVar18 = (in_r2->hh).tbl;
    if (pwVar19 != (work *)0x0) {
      *(void **)(pwVar19->data + pUVar18->hho + 4) = pvVar13;
    }
    pUVar10 = pUVar18->buckets;
    uVar14 = pUVar18->num_buckets - 1 & (pwVar7->hh).hashv;
    pUVar16 = (pwVar7->hh).hh_next;
    pUVar10[uVar14].count = pUVar10[uVar14].count - 1;
    if (pUVar10[uVar14].hh_head == &pwVar7->hh) {
      pUVar10[uVar14].hh_head = pUVar16;
    }
    pUVar15 = (pwVar7->hh).hh_prev;
    if (pUVar15 != (UT_hash_handle *)0x0) {
      pUVar15->hh_next = pUVar16;
      pUVar16 = (pwVar7->hh).hh_next;
    }
    if (pUVar16 != (UT_hash_handle *)0x0) {
      pUVar16->hh_prev = pUVar15;
    }
    in_r2 = (work *)(pUVar18->num_items - 1);
    pUVar18->num_items = (uint)in_r2;
  }
  else {
    do {
      pwVar7 = pwVar19;
      if ((pwVar7 == (work *)0x0) || (pwVar7->clone != false)) break;
      pwVar19 = (work *)(pwVar7->hh).next;
    } while (pwVar7->rolltime != 0);
    pvVar13 = (pwVar7->hh).prev;
    pwVar19 = (work *)(pwVar7->hh).next;
    if (pvVar13 != (void *)0x0) goto LAB_00020586;
LAB_000206b4:
    if (pwVar19 != (work *)0x0) goto LAB_00020586;
    free(pUVar18->buckets);
    free(*(void **)(*(int *)(iVar12 + 0x458) + 0x158));
    *(undefined4 *)(iVar12 + 0x458) = 0;
  }
  if ((pwVar7->clone == false) && (pwVar7->rolltime != 0)) {
    *(int *)(iVar12 + 0x460) = *(int *)(iVar12 + 0x460) + -1;
  }
  pthread_cond_signal(DAT_00020714);
  pthread_cond_signal((pthread_cond_t *)(*piVar2 + 0x28));
  tVar11 = time((time_t *)0x0);
  line = DAT_00020728;
  *DAT_00020728 = tVar11;
out_unlock:
  iVar12 = pthread_mutex_unlock(*(pthread_mutex_t **)(iVar12 + 0x454));
  if (iVar12 != 0) {
    _mutex_unlock_noyield(DAT_00020734,(char *)0x1fc0,(char *)in_r2,(int)line);
  }
  (**DAT_0002072c)();
  return pwVar7;
}

