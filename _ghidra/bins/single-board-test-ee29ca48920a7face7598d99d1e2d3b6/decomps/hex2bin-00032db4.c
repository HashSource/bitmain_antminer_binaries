
undefined4 hex2bin(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int local_24;
  byte *local_20;
  byte *local_1c;
  undefined4 local_c;
  
  local_c = 0;
  local_24 = param_3;
  local_20 = param_2;
  local_1c = param_1;
  while( true ) {
    if ((*local_20 == 0) || (local_24 == 0)) {
      if ((local_24 == 0) && (*local_20 == 0)) {
        local_c = 1;
      }
      return local_c;
    }
    if (local_20[1] == 0) {
      return 0;
    }
    pbVar2 = local_20 + 1;
    bVar1 = *local_20;
    local_20 = local_20 + 2;
    if (((int)*(uint *)(hex2bin_tbl + (uint)bVar1 * 4) < 0) ||
       (*(int *)(hex2bin_tbl + (uint)*pbVar2 * 4) < 0)) break;
    *local_1c = (byte)*(int *)(hex2bin_tbl + (uint)*pbVar2 * 4) |
                (byte)((*(uint *)(hex2bin_tbl + (uint)bVar1 * 4) & 0xff) << 4);
    local_24 = local_24 + -1;
    local_1c = local_1c + 1;
  }
  return 0;
}

