
/* WARNING: Unknown calling convention */

void load_default_config(void)

{
  int iVar1;
  
  cnfbuf = (char *)_cgmalloc(0x1000,"cgminer.c","load_default_config",0x819);
  default_save_file(cnfbuf);
  iVar1 = access(cnfbuf,4);
  if (iVar1 == 0) {
    load_config(cnfbuf,(void *)0x0);
  }
  else {
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  return;
}

