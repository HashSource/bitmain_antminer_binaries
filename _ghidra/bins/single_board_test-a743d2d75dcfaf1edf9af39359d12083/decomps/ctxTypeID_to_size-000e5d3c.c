
int ctxTypeID_to_size(int ctxTypeID)

{
  int iVar1;
  int ctxTypeID_local;
  
  if (ctxTypeID == 1) {
    iVar1 = LZ4_sizeofState();
  }
  else if (ctxTypeID == 2) {
    iVar1 = LZ4_sizeofStateHC();
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

