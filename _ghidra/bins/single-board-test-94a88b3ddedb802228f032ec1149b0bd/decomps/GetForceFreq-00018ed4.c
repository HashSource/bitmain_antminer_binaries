
int GetForceFreq(undefined4 *param_1)

{
  int iVar1;
  char acStack_134 [16];
  char acStack_124 [16];
  char acStack_114 [256];
  int local_14;
  FILE *local_10;
  int local_c;
  
  local_10 = fopen("/etc/config/forcefreq.txt","rb");
  if (local_10 == (FILE *)0x0) {
    *param_1 = 0;
    local_10 = fopen("/etc/config/last_forcefreq.txt","rb");
    if (local_10 == (FILE *)0x0) {
      local_c = -1;
    }
    else {
      memset(acStack_134,0,0x20);
      fread(acStack_134,1,0x20,local_10);
      local_c = atoi(acStack_134);
      fclose(local_10);
    }
  }
  else {
    memset(acStack_134,0,0x20);
    fread(acStack_134,1,0x20,local_10);
    local_14 = atoi(acStack_134);
    fclose(local_10);
    iVar1 = strcmp(acStack_124,"wsdk");
    if (iVar1 == 0) {
      local_10 = fopen("/etc/config/last_forcefreq.txt","rb");
      if (local_10 == (FILE *)0x0) {
        local_c = -1;
      }
      else {
        memset(acStack_134,0,0x20);
        fread(acStack_134,1,0x20,local_10);
        local_c = atoi(acStack_134);
        fclose(local_10);
      }
      if (local_c == local_14) {
        sprintf(acStack_114,"rm %s","/etc/config/forcefreq.txt");
        system(acStack_114);
        *param_1 = 0;
      }
      else {
        printf("force freq=%d\n",local_14);
        iVar1 = scan_freq_already_done();
        local_c = local_14;
        if (iVar1 == 0) {
          *param_1 = 1;
        }
        else {
          *param_1 = 0;
        }
      }
    }
    else {
      *param_1 = 0;
      local_c = -1;
    }
  }
  return local_c;
}

