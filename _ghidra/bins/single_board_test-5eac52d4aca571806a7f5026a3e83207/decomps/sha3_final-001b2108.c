
undefined4 sha3_final(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0xcc) != 0) {
    iVar2 = *(int *)(iVar1 + 200);
    iVar3 = *(int *)(iVar1 + 0xd0);
    memset((void *)(iVar1 + 0xd4 + iVar3),0,iVar2 - iVar3);
    iVar4 = iVar2 + -1 + iVar1;
    *(undefined1 *)(iVar3 + iVar1 + 0xd4) = *(undefined1 *)(iVar1 + 0x17c);
    *(byte *)(iVar4 + 0xd4) = *(byte *)(iVar4 + 0xd4) | 0x80;
    SHA3_absorb(iVar1,iVar1 + 0xd4,iVar2,iVar2);
    SHA3_squeeze(iVar1,param_2,*(undefined4 *)(iVar1 + 0xcc),iVar2);
  }
  return 1;
}

