
json_t * create_ft_bin_json_info(ft_bin_list_t *list)

{
  json_t *json;
  json_t *value;
  json_t *pjVar1;
  json_t *pjVar2;
  char *__ptr;
  ft_bin_list_t *list_local;
  char time_stamp [48];
  char tmp1 [256];
  char *jstr;
  json_t *item;
  json_t *j_ft_bin;
  json_t *j_ft_bin_list;
  int i;
  
  json = json_object();
  value = json_array();
  pjVar1 = json_integer((ulonglong)list->ft_bin_id);
  json_object_set_new(json,"id",pjVar1);
  json_object_set_new(json,"ft_bin",value);
  for (i = 0; i < 2; i = i + 1) {
    pjVar1 = json_object();
    json_array_append_new(value,pjVar1);
    pjVar2 = json_string(list->chip_ftversion[i]);
    json_object_set_new(pjVar1,"ft_version",pjVar2);
    pjVar2 = json_integer((ulonglong)list->chip_bin[i]);
    json_object_set_new(pjVar1,"bin",pjVar2);
    pjVar2 = json_integer((ulonglong)list->chip_col[i]);
    json_object_set_new(pjVar1,"col",pjVar2);
  }
  __ptr = json_dumps(json,0x200);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : jstr:%s\n","create_ft_bin_json_info",__ptr);
  snprintf(tmp1,0x100,"jstr:%s",__ptr);
  log_to_file(tmp1,time_stamp);
  free(__ptr);
  return json;
}

