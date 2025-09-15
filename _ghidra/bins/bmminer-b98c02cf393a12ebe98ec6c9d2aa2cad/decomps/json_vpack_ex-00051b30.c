
int json_vpack_ex(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_68;
  char *local_64;
  char *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    jsonp_error_init(param_1,0);
    local_58 = 0;
    local_5c = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_3c = 0;
    local_20 = 0;
    local_1c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_24 = 1;
    local_64 = param_3;
    local_60 = param_3;
    local_2c = param_1;
    local_28 = param_2;
    next_token(&local_64);
    local_68 = param_4;
    iVar1 = pack(&local_64,&local_68);
    if (iVar1 != 0) {
      next_token(&local_64);
      if ((char)local_40 == '\0') {
        return iVar1;
      }
      if ((*(int *)(iVar1 + 4) != -1) &&
         (iVar2 = *(int *)(iVar1 + 4) + -1, *(int *)(iVar1 + 4) = iVar2, iVar2 == 0)) {
        json_delete(iVar1);
      }
      set_error(&local_64,"<format>","Garbage after format string");
    }
    return 0;
  }
  jsonp_error_init(param_1,"<format>");
  jsonp_error_set(param_1,0xffffffff,0xffffffff,0,"NULL or empty format string");
  return 0;
}

