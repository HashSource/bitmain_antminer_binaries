
void __bin2hex(char *param_1,int param_2,int param_3)

{
  char *local_14;
  int local_c;
  
  local_14 = param_1;
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    *local_14 = "0123456789abcdef/mnt/card/single-BM1385-ASIC-test"
                [*(byte *)(param_2 + local_c) >> 4];
    local_14[1] = "0123456789abcdef/mnt/card/single-BM1385-ASIC-test"
                  [*(byte *)(param_2 + local_c) & 0xf];
    local_14 = local_14 + 2;
  }
  *local_14 = '\0';
  return;
}

