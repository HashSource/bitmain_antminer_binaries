
undefined4 X509v3_asid_canonize(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return 1;
  }
  piVar2 = (int *)*param_1;
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    if ((*piVar2 != 1) || (iVar1 = OPENSSL_sk_num(piVar2[1]), iVar1 == 0)) goto LAB_0016e6b2;
    iVar1 = ASIdentifierChoice_canonize_part_4(piVar2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  piVar2 = (int *)param_1[1];
  if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {
    return 1;
  }
  if ((*piVar2 == 1) && (iVar1 = OPENSSL_sk_num(piVar2[1]), iVar1 != 0)) {
    iVar1 = ASIdentifierChoice_canonize_part_4(piVar2);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
LAB_0016e6b2:
  ERR_put_error(0x22,0xa1,0x74,"crypto/x509v3/v3_asid.c",0x179);
  return 0;
}

