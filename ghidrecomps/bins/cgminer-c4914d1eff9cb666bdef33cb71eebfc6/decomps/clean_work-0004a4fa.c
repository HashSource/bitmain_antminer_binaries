
void clean_work(work *work)

{
  work *work_local;
  
  free(work->job_id);
  free(work->ntime);
  free(work->coinbase);
  free(work->nonce1);
  memset(work,0,0x1c0);
  return;
}

