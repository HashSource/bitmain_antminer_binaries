
void hashtable_do_clear(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while (iVar1 != param_1 + 0xc) {
    iVar2 = *(int *)(iVar1 + 0x14);
    iVar4 = *(int *)(iVar1 + 4);
    if (((iVar2 != 0) && (iVar3 = *(int *)(iVar2 + 4) + -1, *(int *)(iVar2 + 4) != -1)) &&
       (*(int *)(iVar2 + 4) = iVar3, iVar3 == 0)) {
      json_delete();
    }
    jsonp_free(iVar1);
    iVar1 = iVar4;
  }
  return;
}

