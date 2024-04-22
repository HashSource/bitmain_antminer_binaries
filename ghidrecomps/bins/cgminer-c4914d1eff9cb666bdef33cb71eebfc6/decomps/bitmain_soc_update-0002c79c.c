
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
  _mutex_lock(&info->lock,"driver-btm-soc.c","bitmain_soc_update",0x1e31);
  buf = (uchar *)0x0;
  thr->work_update = false;
  thr->work_restart = false;
  work = get_work(thr,thr->id);
  _discard_work(&work,"driver-btm-soc.c","bitmain_soc_update",0x1e37);
  pool = current_pool();
  if (pool->has_stratum != true) {
    tmp42[0] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[0];
    tmp42[1] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[1];
    tmp42[2] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[2];
    tmp42[3] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[3];
    tmp42[4] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[4];
    tmp42[5] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[5];
    tmp42[6] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[6];
    tmp42[7] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[7];
    tmp42[8] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[8];
    tmp42[9] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[9];
    tmp42[10] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[10];
    tmp42[11] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[11];
    tmp42[12] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[12];
    tmp42[13] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[13];
    tmp42[14] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[14];
    tmp42[15] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[15];
    tmp42[16] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[16];
    tmp42[17] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[17];
    tmp42[18] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[18];
    tmp42[19] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[19];
    tmp42[20] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[20];
    tmp42[21] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[21];
    tmp42[22] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[22];
    tmp42[23] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[23];
    tmp42[24] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[24];
    tmp42[25] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[25];
    tmp42[26] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[26];
    tmp42[27] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[27];
    tmp42[28] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[28];
    tmp42[29] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[29];
    tmp42[30] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[30];
    tmp42[31] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[31];
    tmp42[32] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[32];
    tmp42[33] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[33];
    tmp42[34] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[34];
    tmp42[35] = s_Bitmain_S9_has_to_use_stratum_po_000841f8[35];
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cg_wlock(&info->update_lock,"driver-btm-soc.c","bitmain_soc_update",0x1e3e);
  _cg_rlock(&pool->data_lock,"driver-btm-soc.c","bitmain_soc_update",0x1e3f);
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
  _cg_runlock(&pool->data_lock,"driver-btm-soc.c","bitmain_soc_update",0x1e52);
  _cg_wunlock(&info->update_lock,"driver-btm-soc.c","bitmain_soc_update",0x1e53);
  free(buf);
  _mutex_unlock(&info->lock,"driver-btm-soc.c","bitmain_soc_update",0x1e55);
  return;
}

