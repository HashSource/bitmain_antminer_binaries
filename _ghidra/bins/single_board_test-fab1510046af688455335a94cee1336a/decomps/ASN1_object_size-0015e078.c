
int ASN1_object_size(int constructed,int length,int tag)

{
  int iVar1;
  int iVar2;
  
  iVar2 = length + 1;
  iVar1 = iVar2;
  if (0x1e < tag) {
    do {
      iVar1 = iVar2 + 1;
      if (tag >> 7 == 0) break;
      tag = tag >> 0xe;
      iVar2 = iVar2 + 2;
      iVar1 = iVar2;
    } while (tag != 0);
  }
  if (constructed == 2) {
    return iVar1 + 3;
  }
  iVar1 = iVar1 + 1;
  if (0x7f < length) {
    do {
      length = length >> 8;
      iVar1 = iVar1 + 1;
    } while (length != 0);
  }
  return iVar1;
}

