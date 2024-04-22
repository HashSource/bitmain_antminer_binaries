
_Bool test_nonce(work *work,uint32_t nonce)

{
  undefined uVar1;
  int iVar2;
  bool bVar3;
  uint32_t nonce_local;
  work *work_local;
  uint32_t *hash_32;
  
  rebuild_nonce(work,nonce);
  iVar2 = *(int *)(work->hash + 0x1c);
  bVar3 = iVar2 == 0;
  if (bVar3) {
    iVar2 = 1;
  }
  uVar1 = (undefined)iVar2;
  if (!bVar3) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

