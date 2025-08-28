
/* WARNING: Unknown calling convention */

void default_save_file(char *filename)

{
  char *pcVar1;
  size_t sVar2;
  
  if ((default_config != (char *)0x0) && (*default_config != '\0')) {
    (*(code *)(undefined *)0x0)();
    return;
  }
  pcVar1 = getenv("HOME");
  if ((pcVar1 == (char *)0x0) || (pcVar1 = getenv("HOME"), *pcVar1 == '\0')) {
    *filename = '\0';
  }
  else {
    pcVar1 = getenv("HOME");
    pcVar1 = stpcpy(filename,pcVar1);
    pcVar1[0] = '/';
    pcVar1[1] = '\0';
  }
  sVar2 = strlen(filename);
  builtin_strncpy(filename + sVar2,".bmminer/",10);
  mkdir(filename,0x1ff);
  sVar2 = strlen(filename);
  builtin_strncpy(filename + sVar2,"bmminer.conf",0xd);
  return;
}

