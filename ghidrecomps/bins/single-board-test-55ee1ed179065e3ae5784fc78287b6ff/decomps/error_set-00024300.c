
void error_set(int param_1,int param_2,char *param_3,undefined4 param_4)

{
  char acStack_168 [159];
  undefined local_c9;
  char acStack_c8 [159];
  undefined local_29;
  undefined4 *local_28;
  char *local_24;
  char *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_4;
  
  local_14 = 0xffffffff;
  local_18 = 0xffffffff;
  local_1c = 0;
  local_20 = acStack_c8;
  if (param_1 != 0) {
    local_28 = &uStack_4;
    uStack_4 = param_4;
    vsnprintf(acStack_c8,0xa0,param_3,local_28);
    local_29 = 0;
    if (param_2 != 0) {
      local_24 = (char *)strbuffer_value(param_2 + 0x28);
      local_14 = *(undefined4 *)(param_2 + 0x18);
      local_18 = *(undefined4 *)(param_2 + 0x1c);
      local_1c = *(undefined4 *)(param_2 + 0x24);
      if ((local_24 == (char *)0x0) || (*local_24 == '\0')) {
        if (*(int *)(param_2 + 0x14) == -2) {
          local_20 = acStack_c8;
        }
        else {
          snprintf(acStack_168,0xa0,"%s near end of file",acStack_c8);
          local_c9 = 0;
          local_20 = acStack_168;
        }
      }
      else if (*(uint *)(param_2 + 0x2c) < 0x15) {
        snprintf(acStack_168,0xa0,"%s near \'%s\'",acStack_c8,local_24);
        local_c9 = 0;
        local_20 = acStack_168;
      }
    }
    jsonp_error_set(param_1,local_14,local_18,local_1c,&DAT_0002cf58,local_20);
  }
  return;
}

