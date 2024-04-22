
int blake2b_is_lastblock(blake2b_state *S)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  blake2b_state *S_local;
  
  uVar2 = *(uint *)S->f | *(uint *)((int)S->f + 4);
  bVar3 = uVar2 != 0;
  if (bVar3) {
    uVar2 = 1;
  }
  bVar1 = (byte)uVar2;
  if (!bVar3) {
    bVar1 = 0;
  }
  return (uint)bVar1;
}

