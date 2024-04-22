
void check_opt(opt_table *entry)

{
  opt_table *entry_local;
  uint len;
  char *p;
  
  if (((entry->type != OPT_HASARG) && (entry->type != OPT_NOARG)) && (entry->type != OPT_PROCESSARG)
     ) {
    errx(1,"Option %s: unknown entry type %u",entry->names,entry->type);
  }
  if (entry->desc == (char *)0x0) {
    errx(1,"Option %s: description cannot be NULL",entry->names);
  }
  if (*entry->names != '-') {
    errx(1,"Option %s: does not begin with \'-\'",entry->names);
  }
  for (p = first_name(entry->names,&len); p != (char *)0x0; p = next_name(p,&len)) {
    if (*p == '-') {
      if (len == 1) {
        errx(1,"Option %s: invalid long option \'--\'",entry->names);
      }
      opt_num_long = opt_num_long + 1;
    }
    else {
      if (len != 1) {
        errx(1,"Option %s: invalid short option \'%.*s\'",entry->names,len + 1,p + -1);
      }
      opt_num_short = opt_num_short + 1;
      if ((entry->type == OPT_HASARG) || (entry->type == OPT_PROCESSARG)) {
        opt_num_short_arg = opt_num_short_arg + 1;
      }
    }
    if ((entry->type == OPT_NOARG) && ((p[len] == ' ' || (p[len] == '=')))) {
      errx(1,"Option %s: does not take arguments \'%s\'",entry->names,p + len + 1);
    }
  }
  return;
}

