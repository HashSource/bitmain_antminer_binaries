
code * EVP_PKEY_set1_tls_encodedpoint(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  
  if (param_3 < 0) {
    return (code *)0x0;
  }
  pcVar2 = *(code **)(param_1 + 0xc);
  if ((pcVar2 != (code *)0x0) && (pcVar2 = *(code **)(pcVar2 + 0x5c), pcVar2 != (code *)0x0)) {
    iVar1 = (*pcVar2)(param_1,9,param_3,param_2);
    return (code *)(uint)(0 < iVar1);
  }
  return pcVar2;
}

