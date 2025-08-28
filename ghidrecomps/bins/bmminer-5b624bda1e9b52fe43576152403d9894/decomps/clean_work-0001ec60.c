
/* WARNING: Unknown calling convention */

void clean_work(work *work)

{
  undefined4 extraout_r3;
  undefined4 unaff_lr;
  
  free(work->job_id);
  free(work->ntime);
  free(work->coinbase);
  free(work->nonce1);
  (*(code *)(undefined *)0x0)(work,0,0x1c0,extraout_r3,unaff_lr);
  return;
}

