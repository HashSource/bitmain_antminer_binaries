
int tls_process_server_done(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 4) == 0) {
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x10) << 0x1a < 0) &&
       (iVar1 = SRP_Calc_A_param(), iVar1 < 1)) {
      ossl_statem_fatal(param_1,0x50,0x170,0x169,"ssl/statem/statem_clnt.c",0xb37);
      iVar1 = 0;
    }
    else {
      iVar1 = tls_process_initial_server_flight(param_1);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    return iVar1;
  }
  ossl_statem_fatal(param_1,0x32,0x170,0x9f,"ssl/statem/statem_clnt.c",0xb30);
  return 0;
}

