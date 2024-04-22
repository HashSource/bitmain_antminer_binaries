
/* WARNING: Unknown calling convention */

void __libc_csu_init(int argc,char **argv,char **envp)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_0012cf70;
  iVar4 = DAT_0012cf6c + 0x12cf48;
  _init();
  iVar4 = iVar4 - (iVar2 + 0x12cf4e) >> 2;
  if (iVar4 != 0) {
    iVar3 = 0;
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      (**(code **)(iVar2 + 0x12cf4e + iVar1))(argc,argv,envp);
    } while (iVar3 != iVar4);
  }
  return;
}

