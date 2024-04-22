
/* WARNING: Unknown calling convention */

void add_opt(opt_table *entry)

{
  opt_type oVar1;
  anon_union_4_3_d8f38084_for_u aVar2;
  _func_char_ptr_void_ptr *p_Var3;
  char *pcVar4;
  _func_char_ptr_char_ptr_void_ptr *p_Var5;
  opt_table *poVar6;
  
  opt_table = (opt_table *)realloc(opt_table,(opt_count + 1) * 0x1c);
  oVar1 = entry->type;
  p_Var3 = entry->cb;
  p_Var5 = entry->cb_arg;
  poVar6 = opt_table + opt_count;
  poVar6->names = entry->names;
  poVar6->type = oVar1;
  poVar6->cb = p_Var3;
  poVar6->cb_arg = p_Var5;
  aVar2 = entry->u;
  pcVar4 = entry->desc;
  opt_count = opt_count + 1;
  poVar6->show = entry->show;
  poVar6->u = aVar2;
  poVar6->desc = pcVar4;
  return;
}

