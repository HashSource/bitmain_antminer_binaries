
_Bool parse_diff(pool *pool,json_t *val)

{
  json_t *json;
  _Bool _Var1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  json_t *val_local;
  pool *pool_local;
  char tmp42 [2048];
  int idiff;
  double diff;
  double old_diff;
  
  json = json_array_get(val,0);
  dVar3 = json_number_value(json);
  if (dVar3 == 0.0) {
    _Var1 = false;
  }
  else {
    _cg_wlock(&pool->data_lock,"util.c","parse_diff",0x8d6);
    dVar4 = pool->next_diff;
    diff._0_4_ = SUB84(dVar3,0);
    diff._4_4_ = (undefined4)((ulonglong)dVar3 >> 0x20);
    if (dVar4 == 0.0 || dVar4 < 0.0 != NAN(dVar4)) {
      old_diff._0_4_ = *(undefined4 *)&pool->sdiff;
      old_diff._4_4_ = *(undefined4 *)((int)&pool->sdiff + 4);
      *(undefined4 *)&pool->sdiff = diff._0_4_;
      *(undefined4 *)((int)&pool->sdiff + 4) = diff._4_4_;
      uVar2 = *(undefined4 *)((int)&pool->sdiff + 4);
      *(undefined4 *)&pool->next_diff = *(undefined4 *)&pool->sdiff;
      *(undefined4 *)((int)&pool->next_diff + 4) = uVar2;
    }
    else {
      old_diff._0_4_ = *(undefined4 *)&pool->next_diff;
      old_diff._4_4_ = *(undefined4 *)((int)&pool->next_diff + 4);
      *(undefined4 *)&pool->next_diff = diff._0_4_;
      *(undefined4 *)((int)&pool->next_diff + 4) = diff._4_4_;
    }
    _cg_wunlock(&pool->data_lock,"util.c","parse_diff",0x8e3);
    if ((double)CONCAT44(old_diff._4_4_,old_diff._0_4_) == dVar3) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Pool %d difficulty set to %f",pool->pool_no,diff._0_4_,diff._4_4_);
        _applog(7,tmp42,false);
      }
    }
    else if (dVar3 == (double)(longlong)(int)(longlong)dVar3) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d difficulty changed to %d",pool->pool_no,(int)(longlong)dVar3);
        _applog(5,tmp42,false);
      }
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Pool %d difficulty changed to %.1f",pool->pool_no,diff._0_4_,diff._4_4_)
      ;
      _applog(5,tmp42,false);
    }
    _Var1 = true;
  }
  return _Var1;
}

