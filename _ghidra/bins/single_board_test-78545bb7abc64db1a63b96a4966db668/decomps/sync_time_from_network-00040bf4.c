
/* WARNING: Unknown calling convention */

int32_t sync_time_from_network(void)

{
  int iVar1;
  int32_t iVar2;
  int ret;
  
  iVar1 = get_time_from_web("http://www.baidu.com");
  if (((((iVar1 == 0) || (iVar1 = get_time_from_web("http://www.taobao.com"), iVar1 == 0)) ||
       (iVar1 = get_time_from_web("http://www.tencent.com"), iVar1 == 0)) ||
      ((iVar1 = get_time_from_pool("ss.antpool.com",0xd05), iVar1 == 0 ||
       (iVar1 = get_time_from_pool("us.ss.btc.com",0x708), iVar1 == 0)))) ||
     ((iVar1 = get_time_from_pool("btc.ss.poolin.com",0x1bb), iVar1 == 0 ||
      ((iVar1 = get_time_from_pool("btc.f2pool.com",0x522), iVar1 == 0 ||
       (iVar1 = get_time_from_pool("eu.ss.btc.com",0x708), iVar1 == 0)))))) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

