
void LZ4F_free(void *p,LZ4F_CustomMem cmem)

{
  void *p_local;
  
  cmem.opaqueState = cmem.opaqueState;
  if (cmem.customFree == (LZ4F_FreeFunction)0x0) {
    free(p);
  }
  else {
    (*cmem.customFree)(cmem.opaqueState,p);
  }
  return;
}

