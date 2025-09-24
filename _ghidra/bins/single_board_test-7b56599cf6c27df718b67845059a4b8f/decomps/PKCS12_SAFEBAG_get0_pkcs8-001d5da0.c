
undefined4 PKCS12_SAFEBAG_get0_pkcs8(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_1);
  if (iVar1 == 0x97) {
    uVar2 = param_1[1];
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

