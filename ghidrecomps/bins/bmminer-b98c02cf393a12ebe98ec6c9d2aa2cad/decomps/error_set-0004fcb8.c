
void error_set(int param_1,int param_2,char *param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char acStack_168 [159];
  undefined local_c9;
  char acStack_c8 [159];
  undefined local_29;
  undefined4 uStack_4;
  
  if (param_1 == 0) {
    return;
  }
  uStack_4 = param_4;
  vsnprintf(acStack_168,0xa0,param_3,&uStack_4);
  local_c9 = 0;
  if (param_2 == 0) {
    uVar2 = 0xffffffff;
    uVar3 = 0xffffffff;
    pcVar1 = acStack_168;
    uVar4 = 0;
  }
  else {
    pcVar1 = (char *)strbuffer_value(param_2 + 0x28);
    uVar3 = *(undefined4 *)(param_2 + 0x18);
    uVar2 = *(undefined4 *)(param_2 + 0x1c);
    uVar4 = *(undefined4 *)(param_2 + 0x24);
    if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
      if (*(int *)(param_2 + 0x14) != -2) {
        snprintf(acStack_c8,0xa0,"%s near end of file",acStack_168);
        pcVar1 = acStack_c8;
        local_29 = 0;
        goto LAB_0004fd02;
      }
    }
    else if (*(uint *)(param_2 + 0x2c) < 0x15) {
      snprintf(acStack_c8,0xa0,"%s near \'%s\'",acStack_168,pcVar1);
      pcVar1 = acStack_c8;
      local_29 = 0;
      goto LAB_0004fd02;
    }
    pcVar1 = acStack_168;
  }
LAB_0004fd02:
  jsonp_error_set(param_1,uVar3,uVar2,uVar4,"%s",pcVar1);
  return;
}

