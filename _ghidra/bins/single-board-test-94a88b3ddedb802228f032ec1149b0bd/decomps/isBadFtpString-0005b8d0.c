
char * isBadFtpString(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = strchr(param_1,0xd);
  if (pcVar1 != (char *)0x0) {
    return (char *)0x1;
  }
  pcVar1 = strchr(param_1,10);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = (char *)0x1;
  }
  return pcVar1;
}

