
_Bool test_nonce(work *work,uint nonce)

{
  undefined uVar1;
  int iVar2;
  bool bVar3;
  uint nonce_local;
  work *work_local;
  uint *hash_32;
  
  rebuild_nonce(work,nonce);
  iVar2 = *(int *)(work->hash + 0x1c);
  bVar3 = iVar2 != 0;
  if (bVar3) {
    iVar2 = 0;
  }
  uVar1 = (undefined)iVar2;
  if (!bVar3) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

