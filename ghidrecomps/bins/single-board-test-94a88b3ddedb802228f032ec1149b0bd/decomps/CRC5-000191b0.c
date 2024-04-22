
byte CRC5(byte *param_1,byte param_2)

{
  byte bVar1;
  bool bVar2;
  byte *local_24;
  undefined4 local_1c;
  undefined4 local_14;
  byte local_10;
  byte local_c;
  char local_b;
  byte local_a;
  byte local_9;
  
  local_14 = DAT_0012e434;
  local_10 = DAT_0012e438;
  local_a = 0x80;
  local_b = '\0';
  local_9 = 0;
  local_24 = param_1;
  while( true ) {
    bVar1 = local_14._3_1_;
    if (param_2 <= local_9) break;
    bVar2 = (local_a & *local_24) != 0;
    local_1c = CONCAT13(local_14._2_1_,
                        CONCAT12(bVar2 ^ local_10 ^ local_14._1_1_,
                                 CONCAT11((char)local_14,bVar2 ^ local_10)));
    local_a = local_a >> 1;
    local_b = local_b + '\x01';
    if (local_b == '\b') {
      local_a = 0x80;
      local_b = '\0';
      local_24 = local_24 + 1;
    }
    local_14 = local_1c;
    local_10 = bVar1;
    local_9 = local_9 + 1;
  }
  local_c = 0;
  if (local_10 != 0) {
    local_c = 0x10;
  }
  if (local_14._3_1_ != 0) {
    local_c = local_c | 8;
  }
  if (local_14._2_1_ != '\0') {
    local_c = local_c | 4;
  }
  if (local_14._1_1_ != 0) {
    local_c = local_c | 2;
  }
  if ((char)local_14 != '\0') {
    local_c = local_c | 1;
  }
  return local_c;
}

