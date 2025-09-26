
void log_out_multiple_ft_bin_info(ft_bin_list_t *p_list)

{
  ft_bin_list_t *p_list_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : FT info : %s-%d-%d %s-%d-%d\n","log_out_multiple_ft_bin_info",p_list->chip_ftversion,
         (uint)p_list->chip_bin[0],(uint)p_list->chip_col[0],p_list->chip_ftversion + 1,
         (uint)p_list->chip_bin[1],(uint)p_list->chip_col[1]);
  snprintf(tmp1,0x100,"FT info : %s-%d-%d %s-%d-%d",p_list->chip_ftversion,(uint)p_list->chip_bin[0]
           ,(uint)p_list->chip_col[0],p_list->chip_ftversion + 1,(uint)p_list->chip_bin[1],
           (uint)p_list->chip_col[1]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : FT encode : 0x%x-%d-%d-0x%x\n","log_out_multiple_ft_bin_info",
         (uint)(p_list->ft_value).u.head,(p_list->ft_value).u.data[0],(p_list->ft_value).u.data[1],
         (uint)(p_list->ft_value).u.tail);
  snprintf(tmp1,0x100,"FT encode : 0x%x-%d-%d-0x%x",(uint)(p_list->ft_value).u.head,
           (p_list->ft_value).u.data[0],(p_list->ft_value).u.data[1],(uint)(p_list->ft_value).u.tail
          );
  log_to_file(tmp1,time_stamp);
  return;
}

