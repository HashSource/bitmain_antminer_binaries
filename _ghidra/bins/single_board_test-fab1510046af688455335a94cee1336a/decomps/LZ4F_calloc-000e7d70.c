
void * LZ4F_calloc(size_t s,LZ4F_CustomMem cmem)

{
  size_t s_local;
  void *p;
  
  cmem.opaqueState = cmem.opaqueState;
  if (cmem.customCalloc == (LZ4F_CallocFunction)0x0) {
    if (cmem.customAlloc == (LZ4F_AllocFunction)0x0) {
      cmem.customFree = (LZ4F_FreeFunction)calloc(1,s);
    }
    else {
      cmem.customFree = (LZ4F_FreeFunction)(*cmem.customAlloc)(cmem.opaqueState,s);
      if (cmem.customFree != (LZ4F_FreeFunction)0x0) {
        memset(cmem.customFree,0,s);
      }
    }
  }
  else {
    cmem.customFree = (LZ4F_FreeFunction)(*cmem.customCalloc)(cmem.opaqueState,s);
  }
  return cmem.customFree;
}

