
void formboundary(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Curl_rand();
  uVar2 = Curl_rand(param_1);
  curl_maprintf("------------------------%08x%08x",uVar1,uVar2,param_4);
  return;
}

