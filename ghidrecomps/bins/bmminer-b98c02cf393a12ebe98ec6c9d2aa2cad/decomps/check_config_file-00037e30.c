
void check_config_file(void)

{
  FILE *__stream;
  int local_6c;
  stat sStack_68;
  
  time(&local_6c);
  __xstat(3,"/etc/config/pcbtemp",&sStack_68);
  if ((600 < local_6c - sStack_68.st_mtim.tv_sec) &&
     (system("rm -rf /etc/config/pcbtemp"), 3 < log_level)) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: /etc/config/pcbtemp is too old, deleted\n","driver-btm-c5.c",
              0x2eea,DAT_00037eb4);
    }
    fclose(__stream);
    return;
  }
  return;
}

