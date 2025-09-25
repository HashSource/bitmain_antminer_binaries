
int refresh_log_list(char (*logs) [128],char *prefix)

{
  DIR *__dirp;
  size_t __n;
  int iVar1;
  char *pcVar2;
  dirent *pdVar3;
  char *prefix_local;
  char (*logs_local) [128];
  dirent *ent;
  DIR *dir;
  int i;
  int log_cnt;
  
  log_cnt = 0;
  __dirp = opendir(LOG_DIR);
  if (__dirp != (DIR *)0x0) {
    while ((pdVar3 = readdir(__dirp), pdVar3 != (dirent *)0x0 && (log_cnt < 400))) {
      __n = strlen(prefix);
      iVar1 = strncmp(pdVar3->d_name,prefix,__n);
      if (((iVar1 == 0) && (pcVar2 = strstr(pdVar3->d_name,".lz4"), pcVar2 == (char *)0x0)) &&
         (pcVar2 = strstr(pdVar3->d_name,".64"), pcVar2 == (char *)0x0)) {
        strncpy(logs[log_cnt],pdVar3->d_name,0x7f);
        log_cnt = log_cnt + 1;
      }
    }
    closedir(__dirp);
  }
  sort_files_by_time(logs,0,log_cnt + -1);
  for (i = 0; i < log_cnt; i = i + 1) {
  }
  return log_cnt;
}

