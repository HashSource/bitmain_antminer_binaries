
/* WARNING: Unknown calling convention */

void submit_nonce_2(work *work)

{
  work *work_00;
  
  work_00 = copy_work_noffset(work,0);
  submit_work_async(work_00);
  return;
}

