
void _k_list_transfer_to_head
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char acStack_820 [2052];
  
  if (*param_1 != *param_2) {
    snprintf(acStack_820,0x800,
             "List %s can\'t %s() to a %s list - from %s %s() line %d in %s %s():%d",*param_1,
             DAT_000408e8,*param_2,param_3,param_4,param_5,"klist.c",DAT_000408e8,0x152);
    _applog(3,acStack_820,1);
    _quit(1);
  }
  if (*(char *)(param_1 + 0xb) == '\0') {
    snprintf(acStack_820,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",*param_1,
             DAT_000408e8,param_3,param_4,param_5,"klist.c",DAT_000408e8,0x157);
    _applog(3,acStack_820,1);
    _quit(1);
  }
  iVar4 = param_1[3];
  if (iVar4 != 0) {
    iVar1 = param_2[3];
    if (iVar1 == 0) {
      param_2[4] = param_1[4];
      iVar5 = param_1[4];
    }
    else {
      iVar5 = param_1[4];
      *(int *)(iVar1 + 4) = iVar5;
    }
    iVar6 = param_2[7];
    iVar7 = param_2[8];
    iVar2 = param_1[7];
    iVar3 = param_1[8];
    *(int *)(iVar5 + 8) = iVar1;
    param_2[3] = iVar4;
    param_1[4] = 0;
    param_1[3] = 0;
    param_2[7] = iVar2 + iVar6;
    param_1[7] = 0;
    param_2[8] = iVar3 + iVar7;
    param_1[8] = 0;
  }
  return;
}

