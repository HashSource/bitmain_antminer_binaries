
int GetDefaultFreq(void)

{
  int iVar1;
  char acStack_834 [32];
  char acStack_814 [2048];
  char *local_14;
  char *local_10;
  FILE *local_c;
  
  local_c = fopen("/etc/bmminer.conf.factory","rb");
  if (local_c != (FILE *)0x0) {
    memset(acStack_814,0,0x800);
    fread(acStack_814,1,0x800,local_c);
    fclose(local_c);
    local_10 = strstr(acStack_814,"bitmain-freq");
    if ((local_10 != (char *)0x0) && (local_10 = strchr(local_10,0x3a), local_10 != (char *)0x0)) {
      local_10 = strchr(local_10,0x22);
      local_10 = local_10 + 1;
      local_14 = strchr(local_10,0x22);
      memcpy(acStack_834,local_10,(int)local_14 - (int)local_10);
      local_14[(int)(acStack_834 + -(int)local_10)] = '\0';
      iVar1 = atoi(acStack_834);
      return iVar1;
    }
  }
  return 0x226;
}

