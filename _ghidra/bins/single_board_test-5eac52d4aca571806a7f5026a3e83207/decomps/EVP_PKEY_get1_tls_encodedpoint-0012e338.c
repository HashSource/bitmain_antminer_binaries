
int EVP_PKEY_get1_tls_encodedpoint(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  pcVar2 = *(code **)(*(int *)(param_1 + 0xc) + 0x5c);
  if ((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(param_1,10,0,param_2), 0 < iVar1)) {
    return iVar1;
  }
  return 0;
}

