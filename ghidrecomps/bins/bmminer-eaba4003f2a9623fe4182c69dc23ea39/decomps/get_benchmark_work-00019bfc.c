
void get_benchmark_work(work *work)

{
  work *work_local;
  
  *(undefined4 *)&work->work_difficulty = 0;
  *(undefined4 *)((int)&work->work_difficulty + 4) = 0x40400000;
  _cg_memcpy(work->target,bench_target,0x20,"cgminer.c","get_benchmark_work",0x104c);
  work->drv_rolllimit = 0;
  work->mandatory = true;
  work->pool = *pools;
  cgtime(&work->tv_getwork);
  copy_time(&work->tv_getwork_reply,&work->tv_getwork);
  work->getwork_mode = 'B';
  return;
}

