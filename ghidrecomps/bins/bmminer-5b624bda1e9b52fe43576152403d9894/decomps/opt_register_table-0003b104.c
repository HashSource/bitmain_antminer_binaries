
/* WARNING: Unknown calling convention */

void opt_register_table(opt_table *entry,char *desc)

{
  int *piVar1;
  opt_table *poVar2;
  opt_type oVar3;
  opt_table *poVar4;
  int iVar5;
  uint start;
  opt_table heading;
  
  piVar1 = DAT_0003b190;
  iVar5 = *DAT_0003b190;
  if (desc != (char *)0x0) {
    heading.names = (char *)0x0;
    heading.cb = (_func_char_ptr_void_ptr *)0x0;
    heading.cb_arg = (_func_char_ptr_char_ptr_void_ptr *)0x0;
    heading.show = (_func_void_char_ptr_void_ptr *)0x0;
    heading.u.carg = (void *)0x0;
    heading.type = OPT_SUBTABLE;
    heading.desc = desc;
    add_opt(&heading);
  }
  oVar3 = entry->type;
  if (oVar3 != OPT_END) {
    poVar2 = entry + 1;
    do {
      while (poVar4 = poVar2, oVar3 == OPT_SUBTABLE) {
        opt_register_table((opt_table *)entry->names,entry->desc);
        oVar3 = poVar4->type;
        poVar2 = poVar4 + 1;
        entry = poVar4;
        if (oVar3 == OPT_END) goto LAB_0003b16e;
      }
      check_opt(entry);
      add_opt(entry);
      oVar3 = poVar4->type;
      poVar2 = poVar4 + 1;
      entry = poVar4;
    } while (oVar3 != OPT_END);
  }
LAB_0003b16e:
  if (desc != (char *)0x0) {
    *(int *)(*DAT_0003b18c + iVar5 * 0x1c + 0x14) = *piVar1 - iVar5;
  }
  return;
}

