
void asn1_primitive_free(int *param_1,char *param_2,int param_3)

{
  ASN1_OBJECT *a;
  undefined4 *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == (char *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    a = (ASN1_OBJECT *)puVar1[1];
    param_1 = puVar1 + 1;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
    switch(*puVar1) {
    case 1:
      puVar1[1] = 0xffffffff;
      return;
    case 5:
      goto switchD_00109394_caseD_5;
    case 6:
      goto switchD_00109394_caseD_6;
    case 0xfffffffc:
      goto switchD_00109394_caseD_fffffffc;
    default:
      goto switchD_00109394_caseD_fffffffd;
    }
  }
  iVar2 = *(int *)(param_2 + 0x10);
  if (param_3 == 0) {
    if (iVar2 != 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0xc);
joined_r0x0010931e:
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00109316. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
    }
  }
  else if (iVar2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x10);
    goto joined_r0x0010931e;
  }
  if (*param_2 != '\x05') {
    iVar2 = *(int *)(param_2 + 4);
    if (iVar2 == 1) {
      *param_1 = *(int *)(param_2 + 0x14);
      return;
    }
    a = (ASN1_OBJECT *)*param_1;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar2 != 5) {
      if (iVar2 == 6) {
switchD_00109394_caseD_6:
        ASN1_OBJECT_free(a);
        *param_1 = 0;
        return;
      }
      if (iVar2 != -4) goto switchD_00109394_caseD_fffffffd;
switchD_00109394_caseD_fffffffc:
      asn1_primitive_free(param_1,0);
      CRYPTO_free((void *)*param_1);
    }
switchD_00109394_caseD_5:
    *param_1 = 0;
    return;
  }
  a = (ASN1_OBJECT *)*param_1;
  if (a == (ASN1_OBJECT *)0x0) {
    return;
  }
switchD_00109394_caseD_fffffffd:
  asn1_string_embed_free(a,param_3);
  *param_1 = 0;
  return;
}

