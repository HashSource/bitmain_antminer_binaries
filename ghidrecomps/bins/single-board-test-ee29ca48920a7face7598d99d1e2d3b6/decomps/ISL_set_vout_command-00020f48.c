
undefined4
ISL_set_vout_command(undefined param_1,undefined param_2,undefined param_3,ushort param_4)

{
  byte local_14;
  byte local_13;
  
  local_14 = (byte)param_4;
  local_13 = (byte)(param_4 >> 8);
  printf("uint16 = 0x%04x[%u], cmd0=%02x cmd1=%02x\n",(uint)param_4,(uint)param_4,(uint)local_14,
         (uint)local_13);
  write_dc_dc(param_1,param_2,param_3,0x21,&local_14,2);
  return 0;
}

