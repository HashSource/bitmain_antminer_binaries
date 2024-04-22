
undefined4 Curl_connected_proxy(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x1ef) == '\0') {
    return 0;
  }
  if (param_2 == 0) {
    switch(*(undefined4 *)(param_1 + 0x138)) {
    case 4:
      uVar1 = Curl_SOCKS4(*(undefined4 *)(param_1 + 0x130),*(undefined4 *)(param_1 + 0x98),
                          *(undefined4 *)(param_1 + 0xb4),0,param_1,0);
      break;
    case 5:
    case 7:
      uVar1 = Curl_SOCKS5(*(undefined4 *)(param_1 + 0x130),*(undefined4 *)(param_1 + 0x134),
                          *(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0xb4),0,param_1)
      ;
      break;
    case 6:
      uVar1 = Curl_SOCKS4(*(undefined4 *)(param_1 + 0x130),*(undefined4 *)(param_1 + 0x98),
                          *(undefined4 *)(param_1 + 0xb4),0,param_1,1);
      break;
    default:
      goto switchD_0004575c_caseD_4;
    }
  }
  else {
switchD_0004575c_caseD_4:
    uVar1 = 0;
  }
  return uVar1;
}

