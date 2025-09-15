
void saveSearchFailedFlagInfo(void)

{
  FILE *__s;
  size_t sVar1;
  
  __s = fopen("/tmp/searcherror","wb");
  if (__s != (FILE *)0x0) {
    sVar1 = strlen(search_failed_info);
    fwrite(search_failed_info,1,sVar1 + 1,__s);
    fclose(__s);
  }
  system("cp /tmp/search /tmp/err1.log -f");
  system("cp /tmp/freq /tmp/err2.log -f");
  system("cp /tmp/lasttemp /tmp/err3.log -f");
  system("sync");
  PostSearchFailedInfoToServer(search_failed_info);
  return;
}

