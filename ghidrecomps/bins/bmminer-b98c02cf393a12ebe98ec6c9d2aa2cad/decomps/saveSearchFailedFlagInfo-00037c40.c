
void saveSearchFailedFlagInfo(char *param_1)

{
  FILE *__s;
  size_t sVar1;
  
  __s = fopen("/tmp/searcherror","wb");
  if (__s != (FILE *)0x0) {
    sVar1 = strlen(param_1);
    fwrite(param_1,1,sVar1 + 1,__s);
    fclose(__s);
  }
  system("cp /tmp/search /tmp/err1.log -f");
  system("cp /tmp/freq /tmp/err2.log -f");
  system("cp /tmp/lasttemp /tmp/err3.log -f");
  (*(code *)PTR_system_0007cf40)(&DAT_00061fc4);
  return;
}

