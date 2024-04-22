
/* WARNING: Unknown calling convention */

char * jsonp_strsteal(strbuffer_t *strbuff)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a674. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0005f354)(strbuff->value,strbuff->length + 1);
  return pcVar1;
}

