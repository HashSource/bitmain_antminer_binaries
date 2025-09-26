
LZ4F_dctx * LZ4F_createDecompressionContext_advanced(LZ4F_CustomMem customMem,uint version)

{
  LZ4F_dctx *pLVar1;
  LZ4F_AllocFunction p_Var4;
  LZ4F_CallocFunction p_Var5;
  LZ4F_FreeFunction p_Var2;
  LZ4F_CustomMem cmem;
  undefined8 uVar3;
  undefined8 uVar6;
  LZ4F_CustomMem customMem_local;
  LZ4F_dctx *dctx;
  
  p_Var2 = customMem.customFree;
  uVar3 = CONCAT44(version,p_Var2);
  p_Var4 = (LZ4F_AllocFunction)(int)customMem._0_8_;
  register0x00000028 = (LZ4F_CallocFunction)(int)((ulonglong)customMem._0_8_ >> 0x20);
  cmem = (LZ4F_CustomMem)CONCAT88(uVar3,uVar6);
  pLVar1 = (LZ4F_dctx *)LZ4F_calloc(0xe8,cmem);
  if (pLVar1 == (LZ4F_dctx *)0x0) {
    pLVar1 = (LZ4F_dctx *)0x0;
  }
  else {
    (pLVar1->cmem).customAlloc = customMem.customAlloc;
    (pLVar1->cmem).customCalloc = customMem.customCalloc;
    (pLVar1->cmem).customFree = customMem.customFree;
    (pLVar1->cmem).opaqueState = customMem.opaqueState;
    pLVar1->version = version;
  }
  return pLVar1;
}

