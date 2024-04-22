
BIO * cms_SignedData_init_bio(ASN1_OBJECT **param_1)

{
  int iVar1;
  int iVar2;
  BIO *append;
  int *piVar3;
  char *pcVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  BIO *a;
  
  iVar1 = OBJ_obj2nid(*param_1);
  if (iVar1 == 0x16) {
    pAVar5 = param_1[1];
    if (pAVar5 == (ASN1_OBJECT *)0x0) {
LAB_00110c68:
      a = (BIO *)0x0;
    }
    else {
      if (*(int *)(pAVar5->nid + 8) != 0) {
        for (iVar1 = 0; iVar2 = sk_num((_STACK *)pAVar5->length), iVar1 < iVar2; iVar1 = iVar1 + 1)
        {
          piVar3 = (int *)sk_value((_STACK *)pAVar5->length,iVar1);
          iVar2 = *piVar3;
          if (iVar2 == 4) {
            if ((int)pAVar5->sn < 5) {
              pAVar5->sn = (char *)0x5;
            }
          }
          else if (iVar2 == 3) {
            if ((int)pAVar5->sn < 4) {
              pAVar5->sn = (char *)0x4;
            }
          }
          else if ((iVar2 == 2) && ((int)pAVar5->sn < 3)) {
            pAVar5->sn = (char *)0x3;
          }
        }
        iVar1 = 0;
        while( true ) {
          iVar2 = sk_num((_STACK *)pAVar5->data);
          iVar6 = iVar1 + 1;
          if (iVar2 <= iVar1) break;
          piVar3 = (int *)sk_value((_STACK *)pAVar5->data,iVar1);
          iVar1 = iVar6;
          if ((*piVar3 == 1) && ((int)pAVar5->sn < 5)) {
            pAVar5->sn = (char *)0x5;
          }
        }
        iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)pAVar5->nid);
        if ((iVar1 != 0x15) && ((int)pAVar5->sn < 3)) {
          pAVar5->sn = (char *)0x3;
        }
        for (iVar1 = 0; iVar2 = sk_num((_STACK *)pAVar5->flags), iVar1 < iVar2; iVar1 = iVar1 + 1) {
          piVar3 = (int *)sk_value((_STACK *)pAVar5->flags,iVar1);
          if (*(int *)piVar3[1] == 1) {
            pcVar4 = pAVar5->sn;
            if (*piVar3 < 3) {
              *piVar3 = 3;
            }
            if ((int)pcVar4 < 3) {
              pAVar5->sn = (char *)0x3;
            }
          }
          else if (*piVar3 < 1) {
            *piVar3 = 1;
          }
        }
        if ((int)pAVar5->sn < 1) {
          pAVar5->sn = (char *)0x1;
        }
      }
      a = (BIO *)0x0;
      for (iVar1 = 0; iVar2 = sk_num((_STACK *)pAVar5->ln), iVar1 < iVar2; iVar1 = iVar1 + 1) {
        sk_value((_STACK *)pAVar5->ln,iVar1);
        append = (BIO *)cms_DigestAlgorithm_init_bio();
        if (append == (BIO *)0x0) {
          if (a != (BIO *)0x0) {
            BIO_free_all(a);
            return (BIO *)0x0;
          }
          goto LAB_00110c68;
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
    ERR_put_error(0x2e,0x85,0x6c,DAT_00110c80,0x48);
    a = (BIO *)0x0;
  }
  return a;
}

