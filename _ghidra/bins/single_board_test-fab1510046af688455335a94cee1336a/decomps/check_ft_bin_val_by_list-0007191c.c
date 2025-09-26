
_Bool check_ft_bin_val_by_list(ft_bin_list_t *list)

{
  _Bool _Var1;
  ft_bin_list_t *list_local;
  char time_stamp [48];
  char tmp1 [2048];
  _Bool res;
  int i;
  
  if (list->ft_bin_id < 0x40) {
    for (i = 0; i < list->ft_bin_cnt; i = i + 1) {
      _Var1 = check_ft_bin_val('F',((uint)*(byte *)(list->ft_bin + i) << 0x1c) >> 0x1d,
                               ((uint)*(ushort *)(list->ft_bin + i) << 0x16) >> 0x1a,
                               ((uint)*(byte *)((int)list->ft_bin + i * 4 + 1) << 0x1b) >> 0x1d,
                               ((uint)*(byte *)((int)list->ft_bin + i * 4 + 1) << 0x19) >> 0x1e,
                               (list->ft_bin[i].v << 0xe) >> 0x1d,
                               ((uint)*(byte *)((int)list->ft_bin + i * 4 + 2) << 0x18) >> 0x1c);
      if (!_Var1) {
        return false;
      }
    }
    _Var1 = true;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ft_bin_id is err:%d\n","check_ft_bin_val_by_list",(uint)list->ft_bin_id);
    snprintf(tmp1,0x800,"ft_bin_id is err:%d",(uint)list->ft_bin_id);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

