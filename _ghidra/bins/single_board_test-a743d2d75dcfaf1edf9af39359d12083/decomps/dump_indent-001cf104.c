
/* WARNING: Unknown calling convention */

int dump_indent(size_t flags,int depth,int space,json_dump_callback_t dump,void *data)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  
  if ((flags & 0x1f) == 0) {
    if ((space != 0) && (-1 < (int)(flags << 0x1a))) {
      iVar1 = (*dump)(" ",1,data);
      return iVar1;
    }
  }
  else {
    uVar2 = (flags & 0x1f) * depth;
    iVar1 = (*dump)("\n",1,data);
    if (iVar1 != 0) {
      return -1;
    }
    for (; uVar2 != 0; uVar2 = uVar2 - sVar3) {
      sVar3 = uVar2;
      if (0x1f < uVar2) {
        sVar3 = 0x20;
      }
      iVar1 = (*dump)("                                ",sVar3,data);
      if (iVar1 != 0) {
        return -1;
      }
    }
  }
  return 0;
}

