
int X509_check_trust(X509 *x,int id,int flags)

{
  _STACK *p_Var1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  int *piVar7;
  int local_30 [7];
  
  if (id == -1) {
    return 1;
  }
  if (id == 0) {
    piVar7 = *(int **)(x->sha1_hash + 0xc);
    if (piVar7 != (int *)0x0) {
      p_Var1 = (_STACK *)piVar7[1];
      if (p_Var1 != (_STACK *)0x0) {
        iVar4 = 0;
        while( true ) {
          iVar2 = sk_num(p_Var1);
          if (iVar2 <= iVar4) break;
          pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)piVar7[1],iVar4);
          iVar2 = OBJ_obj2nid(pAVar3);
          if (iVar2 == 0x38e) {
            return 2;
          }
          p_Var1 = (_STACK *)piVar7[1];
          iVar4 = iVar4 + 1;
        }
      }
      p_Var1 = (_STACK *)*piVar7;
      if (p_Var1 != (_STACK *)0x0) {
        iVar4 = 0;
        while( true ) {
          iVar2 = sk_num(p_Var1);
          if (iVar2 <= iVar4) break;
          pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)*piVar7,iVar4);
          iVar2 = OBJ_obj2nid(pAVar3);
          if (iVar2 == 0x38e) {
            return 1;
          }
          p_Var1 = (_STACK *)*piVar7;
          iVar4 = iVar4 + 1;
        }
      }
    }
    X509_check_purpose(x,-1,0);
    if ((x->ex_flags & 0x2000) == 0) {
      return 3;
    }
    return 1;
  }
  uVar6 = id - 1;
  if (7 < uVar6) {
    local_30[0] = id;
    if (((trtable == (_STACK *)0x0) || (iVar4 = sk_find(trtable,local_30), iVar4 == -1)) ||
       (uVar6 = iVar4 + 8, iVar4 == -9)) {
      iVar4 = (*default_trust)(id,x,flags);
      return iVar4;
    }
    if ((int)uVar6 < 0) {
      puVar5 = (undefined1 *)0x0;
      goto LAB_001631bc;
    }
  }
  if ((int)uVar6 < 8) {
    puVar5 = trstandard + uVar6 * 0x18;
  }
  else {
    puVar5 = (undefined1 *)sk_value(trtable,uVar6 - 8);
  }
LAB_001631bc:
  iVar4 = (**(code **)(puVar5 + 8))(puVar5,x,flags);
  return iVar4;
}

