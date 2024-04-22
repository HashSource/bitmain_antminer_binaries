
/* WARNING: Unknown calling convention */

char * json_array_string(json_t *val,uint entry)

{
  char *pcVar1;
  char *buf;
  
  pcVar1 = __json_array_string(val,entry);
  if (pcVar1 == (char *)0x0) {
    return (char *)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x0000a6cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0005f370)();
  return pcVar1;
}

