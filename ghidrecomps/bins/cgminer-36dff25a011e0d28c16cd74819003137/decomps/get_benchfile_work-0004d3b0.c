
void get_benchfile_work(work *work)

{
  work *work_local;
  
  benchfile_get_work(work);
  work->mandatory = true;
  work->pool = *pools;
  cgtime(&work->tv_getwork);
  copy_time(&work->tv_getwork_reply,&work->tv_getwork);
  work->getwork_mode = 'B';
  calc_diff(work,0.0);
  return;
}

