
/* WARNING: Unknown calling convention */

void _discard_work(work **workptr,char *file,char *func,int line)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  work *pwVar4;
  work *work;
  pool *ppVar5;
  uint uVar6;
  char tmp42 [2048];
  
  pwVar4 = *workptr;
  if (pwVar4 == (work *)0x0) {
    if (((*DAT_0001f044 != '\0') || (*DAT_0001f048 != '\0')) || (2 < *DAT_0001f04c)) {
      snprintf(tmp42,0x800,DAT_0001f058,file,func,line);
      _applog(3,tmp42,false);
    }
  }
  else {
    if (((pwVar4->clone == false) && (pwVar4->rolls == 0)) && (pwVar4->mined == false)) {
      ppVar5 = pwVar4->pool;
      if (ppVar5 != (pool *)0x0) {
        ppVar5->discarded_work = ppVar5->discarded_work + 1;
        ppVar5->quota_used = ppVar5->quota_used + -1;
        ppVar5->works = ppVar5->works + -1;
      }
      puVar3 = DAT_0001f03c;
      uVar6 = *DAT_0001f03c;
      puVar2 = DAT_0001f03c + 1;
      cVar1 = *DAT_0001f040;
      *DAT_0001f03c = uVar6 + 1;
      puVar3[1] = *puVar2 + (uint)(0xfffffffe < uVar6);
      if ((cVar1 != '\0') &&
         (((*DAT_0001f044 != '\0' || (*DAT_0001f048 != '\0')) || (6 < *DAT_0001f04c)))) {
        tmp42._0_4_ = *DAT_0001f054;
        tmp42._4_4_ = DAT_0001f054[1];
        tmp42._8_4_ = DAT_0001f054[2];
        tmp42._12_3_ = (undefined3)DAT_0001f054[3];
        _applog(7,tmp42,false);
      }
    }
    else if ((*DAT_0001f040 != '\0') &&
            (((*DAT_0001f044 != '\0' || (*DAT_0001f048 != '\0')) || (6 < *DAT_0001f04c)))) {
      tmp42._0_4_ = *DAT_0001f050;
      tmp42._4_4_ = DAT_0001f050[1];
      tmp42._8_4_ = DAT_0001f050[2];
      tmp42._12_4_ = DAT_0001f050[3];
      tmp42._16_4_ = DAT_0001f050[4];
      tmp42._20_4_ = DAT_0001f050[5];
      tmp42._24_4_ = DAT_0001f050[6];
      tmp42._28_4_ = DAT_0001f050[7];
      _applog(7,tmp42,false);
    }
    _free_work(workptr,file,func,line);
  }
  return;
}

