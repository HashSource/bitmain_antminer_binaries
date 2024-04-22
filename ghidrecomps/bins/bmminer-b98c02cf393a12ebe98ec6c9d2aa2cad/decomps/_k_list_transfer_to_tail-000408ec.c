
void _k_list_transfer_to_tail
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
             DAT_000409dc,*param_2,param_3,param_4,param_5,"klist.c",DAT_000409dc,0x170);
    _applog(3,acStack_820,1);
    _quit(1);
  }
  if (*(char *)(param_1 + 0xb) == '\0') {
    snprintf(acStack_820,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",*param_1,
             DAT_000409dc,param_3,param_4,param_5,"klist.c",DAT_000409dc,0x175);
    _applog(3,acStack_820,1);
    _quit(1);
  }
  iVar3 = param_1[3];
  if (iVar3 != 0) {
    iVar4 = param_2[4];
    if (iVar4 == 0) {
      param_2[3] = iVar3;
      iVar3 = param_1[3];
    }
    else {
      *(int *)(iVar4 + 8) = iVar3;
    }
    iVar5 = param_2[7];
    iVar1 = param_1[7];
    iVar7 = param_2[8];
    iVar2 = param_1[8];
    iVar6 = param_1[4];
    *(int *)(iVar3 + 4) = iVar4;
    param_2[4] = iVar6;
    param_1[4] = 0;
    param_1[3] = 0;
    param_2[7] = iVar1 + iVar5;
    param_1[7] = 0;
    param_2[8] = iVar7 + iVar2;
    param_1[8] = 0;
  }
  return;
}

