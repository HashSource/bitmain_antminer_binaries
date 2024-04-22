
/* WARNING: Unknown calling convention */

void _simplelog(int prio,char *str,_Bool force)

{
  char cVar1;
  FILE **ppFVar2;
  int iVar3;
  undefined4 in_r3;
  
  ppFVar2 = DAT_0000f834;
  if (*DAT_0000f830 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0000a060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f168)(prio | 0x80,DAT_0000f840,str,in_r3);
    return;
  }
  iVar3 = fileno(*DAT_0000f834);
  iVar3 = isatty(iVar3);
  if (iVar3 == 0) {
    fprintf(*ppFVar2,DAT_0000f844,str);
    fflush(*ppFVar2);
    cVar1 = *DAT_0000f838;
  }
  else {
    cVar1 = *DAT_0000f838;
  }
  if (cVar1 != '\0') {
    if (prio != 3) {
      return;
    }
  }
  my_log_curses(DAT_0000f83c,str,(char *)(uint)force,SUB41(in_r3,0));
  return;
}

