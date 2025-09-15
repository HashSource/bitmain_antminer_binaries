
void opt_register_table(opt_table *entry,char *desc)

{
  uint uVar1;
  char *desc_local;
  opt_table *entry_local;
  opt_table heading;
  uint start;
  uint i;
  
  uVar1 = opt_count;
  if (desc != (char *)0x0) {
    heading.names = (char *)0x0;
    heading.type = OPT_SUBTABLE;
    heading.cb = (_func_char_ptr_void_ptr *)0x0;
    heading.cb_arg = (_func_char_ptr_char_ptr_void_ptr *)0x0;
    heading.show = (_func_void_char_ptr_void_ptr *)0x0;
    heading.u.carg = (void *)0x0;
    heading.desc = desc;
    add_opt(&heading);
  }
  for (i = 0; entry[i].type != OPT_END; i = i + 1) {
    if (entry[i].type == OPT_SUBTABLE) {
      opt_register_table((opt_table *)entry[i].names,entry[i].desc);
    }
    else {
      check_opt(entry + i);
      add_opt(entry + i);
    }
  }
  if (desc != (char *)0x0) {
    opt_table[uVar1].u.carg = (void *)(opt_count - uVar1);
  }
  return;
}

