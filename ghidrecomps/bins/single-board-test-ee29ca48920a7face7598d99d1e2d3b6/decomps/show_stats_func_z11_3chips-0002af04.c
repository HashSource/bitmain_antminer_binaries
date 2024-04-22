
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 show_stats_func_z11_3chips(void)

{
  undefined4 local_28 [4];
  size_t local_18;
  int local_14;
  
  local_14 = 0;
  while (show_id_alive != 0) {
    usleep(1000000);
    memset(lcd_buffer + 0x20,0x20,0x40);
    sprintf(lcd_buffer + 0x20,"time %ds",local_14);
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    sprintf((char *)local_28,"nonce=%d %d %d",*(undefined4 *)g_patten._116_4_,
            *(undefined4 *)(g_patten._116_4_ + 4),*(undefined4 *)(g_patten._116_4_ + 8));
    local_18 = strlen((char *)local_28);
    memset((char *)((int)local_28 + local_18),0x20,0x10 - local_18);
    _DAT_00047b4c = local_28[0];
    _DAT_00047b50 = local_28[1];
    _DAT_00047b54 = local_28[2];
    _DAT_00047b58 = local_28[3];
    sprintf(DAT_0002b040,"%d-%d\'C %d-%d\'C",(uint)sensor_info._1_1_,(uint)(byte)sensor_info,
            (uint)sensor_info._5_1_,(uint)sensor_info._4_1_);
    local_14 = local_14 + 1;
    write(cgpu._36_4_,lcd_buffer + 0x20,0x40);
  }
  return 0;
}

