
_Bool savelog_nonce(work *work,uint nonce)

{
  undefined uVar1;
  uint nonce_local;
  work *work_local;
  
  uVar1 = test_nonce(work,nonce);
  if ((bool)uVar1) {
    cg_savelogwork_uint32(work,nonce);
  }
  return (_Bool)uVar1;
}

