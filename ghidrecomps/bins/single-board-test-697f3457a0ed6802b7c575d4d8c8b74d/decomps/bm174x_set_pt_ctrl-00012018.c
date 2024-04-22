
void bm174x_set_pt_ctrl(int fd,int pt_num,int pt_en)

{
  bm174x_reg bVar1;
  int pt_en_local;
  int pt_num_local;
  int fd_local;
  base_type_t item;
  bm174x_reg pt_ctrl_reg;
  
  pt_ctrl_reg.core_timeout.core_timeout._0_1_ = (undefined)reg_value.pt_ctrl;
  pt_ctrl_reg.core_timeout.core_timeout._1_3_ = (undefined3)(reg_value.pt_ctrl >> 8);
  pt_ctrl_reg.core_timeout.core_timeout._0_1_ =
       pt_ctrl_reg.core_timeout.core_timeout._0_1_ & 0xfe | (byte)pt_en & 1;
  bVar1 = pt_ctrl_reg;
  pt_ctrl_reg.core_timeout.core_timeout._2_2_ = (undefined2)(reg_value.pt_ctrl >> 0x10);
  pt_ctrl_reg.core_timeout.core_timeout._0_2_ = bVar1.core_timeout.core_timeout.core_timeout;
  pt_ctrl_reg.core_timeout.core_timeout._2_2_ =
       pt_ctrl_reg.core_timeout.core_timeout._2_2_ & 0xf800 |
       (ushort)((uint)(pt_num << 0x15) >> 0x15);
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\\';
  item.data = pt_ctrl_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}

