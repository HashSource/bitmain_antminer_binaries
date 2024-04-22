
/* WARNING: Unknown calling convention */

work * get_work(thr_info *thr,int thr_id)

{
  work *pwVar1;
  _Bool _Var2;
  time_t tVar3;
  time_t tVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  time_t diff_t;
  cgpu_info *cgpu;
  cgpu_info *pcVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  work *work;
  char tmp42 [2048];
  
  pcVar10 = DAT_00028c10;
  work = (work *)0x0;
  pcVar11 = thr->cgpu;
  thread_reportout(thr);
  if ((*pcVar10 != '\0') &&
     (((*DAT_00028c14 != '\0' || (*DAT_00028c18 != '\0')) || (6 < *DAT_00028c3c)))) {
    tmp42._0_4_ = *DAT_00028c1c;
    tmp42._4_4_ = DAT_00028c1c[1];
    tmp42._8_4_ = DAT_00028c1c[2];
    tmp42._12_4_ = DAT_00028c1c[3];
    tmp42._16_4_ = DAT_00028c1c[4];
    tmp42._20_4_ = DAT_00028c1c[5];
    tmp42._24_4_ = DAT_00028c1c[6];
    tmp42._28_4_ = DAT_00028c1c[7];
    tmp42._32_4_ = DAT_00028c1c[8];
    tmp42._36_4_ = DAT_00028c1c[9];
    _applog(7,tmp42,false);
  }
  tVar3 = time((time_t *)0x0);
  while (work == (work *)0x0) {
    while( true ) {
      pwVar1 = work;
      work = hash_pop(true);
      _Var2 = stale_work(work,SUB41(pwVar1,0));
      if (!_Var2) break;
      _discard_work(&work,DAT_00028c20,DAT_00028c24,0x214c);
      wake_gws();
      if (work != (work *)0x0) goto LAB_00028abe;
    }
  }
LAB_00028abe:
  tVar4 = time((time_t *)0x0);
  iVar9 = tVar4 - tVar3;
  cVar7 = *pcVar10;
  if (0 < iVar9) {
    if (cVar7 != '\0') {
      if (((*DAT_00028c14 == '\0') && (*DAT_00028c18 == '\0')) && (*DAT_00028c3c < 7)) {
        cVar7 = '\x01';
      }
      else {
        snprintf(tmp42,0x800,DAT_00028c28,iVar9);
        _applog(7,tmp42,false);
        cVar7 = *pcVar10;
      }
    }
    pcVar11->last_device_valid_work = pcVar11->last_device_valid_work + iVar9;
  }
  if ((cVar7 != '\0') &&
     (((*DAT_00028c14 != '\0' || (*DAT_00028c18 != '\0')) || (6 < *DAT_00028c3c)))) {
    snprintf(tmp42,0x800,DAT_00028c2c,thr_id);
    _applog(7,tmp42,false);
  }
  cVar7 = *(char *)(DAT_00028c30 + 0x74d);
  work->thr_id = thr_id;
  if (cVar7 == '\0') goto LAB_00028b38;
  iVar5 = pcVar11->lodiff;
  iVar9 = iVar5 + pcVar11->direction;
  pcVar11->lodiff = iVar9;
  if (iVar9 < 1) {
    iVar5 = 1;
  }
  if (iVar9 < 1) {
    pcVar11->direction = iVar5;
LAB_00028c00:
    iVar6 = 0x2139;
    iVar5 = DAT_00028c40;
    pcVar10 = DAT_00028c38;
  }
  else {
    if (iVar9 < 0x10) goto LAB_00028c00;
    iVar6 = -1;
    pcVar11->direction = -1;
    pcVar10 = DAT_00028c38;
    iVar5 = DAT_00028c34;
    iVar8 = pcVar11->hidiff + 1;
    bVar12 = pcVar11->hidiff + -0xe < 0;
    if (0xf < iVar8) {
      iVar6 = 0;
    }
    iVar9 = iVar6;
    if (iVar8 == 0xf || bVar12 != SBORROW4(iVar8,0xf)) {
      pcVar11->hidiff = iVar8;
      iVar9 = iVar8;
    }
    if (iVar8 != 0xf && bVar12 == SBORROW4(iVar8,0xf)) {
      pcVar11->hidiff = iVar6;
    }
    iVar6 = 0x2135;
  }
  _cg_memcpy(work,(void *)(iVar5 + iVar9 * 0xa0),0xa0,DAT_00028c20,pcVar10,iVar6);
LAB_00028b38:
  thread_reportin(thr);
  dVar13 = work->work_difficulty;
  dVar15 = pcVar11->drv->max_diff;
  dVar14 = pcVar11->drv->min_diff;
  work->mined = true;
  if (dVar15 != dVar13 && dVar15 < dVar13 == (NAN(dVar15) || NAN(dVar13))) {
    dVar15 = dVar13;
  }
  if ((int)((uint)(dVar15 < dVar14) << 0x1f) < 0) {
    dVar15 = dVar14;
  }
  work->device_diff = dVar15;
  return work;
}

