
undefined4 curl_multi_setopt(int *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    uVar1 = 1;
  }
  else if (param_2 == 0x271b) {
    uVar1 = Curl_pipeline_set_site_blacklist(param_3,param_1 + 0x2b);
  }
  else {
    if (param_2 < 0x271c) {
      if (param_2 == 8) {
        param_1[0x28] = param_3;
        return 0;
      }
      if (param_2 < 9) {
        if (param_2 == 6) {
          param_1[0x25] = param_3;
          return 0;
        }
        if (6 < param_2) {
          param_1[0x26] = param_3;
          return 0;
        }
        if (param_2 == 3) {
          param_1[0x18] = param_3;
          return 0;
        }
      }
      else {
        if (param_2 == 0x2712) {
          param_1[8] = param_3;
          return 0;
        }
        if (param_2 == 0x2715) {
          param_1[0x2e] = param_3;
          return 0;
        }
        if (param_2 == 0xd) {
          param_1[0x27] = param_3;
          return 0;
        }
      }
    }
    else {
      if (param_2 == 0x4e24) {
        param_1[0x2d] = param_3;
        return 0;
      }
      if (param_2 < 0x4e25) {
        if (param_2 == 0x271f) {
          param_1[10] = param_3;
          return 0;
        }
        if (param_2 == 0x4e21) {
          param_1[7] = param_3;
          return 0;
        }
        if (param_2 == 0x271c) {
          uVar1 = Curl_pipeline_set_server_blacklist(param_3,param_1 + 0x2c);
          return uVar1;
        }
      }
      else {
        if (param_2 == 0x7539) {
          param_1[0x29] = param_3;
          return 0;
        }
        if (param_2 == 0x753a) {
          param_1[0x2a] = param_3;
          return 0;
        }
        if (param_2 == 0x4e2e) {
          param_1[9] = param_3;
          return 0;
        }
      }
    }
    uVar1 = 6;
  }
  return uVar1;
}

