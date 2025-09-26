
void * upload_repaire_data_func(void *arg)

{
  void *arg_local;
  repaire_info_t m_repaire_info;
  
  do {
    memset(&m_repaire_info,0,0x88);
    sem_wait((sem_t *)&sem_upload);
    pthread_mutex_lock((pthread_mutex_t *)&sync_mutex);
    memcpy(&m_repaire_info,&g_repaire_info,0x88);
    pthread_mutex_unlock((pthread_mutex_t *)&sync_mutex);
    sleep(1);
    upload_res = upload_data_to_server(&m_repaire_info);
    sem_post((sem_t *)&sem_upload_over);
  } while( true );
}

