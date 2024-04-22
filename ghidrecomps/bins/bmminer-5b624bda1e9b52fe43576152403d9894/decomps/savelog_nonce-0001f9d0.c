
/* WARNING: Unknown calling convention */

_Bool savelog_nonce(work *work,uint nonce)

{
  undefined uVar1;
  work *pwVar2;
  
  *(uint *)(work->data + 0x4c) = nonce;
  pwVar2 = work;
  regen_hash(work);
  uVar1 = SUB41(pwVar2,0);
  if (*(int *)(work->hash + 0x1c) == 0) {
    cg_savelogwork_uint32(work,nonce);
    uVar1 = SUB41(work,0);
  }
  return (_Bool)uVar1;
}

