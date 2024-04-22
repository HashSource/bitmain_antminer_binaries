
/* WARNING: Unknown calling convention */

void opt_show_bool(char *buf,_Bool *b)

{
  char *pcVar1;
  
  pcVar1 = "false";
  if (*b != false) {
    pcVar1 = "true";
  }
                    /* WARNING: Could not recover jumptable at 0x0000a0d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f18c)(buf,pcVar1,0x50);
  return;
}

