
/* WARNING: Unknown calling convention */

void __libc_csu_init(int argc,char **argv,char **envp)

{
  int iVar1;
  int iVar2;
  code **ppcVar3;
  int iVar4;
  
  iVar1 = DAT_00010c48;
  iVar4 = DAT_00010c44 + 0x10c22;
  _init((EVP_PKEY_CTX *)argc);
  iVar4 = iVar4 - (int)(code **)(iVar1 + 0x10c28) >> 2;
  if (iVar4 != 0) {
    iVar2 = 0;
    ppcVar3 = (code **)(iVar1 + 0x10c28);
    do {
      iVar2 = iVar2 + 1;
      (**ppcVar3)(argc,argv,envp);
      ppcVar3 = ppcVar3 + 1;
    } while (iVar4 != iVar2);
  }
  return;
}

