
/* WARNING: Unknown calling convention */

void opt_show_invbool(char *buf,_Bool *b)

{
  char *pcVar1;
  
  pcVar1 = "true";
  if (*b != false) {
    pcVar1 = "false";
  }
  (*(code *)(undefined *)0x0)(buf,pcVar1,0x50);
  return;
}

