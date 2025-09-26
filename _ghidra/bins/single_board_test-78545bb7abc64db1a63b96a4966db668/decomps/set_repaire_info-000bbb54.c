
void set_repaire_info(repaire_info_t *p_repaire)

{
  repaire_info_t *p_repaire_local;
  
  if (p_repaire != (repaire_info_t *)0x0) {
    pthread_mutex_lock((pthread_mutex_t *)&sync_mutex);
    memcpy(&g_repaire_info,p_repaire,0x88);
    pthread_mutex_unlock((pthread_mutex_t *)&sync_mutex);
  }
  return;
}

