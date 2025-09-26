
LZ4F_errorCode_t LZ4F_freeDecompressionContext(LZ4F_dctx *dctx)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  LZ4F_AllocFunction p_Var14;
  LZ4F_AllocFunction p_Var15;
  LZ4F_AllocFunction p_Var16;
  LZ4F_CallocFunction p_Var17;
  LZ4F_CallocFunction p_Var18;
  LZ4F_CallocFunction p_Var19;
  LZ4F_FreeFunction p_Var7;
  LZ4F_FreeFunction p_Var8;
  LZ4F_FreeFunction p_Var9;
  LZ4F_CustomMem LVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  void *in_stack_00000000;
  LZ4F_dctx *dctx_local;
  LZ4F_errorCode_t result;
  
  result = 0;
  if (dctx != (LZ4F_dctx *)0x0) {
    result = dctx->dStage;
    uVar1 = (dctx->cmem).customAlloc;
    uVar2 = (dctx->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar2;
    p_Var14 = (LZ4F_AllocFunction)uVar1;
    p_Var7 = (dctx->cmem).customFree;
    uVar11 = CONCAT44(in_stack_00000000,p_Var7);
    LVar10 = (LZ4F_CustomMem)CONCAT88(uVar11,uVar20);
    LZ4F_free(dctx->tmpIn,LVar10);
    uVar3 = (dctx->cmem).customAlloc;
    uVar4 = (dctx->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar4;
    p_Var15 = (LZ4F_AllocFunction)uVar3;
    p_Var8 = (dctx->cmem).customFree;
    in_stack_00000000 = in_stack_00000000;
    uVar12 = CONCAT44(in_stack_00000000,p_Var8);
    LVar10 = (LZ4F_CustomMem)CONCAT88(uVar12,uVar21);
    LZ4F_free(dctx->tmpOutBuffer,LVar10);
    uVar5 = (dctx->cmem).customAlloc;
    uVar6 = (dctx->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar6;
    p_Var16 = (LZ4F_AllocFunction)uVar5;
    p_Var9 = (dctx->cmem).customFree;
    uVar13 = CONCAT44(in_stack_00000000,p_Var9);
    LVar10 = (LZ4F_CustomMem)CONCAT88(uVar13,uVar22);
    LZ4F_free(dctx,LVar10);
  }
  return result;
}

