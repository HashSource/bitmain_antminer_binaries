
int ASN1_object_size(int constructed,int length,int tag)

{
  int iVar1;
  int iVar2;
  
  if (-1 < length) {
    iVar1 = 1;
    iVar2 = iVar1;
    if (0x1e < tag) {
      do {
        iVar2 = iVar1 + 1;
        if (tag >> 7 == 0) break;
        tag = tag >> 0xe;
        iVar1 = iVar1 + 2;
        iVar2 = iVar1;
      } while (tag != 0);
    }
    if (constructed == 2) {
      iVar2 = iVar2 + 3;
    }
    else {
      iVar2 = iVar2 + 1;
      iVar1 = length;
      if (0x7f < length) {
        do {
          iVar1 = iVar1 >> 8;
          iVar2 = iVar2 + 1;
        } while (iVar1 != 0);
      }
    }
    if (iVar2 < 0x7fffffff - length) {
      return iVar2 + length;
    }
  }
  return -1;
}

