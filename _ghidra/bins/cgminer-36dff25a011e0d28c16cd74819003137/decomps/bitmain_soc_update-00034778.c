
void bitmain_soc_update(cgpu_info *bitmain_soc)

{
  cgpu_info *bitmain_soc_local;
  char tmp42 [2048];
  uchar *buf;
  work *work;
  pool *pool;
  thr_info *thr;
  bitmain_soc_info *info;
  
  info = (bitmain_soc_info *)bitmain_soc->device_data;
  thr = *bitmain_soc->thr;
  buf = (uchar *)0x0;
  _mutex_lock(&info->lock,"driver-btm-soc.c","bitmain_soc_update",0x22a2);
  thr->work_update = false;
  thr->work_restart = false;
  work = get_work(thr,thr->id);
  _discard_work(&work,"driver-btm-soc.c","bitmain_soc_update",0x22a7);
  pool = current_pool();
  if (pool->has_stratum != true) {
    builtin_strncpy(tmp42,"Bitmain S9 has to use stratum pools",0x24);
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cg_wlock(&info->update_lock,"driver-btm-soc.c","bitmain_soc_update",0x22ae);
  _cg_rlock(&pool->data_lock,"driver-btm-soc.c","bitmain_soc_update",0x22af);
  info->pool_no = pool->pool_no;
  copy_pool_stratum(&info->pool2,&info->pool1);
  info->pool2_given_id = info->pool1_given_id;
  copy_pool_stratum(&info->pool1,&info->pool0);
  info->pool1_given_id = info->pool0_given_id;
  copy_pool_stratum(&info->pool0,pool);
  given_id = given_id + 1;
  info->pool0_given_id = given_id;
  parse_job_to_soc(&buf,pool,info->pool0_given_id);
  if (status_error != true) {
    pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
    send_job(buf,pool);
    pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  }
  _cg_runlock(&pool->data_lock,"driver-btm-soc.c","bitmain_soc_update",0x22c2);
  _cg_wunlock(&info->update_lock,"driver-btm-soc.c","bitmain_soc_update",0x22c3);
  free(buf);
  _mutex_unlock(&info->lock,"driver-btm-soc.c","bitmain_soc_update",0x22c5);
  return;
}

