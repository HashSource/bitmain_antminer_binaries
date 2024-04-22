
void sha2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  
  local_f8 = 0x6a09e667;
  local_f4 = 0xbb67ae85;
  local_f0 = 0x3c6ef372;
  local_e4 = 0x9b05688c;
  local_100 = 0;
  local_fc = 0;
  local_ec = 0xa54ff53a;
  local_e8 = 0x510e527f;
  local_e0 = 0x1f83d9ab;
  local_dc = 0x5be0cd19;
  sha2_update(&local_100,param_1,param_2);
  sha2_finish(&local_100,param_3);
  return;
}

