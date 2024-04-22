
/* WARNING: Unknown calling convention */

void opt_show_invbool(char *buf,_Bool *b)

{
  char *pcVar1;
  
  pcVar1 = "true";
  if (*b != false) {
    pcVar1 = "false";
  }
                    /* WARNING: Could not recover jumptable at 0x0000a0d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f18c)(buf,pcVar1,0x50);
  return;
}

