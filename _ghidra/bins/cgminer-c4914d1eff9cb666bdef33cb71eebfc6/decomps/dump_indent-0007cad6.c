
int dump_indent(size_t flags,int depth,int space,json_dump_callback_t dump,void *data)

{
  int iVar1;
  uint uVar2;
  json_dump_callback_t dump_local;
  int space_local;
  int depth_local;
  size_t flags_local;
  int cur_n;
  uint ws_count;
  uint n_spaces;
  
  if ((flags & 0x1f) == 0) {
    if ((space != 0) && ((flags & 0x20) == 0)) {
      iVar1 = (*dump)(" ",1,data);
      return iVar1;
    }
  }
  else {
    n_spaces = depth * (flags & 0x1f);
    iVar1 = (*dump)("\n",1,data);
    if (iVar1 != 0) {
      return -1;
    }
    for (; n_spaces != 0; n_spaces = n_spaces - uVar2) {
      uVar2 = n_spaces;
      if (0x1f < n_spaces) {
        uVar2 = 0x20;
      }
      iVar1 = (*dump)("                                ",uVar2,data);
      if (iVar1 != 0) {
        return -1;
      }
    }
  }
  return 0;
}

