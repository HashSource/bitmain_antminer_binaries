
int LZ4HC_protectDictEnd(U32 dictLimit,U32 matchIndex)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  U32 matchIndex_local;
  U32 dictLimit_local;
  
  uVar2 = (dictLimit - matchIndex) - 1;
  uVar3 = uVar2;
  if (2 < uVar2) {
    uVar3 = 1;
  }
  bVar1 = (byte)uVar3;
  if (uVar2 < 3) {
    bVar1 = 0;
  }
  return (uint)bVar1;
}

