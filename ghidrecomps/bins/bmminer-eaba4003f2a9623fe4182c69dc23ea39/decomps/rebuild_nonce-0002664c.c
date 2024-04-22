
void rebuild_nonce(work *work,uint nonce)

{
  uint nonce_local;
  work *work_local;
  uint *work_nonce;
  
  *(uint *)(work->data + 0x4c) = nonce;
  regen_hash(work);
  return;
}

