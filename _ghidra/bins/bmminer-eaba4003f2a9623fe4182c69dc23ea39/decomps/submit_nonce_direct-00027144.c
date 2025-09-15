
_Bool submit_nonce_direct(thr_info *thr,work *work,uint nonce)

{
  work *work_00;
  uint nonce_local;
  work *work_local;
  thr_info *thr_local;
  work *work_out;
  uint *work_nonce;
  
  *(uint *)(work->data + 0x4c) = nonce;
  work_00 = copy_work_noffset(work,0);
  submit_work_async(work_00);
  return true;
}

