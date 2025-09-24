
undefined4 obj_trust(int param_1,X509 *param_2,uint param_3)

{
  ASIdentifierChoice **ppAVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  ASIdentifierChoice *pAVar4;
  int iVar5;
  uint uVar6;
  ASIdentifiers_st *pAVar7;
  
  pAVar7 = param_2[1].rfc3779_asid;
  if (pAVar7 != (ASIdentifiers_st *)0x0) {
    ppAVar1 = pAVar7->rdi;
    if (ppAVar1 == (ASIdentifierChoice **)0x0) {
      pAVar4 = pAVar7->asnum;
      if (pAVar4 != (ASIdentifierChoice *)0x0) {
        if ((int)(param_3 << 0x1b) < 0) goto LAB_001c69fc;
LAB_001c6976:
        iVar5 = 0;
        while( true ) {
          iVar2 = OPENSSL_sk_num(pAVar4);
          if (iVar2 <= iVar5) {
            return 2;
          }
          pAVar3 = (ASN1_OBJECT *)OPENSSL_sk_value(pAVar7->asnum,iVar5);
          iVar2 = OBJ_obj2nid(pAVar3);
          if (param_1 == iVar2) break;
          pAVar4 = pAVar7->asnum;
          iVar5 = iVar5 + 1;
        }
        return 1;
      }
    }
    else {
      uVar6 = param_3 & 0x10;
      if ((param_3 & 0x10) == 0) {
        while( true ) {
          iVar5 = OPENSSL_sk_num(ppAVar1);
          if (iVar5 <= (int)uVar6) break;
          pAVar3 = (ASN1_OBJECT *)OPENSSL_sk_value(pAVar7->rdi,uVar6);
          iVar5 = OBJ_obj2nid(pAVar3);
          if (param_1 == iVar5) {
            return 2;
          }
          ppAVar1 = pAVar7->rdi;
          uVar6 = uVar6 + 1;
        }
        pAVar4 = pAVar7->asnum;
        if (pAVar4 != (ASIdentifierChoice *)0x0) goto LAB_001c6976;
      }
      else {
        iVar5 = 0;
        while( true ) {
          iVar2 = OPENSSL_sk_num(ppAVar1);
          if (iVar2 <= iVar5) break;
          pAVar3 = (ASN1_OBJECT *)OPENSSL_sk_value(pAVar7->rdi,iVar5);
          iVar2 = OBJ_obj2nid(pAVar3);
          if (iVar2 == param_1) {
            return 2;
          }
          if (iVar2 == 0x38e) {
            return 2;
          }
          ppAVar1 = pAVar7->rdi;
          iVar5 = iVar5 + 1;
        }
        pAVar4 = pAVar7->asnum;
        if (pAVar4 != (ASIdentifierChoice *)0x0) {
LAB_001c69fc:
          iVar5 = 0;
          while( true ) {
            iVar2 = OPENSSL_sk_num(pAVar4);
            if (iVar2 <= iVar5) {
              return 2;
            }
            pAVar3 = (ASN1_OBJECT *)OPENSSL_sk_value(pAVar7->asnum,iVar5);
            iVar2 = OBJ_obj2nid(pAVar3);
            if (param_1 == iVar2) break;
            if (iVar2 == 0x38e) {
              return 1;
            }
            pAVar4 = pAVar7->asnum;
            iVar5 = iVar5 + 1;
          }
          return 1;
        }
      }
    }
  }
  if (((((int)(param_3 << 0x1c) < 0) && (iVar5 = X509_check_purpose(param_2,-1,0), iVar5 == 1)) &&
      (-1 < (int)(param_3 << 0x1d))) && (param_2[1].references << 0x12 < 0)) {
    return 1;
  }
  return 3;
}

