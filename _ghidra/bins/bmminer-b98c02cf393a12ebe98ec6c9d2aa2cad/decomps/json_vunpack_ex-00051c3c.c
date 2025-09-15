
undefined4
json_vunpack_ex(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
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
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    jsonp_error_init(param_2,"<root>");
    jsonp_error_set(param_2,0xffffffff,0xffffffff,0,"NULL root value");
  }
  else if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
    uVar2 = 0xffffffff;
    jsonp_error_init(param_2,"<format>");
    jsonp_error_set(param_2,0xffffffff,0xffffffff,0,"NULL or empty format string");
  }
  else {
    jsonp_error_init(param_2,0);
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
    local_64 = param_4;
    local_60 = param_4;
    local_2c = param_2;
    local_28 = param_3;
    next_token(&local_64);
    local_68 = param_5;
    iVar1 = unpack(&local_64,param_1,&local_68);
    if (iVar1 == 0) {
      next_token(&local_64);
      uVar2 = 0;
      if ((local_40 & 0xff) != 0) {
        uVar2 = 0xffffffff;
        set_error(&local_64,"<format>","Garbage after format string");
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

