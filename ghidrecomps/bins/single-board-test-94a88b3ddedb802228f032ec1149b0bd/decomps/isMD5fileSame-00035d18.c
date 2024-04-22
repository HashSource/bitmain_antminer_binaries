
undefined4 isMD5fileSame(char *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_214 [32];
  undefined local_1f4;
  char acStack_114 [32];
  undefined local_f4;
  FILE *local_14;
  size_t local_10;
  FILE *local_c;
  
  local_c = fopen(param_1,"rb");
  if (local_c == (FILE *)0x0) {
    uVar2 = 0;
  }
  else {
    memset(acStack_114,0,0x100);
    local_10 = fread(acStack_114,1,0x100,local_c);
    fclose(local_c);
    if ((int)local_10 < 0x20) {
      uVar2 = 0;
    }
    else {
      local_14 = fopen(param_2,"rb");
      if (local_14 == (FILE *)0x0) {
        uVar2 = 0;
      }
      else {
        memset(acStack_214,0,0x100);
        local_10 = fread(acStack_214,1,0x100,local_14);
        fclose(local_14);
        if ((int)local_10 < 0x20) {
          uVar2 = 0;
        }
        else {
          local_f4 = 0;
          local_1f4 = 0;
          iVar1 = strcmp(acStack_114,acStack_214);
          if (iVar1 == 0) {
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}

