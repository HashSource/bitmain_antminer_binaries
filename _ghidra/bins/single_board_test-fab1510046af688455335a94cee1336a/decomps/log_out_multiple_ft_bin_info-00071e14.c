
void log_out_multiple_ft_bin_info(ft_bin_list_t *list)

{
  undefined4 uVar1;
  ft_bin_list_t *list_local;
  char time_stamp [48];
  char tmp1 [2048];
  int i;
  
  if ((list != (ft_bin_list_t *)0x0) && (list->ft_bin_cnt != 0)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ft_bin_id:%d,ft_bin_cnt:%d\n","log_out_multiple_ft_bin_info",(uint)list->ft_bin_id,
           list->ft_bin_cnt);
    snprintf(tmp1,0x800,"ft_bin_id:%d,ft_bin_cnt:%d",(uint)list->ft_bin_id,list->ft_bin_cnt);
    log_to_file(tmp1,time_stamp);
    for (i = 0; i < list->ft_bin_cnt; i = i + 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      if (((uint)list->ft_bin[i] & 1) == 0) {
        uVar1 = 0x45;
      }
      else {
        uVar1 = 0x46;
      }
      printf("%s: FT info:%c%dV%02dB%dC%d BIN%d,col:%d\n","log_out_multiple_ft_bin_info",uVar1,
             ((uint)*(byte *)(list->ft_bin + i) << 0x1c) >> 0x1d,
             ((uint)*(ushort *)(list->ft_bin + i) << 0x16) >> 0x1a,
             ((uint)*(byte *)((int)list->ft_bin + i * 4 + 1) << 0x1b) >> 0x1d,
             ((uint)*(byte *)((int)list->ft_bin + i * 4 + 1) << 0x19) >> 0x1e,
             (list->ft_bin[i].v << 0xe) >> 0x1d,
             ((uint)*(byte *)((int)list->ft_bin + i * 4 + 2) << 0x18) >> 0x1c);
      if (((uint)list->ft_bin[i] & 1) == 0) {
        uVar1 = 0x45;
      }
      else {
        uVar1 = 0x46;
      }
      snprintf(tmp1,0x800,"FT info:%c%dV%02dB%dC%d BIN%d,col:%d",uVar1,
               ((uint)*(byte *)(list->ft_bin + i) << 0x1c) >> 0x1d,
               ((uint)*(ushort *)(list->ft_bin + i) << 0x16) >> 0x1a,
               ((uint)*(byte *)((int)list->ft_bin + i * 4 + 1) << 0x1b) >> 0x1d,
               ((uint)*(byte *)((int)list->ft_bin + i * 4 + 1) << 0x19) >> 0x1e,
               (list->ft_bin[i].v << 0xe) >> 0x1d,
               ((uint)*(byte *)((int)list->ft_bin + i * 4 + 2) << 0x18) >> 0x1c);
      log_to_file(tmp1,time_stamp);
    }
  }
  return;
}

