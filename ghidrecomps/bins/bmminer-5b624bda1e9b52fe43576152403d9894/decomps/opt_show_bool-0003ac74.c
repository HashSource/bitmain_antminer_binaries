
/* WARNING: Unknown calling convention */

void opt_show_bool(char *buf,_Bool *b)

{
  char *pcVar1;
  
  pcVar1 = "false";
  if (*b != false) {
    pcVar1 = "true";
  }
  (*(code *)(undefined *)0x0)(buf,pcVar1,0x50);
  return;
}

