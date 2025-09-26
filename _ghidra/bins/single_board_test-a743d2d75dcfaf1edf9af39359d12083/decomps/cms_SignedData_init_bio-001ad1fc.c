
BIO * cms_SignedData_init_bio(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  BIO *append;
  int *piVar3;
  int *piVar4;
  int iVar5;
  BIO *a;
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_1);
  if (iVar1 == 0x16) {
    piVar4 = (int *)param_1[1];
    if (piVar4 == (int *)0x0) {
LAB_001ad33c:
      a = (BIO *)0x0;
    }
    else {
      if (*(int *)(piVar4[2] + 8) != 0) {
        for (iVar1 = 0; iVar2 = sk_num((_STACK *)piVar4[3]), iVar1 < iVar2; iVar1 = iVar1 + 1) {
          piVar3 = (int *)sk_value((_STACK *)piVar4[3],iVar1);
          iVar2 = *piVar3;
          if (iVar2 == 4) {
            if (*piVar4 < 5) {
              *piVar4 = 5;
            }
          }
          else if (iVar2 == 3) {
            if (*piVar4 < 4) {
              *piVar4 = 4;
            }
          }
          else if ((iVar2 == 2) && (*piVar4 < 3)) {
            *piVar4 = 3;
          }
        }
        iVar1 = 0;
        while( true ) {
          iVar2 = sk_num((_STACK *)piVar4[4]);
          iVar5 = iVar1 + 1;
          if (iVar2 <= iVar1) break;
          piVar3 = (int *)sk_value((_STACK *)piVar4[4],iVar1);
          iVar1 = iVar5;
          if ((*piVar3 == 1) && (*piVar4 < 5)) {
            *piVar4 = 5;
          }
        }
        iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)piVar4[2]);
        if ((iVar1 != 0x15) && (*piVar4 < 3)) {
          *piVar4 = 3;
        }
        for (iVar1 = 0; iVar2 = sk_num((_STACK *)piVar4[5]), iVar1 < iVar2; iVar1 = iVar1 + 1) {
          piVar3 = (int *)sk_value((_STACK *)piVar4[5],iVar1);
          if (*(int *)piVar3[1] == 1) {
            iVar2 = *piVar4;
            if (*piVar3 < 3) {
              *piVar3 = 3;
            }
            if (iVar2 < 3) {
              *piVar4 = 3;
            }
          }
          else if (*piVar3 < 1) {
            *piVar3 = 1;
          }
        }
        if (*piVar4 < 1) {
          *piVar4 = 1;
        }
      }
      a = (BIO *)0x0;
      for (iVar1 = 0; iVar2 = sk_num((_STACK *)piVar4[1]), iVar1 < iVar2; iVar1 = iVar1 + 1) {
        sk_value((_STACK *)piVar4[1],iVar1);
        append = (BIO *)cms_DigestAlgorithm_init_bio();
        if (append == (BIO *)0x0) {
          if (a != (BIO *)0x0) {
            BIO_free_all(a);
            return (BIO *)0x0;
          }
          goto LAB_001ad33c;
        }
        if (a != (BIO *)0x0) {
          BIO_push(a,append);
          append = a;
        }
        a = append;
      }
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x48);
    a = (BIO *)0x0;
  }
  return a;
}

