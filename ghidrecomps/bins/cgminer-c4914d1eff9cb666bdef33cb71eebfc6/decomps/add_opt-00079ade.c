
void add_opt(opt_table *entry)

{
  opt_type oVar1;
  anon_union_4_3_d8f38084_for_u aVar2;
  opt_table *poVar3;
  _func_char_ptr_void_ptr *p_Var4;
  char *pcVar5;
  _func_char_ptr_char_ptr_void_ptr *p_Var6;
  opt_table *entry_local;
  
  opt_table = (opt_table *)realloc(opt_table,(opt_count + 1) * 0x1c);
  poVar3 = opt_table + opt_count;
  oVar1 = entry->type;
  p_Var4 = entry->cb;
  p_Var6 = entry->cb_arg;
  opt_count = opt_count + 1;
  poVar3->names = entry->names;
  poVar3->type = oVar1;
  poVar3->cb = p_Var4;
  poVar3->cb_arg = p_Var6;
  aVar2 = entry->u;
  pcVar5 = entry->desc;
  poVar3->show = entry->show;
  poVar3->u = aVar2;
  poVar3->desc = pcVar5;
  return;
}

