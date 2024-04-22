
undefined is_working_in_low_power_mode(void)

{
  undefined uVar1;
  int iVar2;
  char acStack_74 [100];
  char *local_10;
  FILE *local_c;
  
  if (working_mode < 0) {
    memset(acStack_74,0,100);
    memcpy(acStack_74,"grep -rn \"bitmain-economic-mode\" /config/bmminer.conf | grep true | wc -l",
           0x4a);
    local_c = popen(acStack_74,"r");
    if (local_c == (FILE *)0x0) {
      uVar1 = 0;
    }
    else {
      memset(acStack_74,0,100);
      local_10 = fgets(acStack_74,100,local_c);
      if (local_10 != (char *)0x0) {
        iVar2 = atoi(acStack_74);
        if (iVar2 == 1) {
          working_mode = 1;
          pclose(local_c);
          return 1;
        }
        iVar2 = atoi(acStack_74);
        if (iVar2 == 1) {
          working_mode = 0;
          pclose(local_c);
          return 0;
        }
      }
      pclose(local_c);
      uVar1 = 0;
    }
  }
  else {
    iVar2 = working_mode;
    if (working_mode == 1) {
      iVar2 = 1;
    }
    uVar1 = (undefined)iVar2;
    if (working_mode != 1) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

