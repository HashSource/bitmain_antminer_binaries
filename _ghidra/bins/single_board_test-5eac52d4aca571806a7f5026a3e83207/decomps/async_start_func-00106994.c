
void async_start_func(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = async_get_ctx();
  do {
    iVar3 = *(int *)(iVar1 + 4);
    uVar2 = (**(code **)(iVar3 + 4))(*(undefined4 *)(iVar3 + 8));
    *(undefined4 *)(iVar3 + 0x10) = 3;
    *(undefined4 *)(iVar3 + 0xc) = uVar2;
    ERR_put_error(0x33,0x68,0x66,"crypto/async/async.c",0xa2);
  } while( true );
}

