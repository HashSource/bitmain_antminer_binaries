
/* WARNING: Unknown calling convention */

void get_benchmark_work(work *work)

{
  char *func;
  pool **pppVar1;
  
  func = DAT_0001dc8c;
  work->work_difficulty = 32.0;
  _cg_memcpy(work->target,DAT_0001dc90,0x20,"cgminer.c",func,0x1045);
  pppVar1 = pools;
  work->drv_rolllimit = 0;
  work->mandatory = true;
  work->pool = *pppVar1;
  cgtime(&work->tv_getwork);
  copy_time(&work->tv_getwork_reply,&work->tv_getwork);
  work->getwork_mode = 'B';
  return;
}

