
undefined4 PKCS12_SAFEBAG_get0_p8inf(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = PKCS12_SAFEBAG_get_nid();
  if (iVar1 == 0x96) {
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

