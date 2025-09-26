
void save_nonce(work_format *work,uint32_t work_id,uint32_t which_asic,uint32_t which_midstate,
               uint32_t which_big_core,uint32_t nonce,uint32_t diff)

{
  char *__ptr;
  uint32_t which_midstate_local;
  uint32_t which_asic_local;
  uint32_t work_id_local;
  work_format *work_local;
  char type [16];
  uchar data_tmp [32];
  uchar midstate_tmp [32];
  char szmsg [1024];
  char *sznonce;
  char *szdata;
  char *szmidstate;
  
  memset(szmsg,0,0x400);
  memset(midstate_tmp,0,0x20);
  memset(data_tmp,0,0x20);
  nonce = nonce << 0x18 | nonce >> 0x18 | (nonce & 0xff0000) >> 8 | (nonce & 0xff00) << 8;
  __ptr = bin2hex((uchar *)&nonce,4);
  if (__ptr != (char *)0x0) {
    free(__ptr);
  }
  pthread_mutex_lock((pthread_mutex_t *)&g_map_mutex);
  if (g_noncemap[work_id].count == 0) {
    memcpy(g_noncemap[work_id].midstate,work->midstate + which_midstate,0x20);
    memcpy(g_noncemap[work_id].data,work->data,0xc);
    g_noncemap[work_id].nonce = nonce;
    g_noncemap[work_id].coreid = which_big_core;
    g_noncemap[work_id].asic = which_asic;
    g_noncemap[work_id].count = 1;
  }
  else if (g_noncemap[work_id].nonce != nonce) {
    g_noncemap[work_id].count = g_noncemap[work_id].count + 1;
  }
  g_id = work_id;
  pthread_mutex_unlock((pthread_mutex_t *)&g_map_mutex);
  return;
}

