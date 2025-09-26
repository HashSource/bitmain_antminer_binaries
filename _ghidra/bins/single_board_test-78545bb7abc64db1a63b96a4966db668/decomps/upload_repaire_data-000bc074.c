
int upload_repaire_data(repaire_info_t *p_repaire)

{
  repaire_info_t *p_repaire_local;
  
  upload_res = 0;
  set_repaire_info(p_repaire);
  sem_post((sem_t *)&sem_upload);
  sem_wait((sem_t *)&sem_upload_over);
  return upload_res;
}

