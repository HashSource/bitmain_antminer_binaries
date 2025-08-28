
_Bool savelog_nonce(work *work,uint nonce)

{
  undefined1 uVar1;
  undefined1 extraout_r3;
  uint nonce_local;
  work *work_local;
  
  uVar1 = test_nonce(work,nonce);
  if ((bool)uVar1) {
    cg_savelogwork_uint32(work,nonce);
    uVar1 = extraout_r3;
  }
  return (_Bool)uVar1;
}

