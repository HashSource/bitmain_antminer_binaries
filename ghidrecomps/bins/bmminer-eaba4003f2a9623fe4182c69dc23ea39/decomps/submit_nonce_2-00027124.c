
void submit_nonce_2(work *work)

{
  work *work_00;
  work *work_local;
  work *work_out;
  
  work_00 = copy_work_noffset(work,0);
  submit_work_async(work_00);
  return;
}

