
void bm174x_set_pt_result(int fd,int ptr_grp_num,int ptr_rd)

{
  int ptr_rd_local;
  int ptr_grp_num_local;
  int fd_local;
  base_type_t item;
  bm174x_reg pt_result_reg;
  
  pt_result_reg.core_timeout.core_timeout._1_1_ =
       pt_result_reg.core_timeout.core_timeout._1_1_ & 0xf0 | (byte)ptr_grp_num & 0xf;
  pt_result_reg.core_timeout.core_timeout._0_1_ =
       pt_result_reg.core_timeout.core_timeout._0_1_ & 0xfe | (byte)ptr_rd & 1;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '`';
  item.data = pt_result_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}

