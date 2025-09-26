
LZ4F_CDict * LZ4F_createCDict_advanced(LZ4F_CustomMem cmem,void *dictBuffer,size_t dictSize)

{
  undefined8 uVar1;
  LZ4F_CDict *cdict_00;
  void *pvVar2;
  LZ4_stream_t *pLVar3;
  LZ4_streamHC_t *pLVar4;
  LZ4F_AllocFunction p_Var15;
  LZ4F_AllocFunction p_Var16;
  LZ4F_AllocFunction p_Var17;
  LZ4F_AllocFunction p_Var18;
  LZ4F_FreeFunction p_Var5;
  LZ4F_CallocFunction p_Var19;
  LZ4F_CallocFunction p_Var20;
  LZ4F_CallocFunction p_Var21;
  LZ4F_CallocFunction p_Var22;
  LZ4F_FreeFunction p_Var6;
  LZ4F_FreeFunction p_Var7;
  LZ4F_FreeFunction p_Var8;
  LZ4F_FreeFunction p_Var9;
  LZ4F_CustomMem LVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  LZ4F_CustomMem cmem_local;
  LZ4F_CDict *cdict;
  char *dictStart;
  
  p_Var5 = cmem.customFree;
  dictStart = (char *)dictBuffer;
  uVar1 = cmem._0_8_;
  p_Var6 = p_Var5;
  uVar11 = CONCAT44(dictBuffer,p_Var6);
  p_Var15 = (LZ4F_AllocFunction)(int)uVar1;
  register0x00000028 = (LZ4F_CallocFunction)(int)((ulonglong)uVar1 >> 0x20);
  LVar10 = (LZ4F_CustomMem)CONCAT88(uVar11,uVar23);
  cdict_00 = (LZ4F_CDict *)LZ4F_malloc(0x1c,LVar10);
  if (cdict_00 == (LZ4F_CDict *)0x0) {
    cdict_00 = (LZ4F_CDict *)0x0;
  }
  else {
    (cdict_00->cmem).customAlloc = cmem.customAlloc;
    (cdict_00->cmem).customCalloc = cmem.customCalloc;
    (cdict_00->cmem).customFree = p_Var5;
    (cdict_00->cmem).opaqueState = cmem.opaqueState;
    if (0x10000 < dictSize) {
      dictStart = (char *)((dictSize - 0x10000) + (int)dictBuffer);
      dictSize = 0x10000;
    }
    p_Var7 = p_Var5;
    uVar12 = CONCAT44(dictBuffer,p_Var7);
    p_Var16 = (LZ4F_AllocFunction)(int)uVar1;
    register0x00000028 = (LZ4F_CallocFunction)(int)((ulonglong)uVar1 >> 0x20);
    LVar10 = (LZ4F_CustomMem)CONCAT88(uVar12,uVar24);
    pvVar2 = LZ4F_malloc(dictSize,LVar10);
    cdict_00->dictContent = pvVar2;
    p_Var8 = p_Var5;
    uVar13 = CONCAT44(dictBuffer,p_Var8);
    p_Var17 = (LZ4F_AllocFunction)(int)uVar1;
    register0x00000028 = (LZ4F_CallocFunction)(int)((ulonglong)uVar1 >> 0x20);
    LVar10 = (LZ4F_CustomMem)CONCAT88(uVar13,uVar25);
    pLVar3 = (LZ4_stream_t *)LZ4F_malloc(0x4020,LVar10);
    cdict_00->fastCtx = pLVar3;
    if (cdict_00->fastCtx != (LZ4_stream_t *)0x0) {
      LZ4_initStream(cdict_00->fastCtx,0x4020);
    }
    p_Var9 = p_Var5;
    uVar14 = CONCAT44(dictBuffer,p_Var9);
    p_Var18 = (LZ4F_AllocFunction)(int)uVar1;
    register0x00000028 = (LZ4F_CallocFunction)(int)((ulonglong)uVar1 >> 0x20);
    LVar10 = (LZ4F_CustomMem)CONCAT88(uVar14,uVar26);
    pLVar4 = (LZ4_streamHC_t *)LZ4F_malloc(0x40038,LVar10);
    cdict_00->HCCtx = pLVar4;
    if (cdict_00->HCCtx != (LZ4_streamHC_t *)0x0) {
      LZ4_initStream(cdict_00->HCCtx,0x40038);
    }
    if (((cdict_00->dictContent == (void *)0x0) || (cdict_00->fastCtx == (LZ4_stream_t *)0x0)) ||
       (cdict_00->HCCtx == (LZ4_streamHC_t *)0x0)) {
      LZ4F_freeCDict(cdict_00);
      cdict_00 = (LZ4F_CDict *)0x0;
    }
    else {
      memcpy(cdict_00->dictContent,dictStart,dictSize);
      LZ4_loadDict(cdict_00->fastCtx,(char *)cdict_00->dictContent,dictSize);
      LZ4_setCompressionLevel(cdict_00->HCCtx,9);
      LZ4_loadDictHC(cdict_00->HCCtx,(char *)cdict_00->dictContent,dictSize);
    }
  }
  return cdict_00;
}

