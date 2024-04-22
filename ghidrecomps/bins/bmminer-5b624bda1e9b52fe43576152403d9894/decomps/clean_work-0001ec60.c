
/* WARNING: Unknown calling convention */

void clean_work(work *work)

{
  free(work->job_id);
  free(work->ntime);
  free(work->coinbase);
  free(work->nonce1);
                    /* WARNING: Could not recover jumptable at 0x0000a1c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f1d8)(work,0,0x1c0);
  return;
}

