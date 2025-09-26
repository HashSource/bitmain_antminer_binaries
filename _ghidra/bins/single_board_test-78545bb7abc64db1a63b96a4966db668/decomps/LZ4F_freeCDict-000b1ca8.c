
void LZ4F_freeCDict(LZ4F_CDict *cdict)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  LZ4F_AllocFunction p_Var18;
  LZ4F_AllocFunction p_Var19;
  LZ4F_AllocFunction p_Var20;
  LZ4F_AllocFunction p_Var21;
  LZ4F_CallocFunction p_Var22;
  LZ4F_CallocFunction p_Var23;
  LZ4F_CallocFunction p_Var24;
  LZ4F_CallocFunction p_Var25;
  LZ4F_FreeFunction p_Var9;
  LZ4F_FreeFunction p_Var10;
  LZ4F_FreeFunction p_Var11;
  LZ4F_FreeFunction p_Var12;
  LZ4F_CustomMem LVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  void *in_stack_00000000;
  LZ4F_CDict *cdict_local;
  
  if (cdict != (LZ4F_CDict *)0x0) {
    uVar1 = (cdict->cmem).customAlloc;
    uVar2 = (cdict->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar2;
    p_Var18 = (LZ4F_AllocFunction)uVar1;
    p_Var9 = (cdict->cmem).customFree;
    uVar14 = CONCAT44(in_stack_00000000,p_Var9);
    LVar13 = (LZ4F_CustomMem)CONCAT88(uVar14,uVar26);
    LZ4F_free(cdict->dictContent,LVar13);
    uVar3 = (cdict->cmem).customAlloc;
    uVar4 = (cdict->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar4;
    p_Var19 = (LZ4F_AllocFunction)uVar3;
    p_Var10 = (cdict->cmem).customFree;
    uVar15 = CONCAT44(in_stack_00000000,p_Var10);
    LVar13 = (LZ4F_CustomMem)CONCAT88(uVar15,uVar27);
    LZ4F_free(cdict->fastCtx,LVar13);
    uVar5 = (cdict->cmem).customAlloc;
    uVar6 = (cdict->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar6;
    p_Var20 = (LZ4F_AllocFunction)uVar5;
    p_Var11 = (cdict->cmem).customFree;
    uVar16 = CONCAT44(in_stack_00000000,p_Var11);
    LVar13 = (LZ4F_CustomMem)CONCAT88(uVar16,uVar28);
    LZ4F_free(cdict->HCCtx,LVar13);
    uVar7 = (cdict->cmem).customAlloc;
    uVar8 = (cdict->cmem).customCalloc;
    register0x00000028 = (LZ4F_CallocFunction)uVar8;
    p_Var21 = (LZ4F_AllocFunction)uVar7;
    p_Var12 = (cdict->cmem).customFree;
    uVar17 = CONCAT44(in_stack_00000000,p_Var12);
    LVar13 = (LZ4F_CustomMem)CONCAT88(uVar17,uVar29);
    LZ4F_free(cdict,LVar13);
  }
  return;
}

