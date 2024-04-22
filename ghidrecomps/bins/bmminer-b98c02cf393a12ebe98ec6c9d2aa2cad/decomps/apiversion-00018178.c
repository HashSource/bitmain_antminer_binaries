
void apiversion(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  message(param_1,0x16,0,0,param_4);
  if (param_4 != 0) {
    iVar1 = io_add(param_1,",\"VERSION\":[");
    uVar2 = api_add_data_full(0,"BMMiner",1,"2.0.0",0);
    uVar2 = api_add_data_full(uVar2,&DAT_00058288,2,&DAT_00058284,0);
    uVar2 = api_add_data_full(uVar2,"Miner",1,g_miner_version,0);
    uVar2 = api_add_data_full(uVar2,"CompileTime",1,g_miner_compiletime,0);
    uVar2 = api_add_data_full(uVar2,&DAT_000582a0,1,g_miner_type,0);
    print_data(param_1,uVar2,1,0);
    if (iVar1 != 0) {
      *(undefined *)(param_1 + 0xd) = 1;
    }
    return;
  }
  io_add(param_1,"VERSION,");
  uVar2 = api_add_data_full(0,"BMMiner",1,"2.0.0",0);
  uVar2 = api_add_data_full(uVar2,&DAT_00058288,2,&DAT_00058284,0);
  uVar2 = api_add_data_full(uVar2,"Miner",1,g_miner_version,0);
  uVar2 = api_add_data_full(uVar2,"CompileTime",1,g_miner_compiletime,0);
  uVar2 = api_add_data_full(uVar2,&DAT_000582a0,1,g_miner_type,0);
  print_data(param_1,uVar2,0,0);
  return;
}

