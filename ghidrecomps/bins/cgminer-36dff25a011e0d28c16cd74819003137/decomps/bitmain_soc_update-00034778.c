
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
    tmp42[0] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[0];
    tmp42[1] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[1];
    tmp42[2] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[2];
    tmp42[3] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[3];
    tmp42[4] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[4];
    tmp42[5] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[5];
    tmp42[6] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[6];
    tmp42[7] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[7];
    tmp42[8] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[8];
    tmp42[9] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[9];
    tmp42[10] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[10];
    tmp42[11] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[11];
    tmp42[12] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[12];
    tmp42[13] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[13];
    tmp42[14] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[14];
    tmp42[15] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[15];
    tmp42[16] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[16];
    tmp42[17] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[17];
    tmp42[18] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[18];
    tmp42[19] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[19];
    tmp42[20] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[20];
    tmp42[21] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[21];
    tmp42[22] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[22];
    tmp42[23] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[23];
    tmp42[24] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[24];
    tmp42[25] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[25];
    tmp42[26] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[26];
    tmp42[27] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[27];
    tmp42[28] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[28];
    tmp42[29] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[29];
    tmp42[30] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[30];
    tmp42[31] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[31];
    tmp42[32] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[32];
    tmp42[33] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[33];
    tmp42[34] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[34];
    tmp42[35] = s_Bitmain_S9_has_to_use_stratum_po_0009d9e0[35];
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

