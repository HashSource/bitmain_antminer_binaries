
/* WARNING: Unknown calling convention */

void submit_work_async(work *work)

{
  char cVar1;
  pthread_mutex_t *ppVar2;
  char **ppcVar3;
  double *pdVar4;
  _Bool _Var5;
  thr_info *ptVar6;
  thr_info *thr;
  int iVar7;
  int iVar8;
  char *in_r2;
  char *pcVar9;
  work *line;
  uint uVar10;
  pool *pool;
  pool *ppVar11;
  cgpu_info *cgpu;
  cgpu_info *pcVar12;
  char *pcVar13;
  char *pcVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  work *local_82c [2];
  pthread_t submit_thread;
  char tmp42 [2048];
  
  ppVar11 = work->pool;
  local_82c[0] = work;
  cgtime(&work->tv_work_found);
  if (*(char *)(DAT_000295a4 + 0x74d) != '\0') {
    line = local_82c[0];
    ptVar6 = get_thread(local_82c[0]->thr_id);
    pcVar12 = ptVar6->cgpu;
    iVar7 = pthread_mutex_lock(DAT_000295a8);
    if (iVar7 != 0) {
      _mutex_lock(DAT_00029704,(char *)0x2178,in_r2,(int)line);
    }
    pdVar4 = DAT_000295f0;
    ppcVar3 = DAT_000295ac;
    dVar15 = pcVar12->diff_accepted;
    dVar18 = local_82c[0]->work_difficulty;
    uVar10 = *(uint *)&ppVar11->accepted;
    iVar7 = *(int *)((int)&ppVar11->accepted + 4);
    dVar16 = ppVar11->diff_accepted;
    pcVar13 = *DAT_000295ac;
    pcVar14 = DAT_000295ac[1];
    pcVar12->accepted = pcVar12->accepted + 1;
    ppVar2 = DAT_000295a8;
    pcVar9 = pcVar13 + 1;
    dVar17 = *pdVar4;
    pcVar14 = pcVar14 + ((char *)0xfffffffe < pcVar13);
    *(uint *)&ppVar11->accepted = uVar10 + 1;
    *(uint *)((int)&ppVar11->accepted + 4) = iVar7 + (uint)(0xfffffffe < uVar10);
    pcVar12->diff_accepted = dVar15 + dVar18;
    ppVar11->diff_accepted = dVar16 + dVar18;
    *ppcVar3 = pcVar9;
    ppcVar3[1] = pcVar14;
    *pdVar4 = dVar18 + dVar17;
    iVar7 = pthread_mutex_unlock(ppVar2);
    if (iVar7 != 0) {
      _mutex_unlock_noyield(DAT_00029704,(char *)0x217f,pcVar9,(int)pcVar14);
    }
    (**DAT_000295b0)();
    if (((*DAT_000295b4 == '\0') && (*DAT_000295b8 == '\0')) && (*DAT_000295c8 < 5)) {
      return;
    }
    snprintf(tmp42,0x800,DAT_000295bc,pcVar12->drv->name,pcVar12->device_id,
             *(undefined4 *)(local_82c[0]->data + 0x4c));
    _applog(5,tmp42,false);
    return;
  }
  _Var5 = stale_work(local_82c[0],true);
  if (!_Var5) {
    cVar1 = local_82c[0]->stratum;
    pcVar9 = DAT_000295c0;
    goto joined_r0x00029506;
  }
  if (*(char *)(DAT_000295d8 + 0x825) == '\0') {
    if (ppVar11->submit_old == false) {
      if (((*DAT_000296dc != '\0') || (*DAT_000296e0 != '\0')) || (iVar7 = *DAT_000296e4, 4 < iVar7)
         ) {
        iVar7 = ppVar11->pool_no;
        snprintf(tmp42,0x800,DAT_000296e8);
        in_r2 = (char *)0x0;
        _applog(5,tmp42,false);
      }
      sharelog(DAT_000296ec,local_82c[0]);
      iVar8 = pthread_mutex_lock(DAT_000296f0);
      if (iVar8 != 0) {
        _mutex_lock(DAT_00029704,(char *)0x2194,in_r2,iVar7);
      }
      ppcVar3 = DAT_000296f8;
      pdVar4 = DAT_000296f4;
      dVar16 = local_82c[0]->work_difficulty;
      dVar15 = *DAT_000296f4;
      pcVar9 = *DAT_000296f8;
      pcVar13 = DAT_000296f8[1];
      pcVar14 = pcVar9 + 1;
      ppVar11->stale_shares = ppVar11->stale_shares + 1;
      ppVar2 = DAT_000296f0;
      pcVar13 = pcVar13 + ((char *)0xfffffffe < pcVar9);
      ppVar11->diff_stale = ppVar11->diff_stale + dVar16;
      *pdVar4 = dVar16 + dVar15;
      *ppcVar3 = pcVar14;
      ppcVar3[1] = pcVar13;
      iVar7 = pthread_mutex_unlock(ppVar2);
      if (iVar7 != 0) {
        _mutex_unlock_noyield(DAT_00029704,(char *)0x219b,pcVar14,(int)pcVar13);
      }
      (**DAT_000296fc)();
      _free_work(local_82c,DAT_00029700,DAT_00029704->__size,0x219d);
      return;
    }
    pcVar9 = DAT_000295ec;
    if ((*DAT_000295b4 == '\0') && (*DAT_000295b8 == '\0')) {
      iVar7 = *DAT_000295c8;
      goto joined_r0x00029598;
    }
LAB_000294e8:
    snprintf(tmp42,0x800,pcVar9,ppVar11->pool_no);
    _applog(5,tmp42,false);
  }
  else {
    pcVar9 = DAT_000295dc;
    if ((*DAT_000295b4 != '\0') || (*DAT_000295b8 != '\0')) goto LAB_000294e8;
    iVar7 = *DAT_000296e4;
joined_r0x00029598:
    if (4 < iVar7) goto LAB_000294e8;
  }
  local_82c[0]->stale = true;
  cVar1 = local_82c[0]->stratum;
  pcVar9 = DAT_000295c0;
joined_r0x00029506:
  DAT_000295c0 = pcVar9;
  if (cVar1 == '\0') {
    if ((*pcVar9 != '\0') &&
       (((*DAT_000295b4 != '\0' || (*DAT_000295b8 != '\0')) || (6 < *DAT_000296e4)))) {
      tmp42._0_4_ = *DAT_000295e0;
      tmp42._4_4_ = DAT_000295e0[1];
      tmp42._8_4_ = DAT_000295e0[2];
      tmp42._12_4_ = DAT_000295e0[3];
      tmp42._16_4_ = DAT_000295e0[4];
      tmp42._20_4_ = DAT_000295e0[5];
      tmp42._24_4_ = DAT_000295e0[6];
      tmp42._28_4_ = DAT_000295e0[7];
      tmp42._32_3_ = (undefined3)DAT_000295e0[8];
      _applog(7,tmp42,false);
    }
    iVar7 = pthread_create(&submit_thread,(pthread_attr_t *)0x0,DAT_000295e4,local_82c[0]);
    if (iVar7 != 0) {
      tmp42._0_4_ = *DAT_000295e8;
      tmp42._4_4_ = DAT_000295e8[1];
      tmp42._8_4_ = DAT_000295e8[2];
      tmp42._12_4_ = DAT_000295e8[3];
      tmp42._16_4_ = DAT_000295e8[4];
      tmp42._20_4_ = DAT_000295e8[5];
      tmp42._24_4_ = DAT_000295e8[6];
      tmp42._28_4_ = DAT_000295e8[7];
      tmp42._32_4_ = DAT_000295e8[8];
      _applog(3,tmp42,true);
      _quit(1);
    }
  }
  else {
    if ((*pcVar9 != '\0') &&
       (((*DAT_000295b4 != '\0' || (*DAT_000295b8 != '\0')) || (6 < *DAT_000296e4)))) {
      snprintf(tmp42,0x800,DAT_000295c4,ppVar11->pool_no);
      _applog(7,tmp42,false);
    }
    if ((ppVar11->stratum_q == (thread_q *)0x0) ||
       (_Var5 = tq_push(ppVar11->stratum_q,local_82c[0]), !_Var5)) {
      if ((*pcVar9 != '\0') &&
         (((*DAT_000295b4 != '\0' || (*DAT_000295b8 != '\0')) || (6 < *DAT_000295c8)))) {
        tmp42._0_4_ = *DAT_000295cc;
        tmp42._4_4_ = DAT_000295cc[1];
        tmp42._8_4_ = DAT_000295cc[2];
        tmp42._12_4_ = DAT_000295cc[3];
        tmp42._16_4_ = DAT_000295cc[4];
        tmp42._20_4_ = DAT_000295cc[5];
        tmp42._24_4_ = DAT_000295cc[6];
        tmp42._28_4_ = DAT_000295cc[7];
        tmp42[32] = (char)(short)DAT_000295cc[8];
        tmp42[33] = (char)((ushort)(short)DAT_000295cc[8] >> 8);
        _applog(7,tmp42,false);
      }
      _free_work(local_82c,DAT_000295d0,DAT_000295d4,0x21a9);
    }
  }
  return;
}

