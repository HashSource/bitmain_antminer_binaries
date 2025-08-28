
/* WARNING: Unknown calling convention */

_Bool savelog_nonce(work *work,uint nonce)

{
  undefined1 extraout_r0;
  undefined1 extraout_r0_00;
  undefined1 uVar1;
  
  *(uint *)(work->data + 0x4c) = nonce;
  regen_hash(work);
  uVar1 = extraout_r0;
  if (*(int *)(work->hash + 0x1c) == 0) {
    cg_savelogwork_uint32(work,nonce);
    uVar1 = extraout_r0_00;
  }
  return (_Bool)uVar1;
}

