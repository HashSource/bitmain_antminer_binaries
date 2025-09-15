
/* WARNING: Unknown calling convention */

int dump_indent(size_t flags,int depth,int space,json_dump_callback_t dump,void *data)

{
  int iVar1;
  int iVar2;
  
  if ((flags & 0x1f) == 0) {
    if ((space != 0) && (-1 < (int)(flags << 0x1a))) {
      iVar2 = (*dump)(" ",1,data);
      return iVar2;
    }
  }
  else {
    iVar2 = (*dump)("\n",1,data);
    if (iVar2 != 0) {
      return -1;
    }
    if (0 < depth) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        iVar1 = (*dump)("                                ",flags & 0x1f,data);
        if (iVar1 != 0) {
          return -1;
        }
      } while (iVar2 != depth);
    }
  }
  return 0;
}

