
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _discard_work(work **workptr,char *file,char *func,int line)

{
  work *pwVar1;
  bool bVar2;
  int line_local;
  char *func_local;
  char *file_local;
  work **workptr_local;
  char tmp42 [2048];
  work *work;
  
  pwVar1 = *workptr;
  if (pwVar1 == (work *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Discard work called with NULL work from %s %s:%d",file,func,line);
      _applog(3,tmp42,false);
    }
  }
  else {
    if (((pwVar1->clone == true) || (pwVar1->rolls != 0)) || (pwVar1->mined == true)) {
      if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
        tmp42._0_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._0_4_;
        tmp42._4_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._4_4_;
        tmp42._8_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._8_4_;
        tmp42._12_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._12_4_;
        tmp42._16_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._16_4_;
        tmp42._20_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._20_4_;
        tmp42._24_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._24_4_;
        tmp42._28_4_ = s_Discarded_cloned_or_rolled_work_000a3c80._28_4_;
        _applog(7,tmp42,false);
      }
    }
    else {
      if (pwVar1->pool != (pool *)0x0) {
        pwVar1->pool->discarded_work = pwVar1->pool->discarded_work + 1;
        pwVar1->pool->quota_used = pwVar1->pool->quota_used + -1;
        pwVar1->pool->works = pwVar1->pool->works + -1;
      }
      bVar2 = 0xfffffffe < (uint)total_discarded;
      total_discarded._0_4_ = (uint)total_discarded + 1;
      total_discarded._4_4_ = total_discarded._4_4_ + (uint)bVar2;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Discarded_work_000a3c70[0];
        tmp42[1] = s_Discarded_work_000a3c70[1];
        tmp42[2] = s_Discarded_work_000a3c70[2];
        tmp42[3] = s_Discarded_work_000a3c70[3];
        tmp42[4] = s_Discarded_work_000a3c70[4];
        tmp42[5] = s_Discarded_work_000a3c70[5];
        tmp42[6] = s_Discarded_work_000a3c70[6];
        tmp42[7] = s_Discarded_work_000a3c70[7];
        tmp42[8] = s_Discarded_work_000a3c70[8];
        tmp42[9] = s_Discarded_work_000a3c70[9];
        tmp42[10] = s_Discarded_work_000a3c70[10];
        tmp42[11] = s_Discarded_work_000a3c70[11];
        tmp42._12_3_ = (undefined3)ram0x000a3c7c;
        _applog(7,tmp42,false);
      }
    }
    _free_work(workptr,file,func,line);
  }
  return;
}

