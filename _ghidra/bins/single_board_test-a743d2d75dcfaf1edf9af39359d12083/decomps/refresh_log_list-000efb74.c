
int refresh_log_list(char (*logs) [128],char *prefix)

{
  DIR *__dirp;
  size_t __n;
  int iVar1;
  char *pcVar2;
  dirent *pdVar3;
  char *prefix_local;
  char (*logs_local) [128];
  char tmp42 [2048];
  dirent *ent;
  DIR *dir;
  int i;
  int log_cnt;
  
  log_cnt = 0;
  __dirp = opendir(LOG_DIR);
  if (__dirp != (DIR *)0x0) {
    while ((pdVar3 = readdir(__dirp), pdVar3 != (dirent *)0x0 && (log_cnt < 0x60))) {
      __n = strlen(prefix);
      iVar1 = strncmp(pdVar3->d_name,prefix,__n);
      if (iVar1 == 0) {
        pcVar2 = strstr(pdVar3->d_name,".lz4");
        if ((pcVar2 == (char *)0x0) &&
           (pcVar2 = strstr(pdVar3->d_name,".64"), pcVar2 == (char *)0x0)) {
          strncpy(logs[log_cnt],pdVar3->d_name,0x7f);
          log_cnt = log_cnt + 1;
        }
        else {
          snprintf(tmp42,0x800,"errfile:%s\n",pdVar3->d_name);
          _applog(5,tmp42,false);
        }
      }
    }
    closedir(__dirp);
  }
  sort_files_by_time(logs,0,log_cnt + -1);
  builtin_strncpy(tmp42,"-----------\n",0xc);
  tmp42[0xc] = '\0';
  _applog(5,tmp42,false);
  for (i = 0; i < log_cnt; i = i + 1) {
    snprintf(tmp42,0x800,"%s\n",logs + i);
    _applog(5,tmp42,false);
  }
  builtin_strncpy(tmp42,"-----------\n",0xc);
  tmp42[0xc] = '\0';
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"file cnt:%d\n",log_cnt);
  _applog(5,tmp42,false);
  return log_cnt;
}

