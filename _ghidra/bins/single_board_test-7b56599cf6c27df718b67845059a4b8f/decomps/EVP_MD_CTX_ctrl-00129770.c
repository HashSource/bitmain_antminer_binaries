
code * EVP_MD_CTX_ctrl(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)*param_1;
  if ((pcVar2 != (code *)0x0) && (pcVar2 = *(code **)(pcVar2 + 0x2c), pcVar2 != (code *)0x0)) {
    iVar1 = (*pcVar2)();
    return (code *)(uint)(0 < iVar1);
  }
  return pcVar2;
}

