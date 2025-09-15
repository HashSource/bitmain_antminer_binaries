
void rebuild_nonce(work *work,uint32_t nonce)

{
  __uint32_t _Var1;
  uint32_t nonce_local;
  work *work_local;
  uint32_t *work_nonce;
  
  _Var1 = __uint32_identity(nonce);
  *(__uint32_t *)(work->data + 0x4c) = _Var1;
  regen_hash(work);
  return;
}

