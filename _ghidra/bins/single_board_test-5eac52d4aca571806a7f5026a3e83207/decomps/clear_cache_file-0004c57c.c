
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_cache_file(void)

{
  DIR *__dirp;
  char *pcVar1;
  dirent *pdVar2;
  char full_name [128];
  dirent *ent;
  DIR *dir;
  
  __dirp = opendir(LOG_DIR);
  if (__dirp != (DIR *)0x0) {
    while (pdVar2 = readdir(__dirp), pdVar2 != (dirent *)0x0) {
      pcVar1 = strstr(pdVar2->d_name,".lz4");
      if ((pcVar1 != (char *)0x0) || (pcVar1 = strstr(pdVar2->d_name,".64"), pcVar1 != (char *)0x0))
      {
        snprintf(full_name,0x80,"%s%s",LOG_DIR,pdVar2->d_name);
        remove(full_name);
        unlink(full_name);
      }
    }
    closedir(__dirp);
  }
  return;
}

