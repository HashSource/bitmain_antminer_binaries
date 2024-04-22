
/* WARNING: Unknown calling convention */

void get_benchfile_work(work *work)

{
  pool **pppVar1;
  double in_stack_00000000;
  
  benchfile_get_work(work);
  pppVar1 = pools;
  work->mandatory = true;
  work->pool = *pppVar1;
  cgtime(&work->tv_getwork);
  copy_time(&work->tv_getwork_reply,&work->tv_getwork);
  work->getwork_mode = 'B';
  calc_diff(work,in_stack_00000000);
  return;
}

