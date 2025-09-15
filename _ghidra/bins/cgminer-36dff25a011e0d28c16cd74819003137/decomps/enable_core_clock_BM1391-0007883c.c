
void enable_core_clock_BM1391(uint core_id,uchar mode,uchar chain)

{
  ushort uVar1;
  undefined2 uVar2;
  uchar chain_local;
  uchar mode_local;
  uint core_id_local;
  core_command_t core_cmd;
  
  memset(&core_cmd,0,4);
  core_cmd.v[1] = core_cmd.v[1] & 0xf0 | 4;
  core_cmd.v_32 = CONCAT22(core_cmd.v_32._2_2_,CONCAT11(core_cmd.v[1],0xaa)) & 0xffffbfff;
  uVar2 = (undefined2)core_cmd.v_32;
  uVar1 = core_cmd.v_32._2_2_ & 0xfe00 | (ushort)((core_id << 0x17) >> 0x17);
  core_cmd.v[3] = (uint8_t)(uVar1 >> 8);
  core_cmd.v_32 = CONCAT13(core_cmd.v[3],(int3)CONCAT22(uVar1,uVar2)) & 0x7fffffff | 0x8000;
  send_set_config_command((uint)chain,mode,'\0','<',core_cmd.v_32);
  return;
}

