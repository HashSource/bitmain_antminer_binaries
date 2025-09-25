
void * LZ4F_malloc(size_t s,LZ4F_CustomMem cmem)

{
  size_t s_local;
  
  cmem.opaqueState = cmem.opaqueState;
  if (cmem.customAlloc == (LZ4F_AllocFunction)0x0) {
    cmem.customFree = (LZ4F_FreeFunction)malloc(s);
  }
  else {
    cmem.customFree = (LZ4F_FreeFunction)(*cmem.customAlloc)(cmem.opaqueState,s);
  }
  return cmem.customFree;
}

