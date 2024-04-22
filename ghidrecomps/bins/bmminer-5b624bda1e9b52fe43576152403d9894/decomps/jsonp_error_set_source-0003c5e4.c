
/* WARNING: Unknown calling convention */

void jsonp_error_set_source(json_error_t *error,char *source)

{
  size_t sVar1;
  size_t length;
  undefined4 in_r3;
  
  if (error == (json_error_t *)0x0 || source == (char *)0x0) {
    return;
  }
  sVar1 = strlen(source);
  if (sVar1 < 0x50) {
                    /* WARNING: Could not recover jumptable at 0x0000a384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f264)(error->source,source,sVar1 + 1,in_r3);
    return;
  }
  *(undefined4 *)error->source = *DAT_0003c628;
                    /* WARNING: Could not recover jumptable at 0x0000a3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f280)(error->source + 3,source + (sVar1 - 0x4c),sVar1,in_r3);
  return;
}

