
undefined4 obj_trust(int param_1,int param_2)

{
  _STACK *p_Var1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 100);
  if (piVar5 != (int *)0x0) {
    p_Var1 = (_STACK *)piVar5[1];
    if (p_Var1 != (_STACK *)0x0) {
      iVar4 = 0;
      while( true ) {
        iVar2 = sk_num(p_Var1);
        if (iVar2 <= iVar4) break;
        pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)piVar5[1],iVar4);
        iVar2 = OBJ_obj2nid(pAVar3);
        if (iVar2 == param_1) {
          return 2;
        }
        p_Var1 = (_STACK *)piVar5[1];
        iVar4 = iVar4 + 1;
      }
    }
    p_Var1 = (_STACK *)*piVar5;
    if (p_Var1 != (_STACK *)0x0) {
      iVar4 = 0;
      while( true ) {
        iVar2 = sk_num(p_Var1);
        if (iVar2 <= iVar4) break;
        pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)*piVar5,iVar4);
        iVar2 = OBJ_obj2nid(pAVar3);
        if (iVar2 == param_1) {
          return 1;
        }
        p_Var1 = (_STACK *)*piVar5;
        iVar4 = iVar4 + 1;
      }
    }
  }
  return 3;
}

