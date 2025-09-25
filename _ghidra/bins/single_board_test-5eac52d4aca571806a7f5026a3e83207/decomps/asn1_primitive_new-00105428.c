
ASN1_STRING * asn1_primitive_new(uint *param_1,char *param_2,int param_3)

{
  ASN1_STRING *pAVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 *puVar3;
  ASN1_STRING *pAVar4;
  uint uVar5;
  ASN1_STRING *pAVar6;
  int iVar7;
  
  if (param_2 == (char *)0x0) {
    return (ASN1_STRING *)0x0;
  }
  iVar7 = *(int *)(param_2 + 0x10);
  if (iVar7 == 0) {
    if (*param_2 == '\x05') {
      iVar7 = -1;
    }
    else {
      iVar7 = *(int *)(param_2 + 4);
      switch(iVar7) {
      case 1:
        goto switchD_001054d0_caseD_1;
      case 5:
        goto switchD_001054d0_caseD_5;
      case 6:
        goto switchD_001054d0_caseD_6;
      case -4:
        goto switchD_001054d0_caseD_fffffffc;
      }
    }
    if (param_3 == 0) goto switchD_00105468_caseD_fffffffd;
  }
  else {
    if (param_3 == 0) {
      if (*(code **)(iVar7 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00105458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pAVar1 = (ASN1_STRING *)(**(code **)(iVar7 + 8))();
        return pAVar1;
      }
      if (*param_2 == '\x05') {
        iVar7 = -1;
      }
      else {
        iVar7 = *(int *)(param_2 + 4);
        switch(iVar7) {
        case 1:
          goto switchD_001054d0_caseD_1;
        case 5:
          goto switchD_001054d0_caseD_5;
        case 6:
          goto switchD_001054d0_caseD_6;
        case -4:
          goto switchD_001054d0_caseD_fffffffc;
        }
      }
switchD_00105468_caseD_fffffffd:
      pAVar4 = ASN1_STRING_type_new(iVar7);
      *param_1 = (uint)pAVar4;
      pAVar1 = pAVar4;
      if (pAVar4 != (ASN1_STRING *)0x0) {
        pAVar1 = (ASN1_STRING *)0x1;
      }
      if (*param_2 == '\x05') {
        pAVar6 = (ASN1_STRING *)((uint)pAVar1 & 1);
      }
      else {
        pAVar6 = (ASN1_STRING *)0x0;
      }
      if (pAVar6 == (ASN1_STRING *)0x0) {
        return pAVar1;
      }
      uVar5 = pAVar4->flags | 0x40;
      goto LAB_00105572;
    }
    if (*(code **)(iVar7 + 0x10) != (code *)0x0) {
      (**(code **)(iVar7 + 0x10))();
      return (ASN1_STRING *)0x1;
    }
    if (*param_2 == '\x05') {
      iVar7 = -1;
    }
    else {
      iVar7 = *(int *)(param_2 + 4);
      switch(iVar7) {
      case 1:
switchD_001054d0_caseD_1:
        *param_1 = *(uint *)(param_2 + 0x14);
        return (ASN1_STRING *)0x1;
      case 5:
switchD_001054d0_caseD_5:
        *param_1 = 1;
        return (ASN1_STRING *)0x1;
      case 6:
switchD_001054d0_caseD_6:
        pAVar2 = OBJ_nid2obj(0);
        *param_1 = (uint)pAVar2;
        return (ASN1_STRING *)0x1;
      case -4:
switchD_001054d0_caseD_fffffffc:
        puVar3 = (undefined4 *)CRYPTO_malloc(8,"crypto/asn1/tasn_new.c",0x12e);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[1] = 0;
          *puVar3 = 0xffffffff;
          *param_1 = (uint)puVar3;
          return (ASN1_STRING *)0x1;
        }
        ERR_put_error(0xd,0x77,0x41,"crypto/asn1/tasn_new.c",0x12f);
        return (ASN1_STRING *)0x0;
      }
    }
  }
  pAVar4 = (ASN1_STRING *)*param_1;
  pAVar4->type = iVar7;
  pAVar4->flags = 0x80;
  pAVar4->length = 0;
  pAVar4->data = (uchar *)0x0;
  if (*param_2 != '\x05') {
    if (*param_1 == 0) {
      return (ASN1_STRING *)0x0;
    }
    return (ASN1_STRING *)0x1;
  }
  pAVar6 = (ASN1_STRING *)*param_1;
  uVar5 = 0xc0;
  if (pAVar6 != (ASN1_STRING *)0x0) {
    pAVar6 = (ASN1_STRING *)0x1;
  }
LAB_00105572:
  pAVar4->flags = uVar5;
  return pAVar6;
}

