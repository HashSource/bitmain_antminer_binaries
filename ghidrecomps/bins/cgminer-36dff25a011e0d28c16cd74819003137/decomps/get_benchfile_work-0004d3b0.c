
/* WARNING: Variable defined which should be unmapped: work-local */

void get_benchfile_work(work *work)

{
  undefined4 uStack_10;
  work *work_local;
  
  benchfile_get_work(work);
  work->mandatory = true;
  work->pool = *pools;
  cgtime(&work->tv_getwork);
  copy_time(&work->tv_getwork_reply,&work->tv_getwork);
  work->getwork_mode = 'B';
  calc_diff(work,(double)CONCAT44(work,uStack_10));
  return;
}

